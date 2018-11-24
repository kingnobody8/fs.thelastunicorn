//The headers
#include "SDL.h"
#undef main
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>
#include <sstream>

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//what is the type of screen being shown
//show title screen
bool title_screen = false;
bool text_screen = false;
bool gameplay = true;
bool gameplay_text = false;
bool boss = false;
bool boss_text = false;
bool end = false;
bool credits = false;

//which battle if being fought
int battle = 0;

// which enemies are shown on screen
bool bad1 = true;
bool bad2 = true;
bool bad3 = true;

bool bad4 = true;
bool bad5 = true;
bool bad6 = true;

// the arrow location
int arx = 15;
int ary = 350;

//what arrow to show
bool right = true;
bool left = false;

//the characters locations
int char1x = 75, char1y = 85;
int char2x = 75, char2y = 165;
int char3x = 75, char3y = 245;

//the enemy locations



// the character health integers
int player1_health = 400;
int player1_total_health = 400;
int player1_magic = 20;
int player1_total_magic = 20;

int player2_health = 500;
int player2_total_health = 500;
int player2_magic = 50;
int player2_total_magic = 50;

int player3_health = 800;
int player3_total_health = 800;
int player3_magic = 30;
int player3_total_magic = 30;

//the enemy health integers
int enemy1_health;
int enemy2_health;
int enemy3_health;
int enemy4_health;
int enemy5_health;
int enemy6_health;

//make the character selection, the primary selection, sub selection, and target selection
int choose1 = 0;
int choose2 = 0;
int choose3 = 0;
int choose4 = 0;

//make an array for each character to hold their selections
int player1_array[3] = {0};
int player2_array[3] = {0};
int player3_array[3] = {0};

//check whether or not the sub selection can even be accessed
bool play1m = false;
bool play2m = false;
bool play3m = false;
bool play1i = false;
bool play2i = false;
bool play3i = false;
//check whether or not a part of the magic sub selection can be used
bool play1m1 = false;
bool play1m2 = false;
bool play2m1 = false;
bool play2m2 = false;
bool play3m1 = false;
bool play3m2 = false;
//check whether or not a part of the item sub selection can be used
bool play1i1 = false;
bool play1i2 = false;
bool play1i3 = false;
bool play2i1 = false;
bool play2i2 = false;
bool play2i3 = false;
bool play3i1 = false;
bool play3i2 = false;
bool play3i3 = false;

//The surfaces
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;
SDL_Surface *sky = NULL;
SDL_Surface *command_background = NULL;
SDL_Surface *character_background = NULL;
SDL_Surface *arrow_right = NULL;
SDL_Surface *arrow_left = NULL;
SDL_Surface *health_counter = NULL;
SDL_Surface *magic_counter = NULL;
SDL_Surface *attack_background = NULL;
SDL_Surface *magic_background = NULL;
SDL_Surface *item_background = NULL;
SDL_Surface *magic_sub_selection = NULL;
SDL_Surface *item_sub_selection = NULL;
SDL_Surface *character1 = NULL;
SDL_Surface *enemy1 = NULL;

//The text that will be displayed
//character 1 attributes
SDL_Surface *character1_name = NULL;
SDL_Surface *character1_health = NULL;
SDL_Surface *character1_total_health = NULL;
SDL_Surface *character1_magic = NULL;
SDL_Surface *character1_total_magic = NULL;
//character 2 attributes
SDL_Surface *character2_name = NULL;
SDL_Surface *character2_health = NULL;
SDL_Surface *character2_total_health = NULL;
SDL_Surface *character2_magic = NULL;
SDL_Surface *character2_total_magic = NULL;
//character 3 attributes
SDL_Surface *character3_name = NULL;
SDL_Surface *character3_health = NULL;
SDL_Surface *character3_total_health = NULL;
SDL_Surface *character3_magic = NULL;
SDL_Surface *character3_total_magic = NULL;
// option attributes
SDL_Surface *attack_text = NULL;
SDL_Surface *magic_text = NULL;
SDL_Surface *item_text = NULL;
//sub selection attributes
//knight magic selection
SDL_Surface *rage_text = NULL;
SDL_Surface *hitx2_text = NULL;
SDL_Surface *limit_text = NULL;
//dark mage magic selection
SDL_Surface *fire_text = NULL;
SDL_Surface *ice_text = NULL;
//ninja magic selection
SDL_Surface *protect_text = NULL;
SDL_Surface *taunt_text = NULL;
//item sub selection options
SDL_Surface *potion_text = NULL;
SDL_Surface *hi_potion_text = NULL;
SDL_Surface *ether_text = NULL;
SDL_Surface *hi_ether_text = NULL;
SDL_Surface *lazarus = NULL;

//warning messages
SDL_Surface *item_warning = NULL;
SDL_Surface *magic_warning = NULL;


SDL_Surface *cheese1 = NULL;
SDL_Surface *cheese2 = NULL;
SDL_Surface *cheese3 = NULL;
SDL_Surface *cheese4 = NULL;

//The event structure that will be used
SDL_Event event;

//The font that's going to be used
TTF_Font *font = NULL;
TTF_Font *font_small = NULL;

//The color of the font
SDL_Color textColor = { 0, 0, 0 };
SDL_Color alertColor = {197, 16, 26};



SDL_Surface *load_image( std::string filename )
{
	std::string prepath("assets/vol_4/");
	filename = prepath + filename;

    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );

        //If the image was optimized just fine
        if( optimizedImage != NULL )
        {
            //Map the color key
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 255, 0, 255 );

            //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }
    }

    //Return the optimized image
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Get the offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }
    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "THE LAST UNICORN", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{
    //Load the image
    background = load_image( "background.png" );
    command_background = load_image( "command_background.png" );
    character_background = load_image( "character_background.png" );
    arrow_right = load_image( "arrow_right.png" );
    arrow_left = load_image( "arrow_left.png" );
    health_counter = load_image( "health_counter.png" );
    magic_counter = load_image( "magic_counter.png" );
    attack_background = load_image( "attack_background.png" );
    magic_background = load_image( "magic_background.png" );
    item_background = load_image( "item_background.png" );
    magic_sub_selection = load_image( "magic_sub_selection.png" );
    item_sub_selection = load_image( "item_sub_selection.png" );
    character1 = load_image( "mario.png" );
    enemy1 = load_image( "flower.png" );
    sky = load_image( "sky.png" );

    //Open the font
    font = TTF_OpenFont( "assets/vol_4/tnr.ttf", 22 );
    font_small = TTF_OpenFont( "assets/vol_4/tnr.ttf", 15 );
    //If there was an error in loading the font
    if( font == NULL )
    {
        return false;
    }
    if( font_small == NULL )
    {
        return false;
    }
    //If there was an error in loading the image
    if( background == NULL )
    {
        return false;
    }
    if( command_background == NULL )
    {
        return false;
    }
    if( character_background == NULL )
    {
        return false;
    }
    if( arrow_right == NULL )
    {
        return false;
    }
    if( arrow_left == NULL )
    {
        return false;
    }
    if( health_counter == NULL )
    {
        return false;
    }
    if( magic_counter == NULL )
    {
        return false;
    }
    if( attack_background == NULL )
    {
        return false;
    }
    if( magic_background == NULL )
    {
        return false;
    }
    if( item_background == NULL )
    {
        return false;
    }
    if( magic_sub_selection == NULL )
    {
        return false;
    }
    if( item_sub_selection == NULL )
    {
        return false;
    }
    if ( character1 == NULL )
    {
        return false;
    }
     if ( enemy1 == NULL )
    {
        return false;
    }
     if ( sky == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the surface
    SDL_FreeSurface( background );
    SDL_FreeSurface( command_background );
    SDL_FreeSurface( character_background );
    SDL_FreeSurface( arrow_right );
    SDL_FreeSurface( arrow_left );
    SDL_FreeSurface( health_counter );
    SDL_FreeSurface( magic_counter );
    SDL_FreeSurface( attack_background );
    SDL_FreeSurface( magic_background );
    SDL_FreeSurface( item_background );
    SDL_FreeSurface( magic_sub_selection );
    SDL_FreeSurface( item_sub_selection );
    SDL_FreeSurface( character1 );
    SDL_FreeSurface( enemy1 );
    SDL_FreeSurface( sky );

    //Close the font that was used
    TTF_CloseFont( font );

    //Quit SDL_ttf
    TTF_Quit();

    //Quit SDL
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Make sure the program waits for a quit
    bool quit = false;

    bool running = true;

    //make factors to make the correct selection boxes appear when appropriate
    bool attack_box = false;
    bool magic_box = false;
    bool item_box = false;
    bool magic_sub_box = false;
    bool item_sub_box = false;

    //have the choose selection perform actions in the correct order
    int order1 = 0;
    int order2 = 0;
    int order3 = 0;

    int player1_selection;
    int player2_selection;
    int player3_selection;

    //variables for use during gameplay
    int point;
    int enemy_random;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //Load the files
    if( load_files() == false )
    {
        return 1;
    }

while(quit == false)
{
    while(title_screen == true)
    {break;}
    while (text_screen == true)
    {break;}
    while(gameplay == true)
    {
        //While there's an event to handle
        while( SDL_PollEvent( &event ) )
        {
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                switch ( event.key.keysym.sym )
                {
                    case SDLK_UP:
                    {
                        //this is for selecting characters, primaries, and sub
                        if( ary != 350 && ary > 350)
                        {
                            if(arx != 15 && ary != 350)
                            {
                                ary = ary - 40; break;
                            }
                            else if(order1 == 0)
                            {
                                ary = ary - 40; break;
                            }
                            else if(arx == 15 && order1 == 1 && order2 == 0)
                            {
                                if(ary == 390)
                                {ary = 430; break;}
                                else if(ary == 430)
                                {ary = 390; break;}
                            }
                            else if(arx == 15 && order1 == 2 && order2 == 0)
                            {
                                ary = 350; break;
                            }
                            else if (arx == 15 && order1 == 3 && order2 == 0)
                            {
                                ary = 350; break;
                            }
                            else if(arx == 15 && order1 != 0 && order2 != 0)
                            {
                                break;
                            }
                        }
                        else if( ary == 350)
                        {
                            if(order1 == 0)
                            {
                                ary = 430; break;
                            }
                            else if(arx != 15)
                            {
                                ary = 430; break;
                            }
                            else if(arx == 15 && order1 == 2 && order2 == 0)
                            {
                                if(ary == 350)
                                {ary = 430; break;}
                                else
                                {break;}
                            }
                            else if(arx == 15 && order1 == 3 && order2 == 0)
                            {
                                if(ary == 350)
                                {ary = 390; break;}
                                else
                                {ary = 430; break;}
                            }
                            else if (arx == 15 && order1 != 0 && order2 != 0)
                            {
                                break;
                            }
                        }

                        // this is for selecting who will receive the action
                        else if(ary < 350 && arx != 140)
                        {
                            //for characters
                            if(arx == 15)
                            {ary = ary - 80; break;}
                            //for first row bad guys if they are all present
                            if(arx == 435 && bad1 == true && bad2 == true && bad3 == true)
                            {
                                if(ary == 110)
                                {ary = 270; break;}
                                else
                                {ary = ary - 80; break;}
                            }
                            //for second row bad guys if they are all present
                            if(arx == 540 && bad4 == true && bad5 == true && bad6 == true)
                            {
                                if(ary == 110)
                                {ary = 270; break;}
                                else
                                {ary = ary - 80; break;}
                            }
                           //for first row depending on which ones are present
                            else if(arx == 435)
                            {
                                if(ary == 110)
                                {
                                    if(bad3 == false)
                                    {
                                        if(bad2 == false)
                                        {break;}
                                        else
                                        {ary = 190; break;}
                                    }
                                    else
                                    {ary = 270; break;}
                                }
                                if(ary == 190)
                                {
                                    if(bad1 == false)
                                    {
                                        if(bad3 == false)
                                        {break;}
                                        else
                                        {ary = 270; break;}
                                    }
                                    else
                                    {ary = 110; break;}
                                }
                                if(ary == 270)
                                {
                                    if(bad2 == false)
                                    {
                                        if(bad1 == false)
                                        {break;}
                                        else
                                        {ary = 110; break;}
                                    }
                                    else
                                    {ary = 190; break;}
                                }

                            }
                            //for the second row depending on which ones are present
                            else if(arx == 540)
                            {
                                if(ary == 110)
                                {
                                    if(bad6 == false)
                                    {
                                        if(bad5 == false)
                                        {break;}
                                        else
                                        {ary = 190; break;}
                                    }
                                    else
                                    {ary = 270; break;}
                                }
                                if(ary == 190)
                                {
                                    if(bad4 == false)
                                    {
                                        if(bad6 == false)
                                        {break;}
                                        else
                                        {ary = 270; break;}
                                    }
                                    else
                                    {ary = 110; break;}
                                }
                                if(ary == 270)
                                {
                                    if(bad5 == false)
                                    {
                                        if(bad4 == false)
                                        {break;}
                                        else
                                        {ary = 110; break;}
                                    }
                                    else
                                    {ary = 190; break;}
                                }

                            }
                        }
                        else if(arx == 140)
                        {
                            if(ary == 110)
                            {ary = 270;break;}
                            else
                            {ary = ary - 80; break;}
                        }
                        else
                        {break;}
                    }
                    case SDLK_DOWN:
                    {
                        //this is for selecting a character, primary, or sub
                        if( ary >= 350 && ary != 430)
                        {
                            if(arx != 15 && ary != 430)
                            {
                                ary = ary + 40; break;
                            }
                            else if(order1 == 0)
                            {
                                ary = ary + 40; break;
                            }
                            else if(arx == 15 && order1 == 1 && order2 == 0)
                            {

                                ary = 430; break;
                            }
                            else if(arx == 15 && order1 == 2 && order2 == 0)
                            {
                                ary = 430; break;
                            }
                            else if (arx == 15 && order1 == 3 && order2 == 0)
                            {
                                if(ary == 390)
                                {ary = 350; break;}
                                else if(ary == 350)
                                { ary = 390; break;}
                            }
                            else if(arx == 15 && order1 != 0 && order2 != 0)
                            {
                                break;
                            }
                        }
                        else if( ary == 430)
                        {
                            if(order1 == 0)
                            {
                                ary = 350; break;
                            }
                            else if(arx != 15)
                            {
                                ary = 350; break;
                            }
                            else if(arx == 15 && order1 ==1 && order2 == 0)
                            {
                                ary = 390; break;
                            }
                            else if(arx == 15 && order1 == 2 && order2 == 0)
                            {
                               ary = 350; break;
                            }
                            else if (arx == 15 && order1 != 0 && order2 != 0)
                            {
                                break;
                            }
                        }
                        //this is for selecting who will receive the action
                        else if(ary < 350 && arx != 140)
                        {
                            //for characters
                            if(arx == 15)
                            {ary = ary + 80; break;}
                            //for first row bad guys if they are all present
                            if(arx == 435 && bad1 == true && bad2 == true && bad3 == true)
                            {
                                if(ary == 270)
                                {ary = 110; break;}
                                else
                                {ary = ary + 80; break;}
                            }
                            //for second row bad guys if they are all present
                            if(arx == 540 && bad4 == true && bad5 == true && bad6 == true)
                            {
                                if(ary == 270)
                                {ary = 110; break;}
                                else
                                {ary = ary + 80; break;}
                            }
                           //for first row depending on which ones are present
                            else if(arx == 435)
                            {
                                if(ary == 110)
                                {
                                    if(bad2 == false)
                                    {
                                        if(bad3 == false)
                                        {break;}
                                        else
                                        {ary = 270; break;}
                                    }
                                    else
                                    {ary = 190; break;}
                                }
                                if(ary == 190)
                                {
                                    if(bad3 == false)
                                    {
                                        if(bad1 == false)
                                        {break;}
                                        else
                                        {ary = 110; break;}
                                    }
                                    else
                                    {ary = 270; break;}
                                }
                                if(ary == 270)
                                {
                                    if(bad1 == false)
                                    {
                                        if(bad2 == false)
                                        {break;}
                                        else
                                        {ary = 190; break;}
                                    }
                                    else
                                    {ary = 110; break;}
                                }
                            }
                            //for the second row depending on which ones are present
                            else if(arx == 540)
                            {
                                if(ary == 110)
                                {
                                    if(bad5 == false)
                                    {
                                        if(bad6 == false)
                                        {break;}
                                        else
                                        {ary = 270; break;}
                                    }
                                    else
                                    {ary = 190; break;}
                                }
                                if(ary == 190)
                                {
                                    if(bad6 == false)
                                    {
                                        if(bad4 == false)
                                        {break;}
                                        else
                                        {ary = 110; break;}
                                    }
                                    else
                                    {ary = 270; break;}
                                }
                                if(ary == 270)
                                {
                                    if(bad4 == false)
                                    {
                                        if(bad5 == false)
                                        {break;}
                                        else
                                        {ary = 190; break;}
                                    }
                                    else
                                    {ary = 110; break;}
                                }
                            }
                        }
                       else if(arx == 140)
                        {
                            if(ary == 270)
                            {ary = 110;break;}
                            else
                            {ary = ary + 80; break;}
                        }
                        else
                        {break;}
                    }
                    case SDLK_RIGHT:
                    {
                        //moving from first row to second row
                        if(ary < 350 && arx == 435)
                        {
                                if(ary == 110)
                                {
                                    if(bad4 == true)
                                        {arx = 540; ary = 110; break;}
                                    else if(bad5 == true)
                                        {arx = 540; ary = 190; break;}
                                    else if(bad6 == true)
                                        {arx = 540; ary = 270; break;}
                                    else
                                        {break;}
                                }
                                if(ary == 190)
                                {
                                    if(bad5 == true)
                                        {arx = 540; ary = 190; break;}
                                    else if(bad4 == true)
                                        {arx = 540; ary = 110; break;}
                                    else if(bad6 == true)
                                        {arx = 540; ary = 270; break;}
                                    else
                                        {break;}
                                }
                                if(ary == 270)
                                {
                                    if(bad6 == true)
                                        {arx = 540; ary = 270; break;}
                                    else if(bad5 == true)
                                        {arx = 540; ary = 190; break;}
                                    else if(bad4 == true)
                                        {arx = 540; ary = 110; break;}
                                    else
                                        {break;}
                                }
                            }
                       //moving from the characters to the first or second row
                        else if(ary < 350 && arx == 140)
                        {
                                //if the first row is all there
                                if(bad1 == true && bad2 == true && bad3 == true)
                                {arx = 435; right = true; left = false; break;}
                                //if the any are missing from the front row
                                else
                                {
                                    if(ary == 110)
                                    {
                                        if(bad1 == false)
                                        {
                                            if(bad2 == false)
                                            {
                                                if(bad3 == false)
                                                {
                                                    if(bad4 == false)
                                                    {
                                                        if(bad5 == false)
                                                        {
                                                            arx = 540; ary = 270; right = true; left = false; break;
                                                        }
                                                        else
                                                        {arx = 540; ary = 190; right = true; left = false; break;}
                                                    }
                                                    else
                                                    { arx = 540; ary = 110; right = true; left = false; break;}
                                                }
                                                else
                                                {arx = 435; ary = 270; right = true; left = false; break;}
                                            }
                                            else
                                            {arx = 435; ary = 190; right = true; left = false; break;}
                                        }
                                        else
                                        {arx = 435; ary = 110; right = true; left = false; break;}
                                    }
                                    if(ary == 190)
                                    {
                                            if(bad2 == false)
                                            {
                                                if(bad1 == false)
                                                {
                                                    if(bad3 == false)
                                                    {
                                                        if(bad5 == false)
                                                        {
                                                            if(bad4 == false)
                                                            {
                                                                arx = 540; ary = 270; right = true; left = false; break;
                                                            }
                                                            else
                                                            {
                                                                arx = 540; ary = 110; right = true; left = false; break;
                                                            }
                                                        }
                                                        else
                                                        { arx = 540; ary = 190; right = true; left = false; break;}
                                                    }
                                                    else
                                                    {arx = 435; ary = 270; right = true; left = false; break;}
                                                }
                                                else
                                                {arx = 435; ary = 110; right = true; left = false; break;}
                                            }
                                            else
                                            {arx = 435; ary = 190; right = true; left = false; break;}


                                        }
                                    if(ary == 270)
                                    {
                                            if(bad3 == false)
                                            {
                                                if(bad2 == false)
                                                {
                                                    if(bad1 == false)
                                                    {
                                                        if(bad6 == false)
                                                        {
                                                            if(bad5 == false)
                                                            {
                                                                arx = 540; ary = 110; right = true; left = false; break;
                                                            }
                                                            else
                                                            {
                                                                arx = 540; ary = 190; right = true; left = false; break;
                                                            }
                                                        }
                                                        else
                                                        { arx = 540; ary = 270; right = true; left = false; break;}
                                                    }
                                                    else
                                                    {arx = 435; ary = 110; right = true; left = false; break;}
                                                }
                                                else
                                                {arx = 435; ary = 190; right = true; left = false; break;}
                                            }
                                            else
                                            {arx = 435; ary = 270; right = true; left = false; break;}

                                        }
                                }
                            }
                        else
                        {break;}
                    }
                    case SDLK_LEFT:
                    {
                            if(ary < 350 && arx == 540)
                            {
                                if(ary == 110)
                                {
                                    if(bad1 == true)
                                        {arx = 435; ary = 110; break;}
                                    else if(bad2 == true)
                                        {arx = 435; ary = 190; break;}
                                    else if(bad3 == true)
                                        {arx = 435; ary = 270; break;}
                                    else
                                        {arx = 140; right = false; left = true; break;}
                                }
                                if(ary == 190)
                                {
                                    if(bad2 == true)
                                        {arx = 435; ary = 190; break;}
                                    else if(bad1 == true)
                                        {arx = 435; ary = 110; break;}
                                    else if(bad3 == true)
                                        {arx = 435; ary = 270; break;}
                                    else
                                        {arx = 140; right = false; left = true; break;}
                                }
                                if(ary == 270)
                                {
                                    if(bad3 == true)
                                        {arx = 435; ary = 270; break;}
                                    else if(bad2 == true)
                                        {arx = 435; ary = 190; break;}
                                    else if(bad1 == true)
                                        {arx = 435; ary = 110; break;}
                                    else
                                        {arx = 140; right = false; left = true; break;}
                                }
                            }
                            else if( ary < 350 && arx == 435)
                            { arx = 140; right = false; left = true; break;}
                            else
                            {break;}
                    }
                    case SDLK_a:
                    {
                        // check first for target selection
                        if( ary < 350 )
                        {
                                if( arx == 140 && ary == 110)
                                    {choose4 = 1;}
                                else if( arx == 140 && ary == 190)
                                    {choose4 = 2;}
                                else if( arx == 140 && ary == 270)
                                    {choose4 = 3;}
                                else if( arx == 435 && ary == 110)
                                    {choose4 = 4;}
                                else if( arx == 435 && ary == 190)
                                    {choose4 = 5;}
                                else if( arx == 435 && ary == 270)
                                    {choose4 = 6;}
                                else if( arx == 540 && ary == 110)
                                    {choose4 = 7;}
                                else if( arx == 540 && ary == 190)
                                    {choose4 = 8;}
                                else if( arx == 540 && ary == 270)
                                    {choose4 = 9;}

                                if (choose1 == 1)
                                {
                                    player1_array[0] = choose2;
                                    player1_array[1] = choose3;
                                    player1_array[2] = choose4;
                                }
                                else if (choose1 == 2)
                                {
                                    player2_array[0] = choose2;
                                    player2_array[1] = choose3;
                                    player2_array[2] = choose4;
                                }
                                else if (choose1 == 3)
                                {
                                    player3_array[0] = choose2;
                                    player3_array[1] = choose3;
                                    player3_array[2] = choose4;
                                }
                                else
                                {break;}


                                if(order1==0)
                                {
                                    order1 = choose1;
                                    if(order1 == 1)
                                        {arx = 15; ary = 390;}
                                    else
                                        {arx = 15; ary = 350;}
                                }
                                else if(order2==0)
                                {
                                    order2 = choose1;
                                    if(order1 == 1 && order2 == 2)
                                        {arx = 15; ary = 430;}
                                    else if(order1 == 1 && order2 == 3)
                                        {arx = 15; ary = 390;}
                                    else if(order1 == 2 && order2 == 1)
                                        {arx = 15; ary = 430;}
                                    else if(order1 == 3 && order2 == 1)
                                        {arx = 15; ary = 390;}
                                    else
                                        {arx = 15; ary = 350;}
                                }
                                else if(order3==0)
                                {
                                    order3 = choose1;
    // -------------------------------------------------------------------------------XXXXIJDLFIJASODFIJOSIJOJS------------------------------------
    //              this is where the control switches from the player and then the program displays the attack animations
    //                 then shows the enemy animations, then sends control back to player.
                                }
                                else
                                {break;}

                                right = true; left = false;
                                choose1 = 0;
                                choose2 = 0;
                                choose3 = 0;
                                choose4 = 0;
                        }

                       //check second for sub selection
                        else if(arx == 445)
                        {
                            if( ary == 350 )
                            {
                                    choose3 = 1;
                                            if(bad1 == false)
                                            {
                                                if(bad2 == false)
                                                {
                                                    if(bad3 == false)
                                                    {
                                                        if(bad4 == false)
                                                        {
                                                            if(bad5 == false)
                                                            {
                                                                arx = 540; ary = 270; right = true; left = false; break;
                                                            }
                                                            else
                                                            {
                                                                arx = 540; ary = 190; right = true; left = false; break;
                                                            }
                                                        }
                                                        else
                                                        { arx = 540; ary = 110; right = true; left = false; break;}
                                                    }
                                                    else
                                                    {arx = 435; ary = 270; right = true; left = false; break;}
                                                }
                                                else
                                                {arx = 435; ary = 190; right = true; left = false; break;}
                                            }
                                            else
                                            {arx = 435; ary = 110; right = true; left = false; break;}
                            }
                            else if( ary == 390 )
                                {
                                    choose3 = 2;

                                            if(bad1 == false)
                                            {
                                                if(bad2 == false)
                                                {
                                                    if(bad3 == false)
                                                    {
                                                        if(bad4 == false)
                                                        {
                                                            if(bad5 == false)
                                                            {
                                                                arx = 540; ary = 270; right = true; left = false; break;
                                                            }
                                                            else
                                                            {
                                                                arx = 540; ary = 190; right = true; left = false; break;
                                                            }
                                                        }
                                                        else
                                                        { arx = 540; ary = 110; right = true; left = false; break;}
                                                    }
                                                    else
                                                    {arx = 435; ary = 270; right = true; left = false; break;}
                                                }
                                                else
                                                {arx = 435; ary = 190; right = true; left = false; break;}
                                            }
                                            else
                                            {arx = 435; ary = 110; right = true; left = false; break;}
                            }
                            else if( ary == 430 )
                                {
                                    choose3 = 3;

                                            if(bad1 == false)
                                            {
                                                if(bad2 == false)
                                                {
                                                    if(bad3 == false)
                                                    {
                                                        if(bad4 == false)
                                                        {
                                                            if(bad5 == false)
                                                            {
                                                                arx = 540; ary = 270; right = true; left = false; break;
                                                            }
                                                            else
                                                            {
                                                                arx = 540; ary = 190; right = true; left = false; break;
                                                            }
                                                        }
                                                        else
                                                        { arx = 540; ary = 110; right = true; left = false; break;}
                                                    }
                                                    else
                                                    {arx = 435; ary = 270; right = true; left = false; break;}
                                                }
                                                else
                                                {arx = 435; ary = 190; right = true; left = false; break;}
                                            }
                                            else
                                            {arx = 435; ary = 110; right = true; left = false; break;}
                                }
                            else
                                {break;}
                        }

                        // check third for primary selection
                        else if(arx == 280)
                        {
                            //this one is the attack one, it is special because it has no sub selection
                            if( ary == 350 )
                                {
                                    choose2 = 1;
                                    if(bad1 == false)
                                            {
                                                if(bad2 == false)
                                                {
                                                    if(bad3 == false)
                                                    {
                                                        if(bad4 == false)
                                                        {
                                                            if(bad5 == false)
                                                            {
                                                                arx = 540; ary = 270; right = true; left = false; break;
                                                            }
                                                            else
                                                            {
                                                                arx = 540; ary = 190; right = true; left = false; break;
                                                            }
                                                        }
                                                        else
                                                        { arx = 540; ary = 110; right = true; left = false; break;}
                                                    }
                                                    else
                                                    {arx = 435; ary = 270; right = true; left = false; break;}
                                                }
                                                else
                                                {arx = 435; ary = 190; right = true; left = false; break;}
                                            }
                                            else
                                            {arx = 435; ary = 110; right = true; left = false; break;}
                                }
                            // now back to the other options
                            else if( ary == 390 )
                                {choose2 = 2; arx = 445; ary = 350; break;}
                            else if( ary == 430 )
                                {
                                    if(choose1 == 1)
                                    {
                                        if(play1i == false)
                                        {apply_surface(445, 300, item_warning, screen ); break;}
                                        else
                                        {choose2 = 3; arx = 445; ary = 350; break;}
                                    }
                                    else if(choose1 == 2)
                                    {
                                        if(play2i == false)
                                        {apply_surface(445, 390, item_warning, screen ); break;}
                                        else
                                        {choose2 = 3; arx = 445; ary = 350; break;}
                                    }
                                    else if(choose1 == 3)
                                    {
                                        if(play3i == false)
                                        {apply_surface(445, 390, item_warning, screen ); break;}
                                        else
                                        {choose2 = 3; arx = 445; ary = 350; break;}
                                    }
                                }
                            else
                                {break;}
                        }

                       // check last for character selection
                        else if(arx == 15)
                        {
                            if( ary == 350 )
                                { choose1 = 1; ary = 350; arx = 280; break;}
                            if( ary == 390 )
                                { choose1 = 2; ary = 350; arx = 280; break;}
                            if( ary == 430 )
                                {choose1 = 3; ary = 350; arx = 280; break;}
                            else
                                {break;}
                        }

                        else
                        {break;}

                    }
                    case SDLK_s:
                    {
                            //go back and undo sub selection
                            if(ary < 350 && choose3 == 0)
                                {arx = 280; ary = 350; choose2 = 0; right = true; left = false; break;}
                            if(ary < 350 && choose3 == 1)
                                {arx = 445; ary = 350; choose3 = 0; right = true; left = false; break;}
                            if(ary < 350 && choose3 == 2)
                                {arx = 445; ary = 390; choose3 = 0; right = true; left = false; break;}
                            if(ary < 350 && choose3 == 3)
                                {arx = 445; ary = 430; choose3 = 0; right = true; left = false; break;}
                            //go back and undo primary selection
                            if( arx == 445 && choose2 == 1)
                                { arx = 280; ary = 350; choose2 = 0; break;}
                            if( arx == 445 && choose2 == 2)
                                { arx = 280; ary = 390; choose2 = 0; break;}
                            if( arx == 445 && choose2 == 3)
                                { arx = 280; ary = 430; choose2 = 0; break;}
                            //go back and undo character selection
                            if( arx == 280 && choose1 == 1)
                                { arx = 15; ary = 350; choose1 = 0; break;}
                            if( arx == 280 && choose1 == 2)
                                { arx = 15; ary = 390; choose1 = 0; break;}
                            if( arx == 280 && choose1 == 3)
                                { arx = 15; ary = 430; choose1 = 0; break;}
                            else{break;}
                    }
                    case SDLK_d:
                    {
                        break;
                    }
                    default:
                    {break;}
                }
            }
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                gameplay = false;
            }
        }

    //Apply the surface to the screen
    apply_surface(0, 0, sky, screen );
    apply_surface( 0, 0, background, screen );
    apply_surface( 0, 330, command_background, screen );
    apply_surface( 50, 345, character_background, screen);
    apply_surface( 50, 385, character_background, screen);
    apply_surface( 50, 425, character_background, screen);
    apply_surface( 170, 345, health_counter, screen);
    apply_surface( 220, 345, magic_counter, screen);

    //show or don't show the primary and sub selections
    if ( choose1 != 0)
    {
        //render background
        apply_surface( 320, 345, attack_background, screen);
        apply_surface( 320, 385, magic_background, screen);
        apply_surface( 320, 425, item_background, screen);
        //apply primary selection text
        apply_surface( 325, 352, attack_text, screen );
        apply_surface( 325, 392, magic_text, screen );
        apply_surface( 325, 432, item_text, screen );

        if (choose2 == 2 )
        {
            apply_surface( 500, 345, magic_sub_selection, screen);
            apply_surface( 500, 385, magic_sub_selection, screen);
            apply_surface( 500, 425, magic_sub_selection, screen);
            //now set the text for which character is selected
            if( choose1 == 1 && choose2 == 2)
            {
                apply_surface( 505, 350, rage_text, screen );
                apply_surface( 505, 390, hitx2_text, screen );
                apply_surface( 505, 430, limit_text, screen );
            }
            if ( choose1 == 2 && choose2 == 2)
            {
                apply_surface( 505, 350, fire_text, screen );
                apply_surface( 505, 390, ice_text, screen );
                apply_surface( 505, 430, limit_text, screen );
            }
            if ( choose1 == 3 && choose2 == 2)
            {
                apply_surface( 505, 350, protect_text, screen );
                apply_surface( 505, 390, taunt_text, screen );
                apply_surface( 505, 430, limit_text, screen );
            }


        }
        if (choose2 == 3)
        {
            apply_surface( 500, 345, item_sub_selection, screen);
            apply_surface( 500, 385, item_sub_selection, screen);
            apply_surface( 500, 425, item_sub_selection, screen);

        }
    }

    // show the characters
    apply_surface( char1x, char1y, character1, screen);
    apply_surface( char2x, char2y, character1, screen);
    apply_surface( char3x, char3y, character1, screen);
    // place the characters depending on which one is selected
    if ( ary == 350 && arx ==  15)
    {
        char1x = 65;
        char2x = 15;
        char3x = 15;
    }
    if ( ary == 390 && arx ==  15)
    {
        char1x = 15;
        char2x = 65;
        char3x = 15;
    }
    if ( ary == 430 && arx ==  15)
    {
        char1x = 15;
        char2x = 15;
        char3x = 65;
    }


    // show the enemies
    if(bad1 == true)
    {apply_surface( 470, 85, enemy1, screen);}
    if(bad2 == true)
    {apply_surface( 470, 165, enemy1, screen);}
    if(bad3 == true)
    {apply_surface( 470, 245, enemy1, screen);}
    if(bad4 == true)
    {apply_surface( 550, 85, enemy1, screen);}
    if(bad5 == true)
    {apply_surface( 550, 165, enemy1, screen);}
    if(bad6 == true)
    {apply_surface( 550, 245, enemy1, screen);}

 // show the arrow
if ( right == true )
    {apply_surface( arx, ary, arrow_right, screen);}
if ( left == true)
    {apply_surface(arx, ary, arrow_left, screen);}

    //see the choices
    if( running == true )
    {
        //The timer's time as a string
        std::stringstream ch1;
        std::stringstream ch2;
        std::stringstream ch3;
        std::stringstream ch4;

        //Convert the timer's time to a string
        ch1 << "player1 - 0 is " << order1;
        ch2 << "player1 - 1 is " << order2;
        ch3 << "ARX is " << arx;
        ch4 << "ARY is " << ary;

        //Render the time surface
        cheese1 = TTF_RenderText_Solid( font, ch1.str().c_str(), textColor );
        cheese2 = TTF_RenderText_Solid( font, ch2.str().c_str(), textColor );
        cheese3 = TTF_RenderText_Solid( font, ch3.str().c_str(), textColor );
        cheese4 = TTF_RenderText_Solid( font, ch4.str().c_str(), textColor );

        //Apply the time surface
        apply_surface( 250, 150,cheese1, screen );
        apply_surface( 250, 170, cheese2, screen );
        apply_surface( 250, 190, cheese3, screen );
        apply_surface( 250, 210, cheese4, screen );

        //Free the time surface
        SDL_FreeSurface( cheese1 );
        SDL_FreeSurface( cheese2 );
        SDL_FreeSurface( cheese3 );
        SDL_FreeSurface( cheese4 );
    }
//----------------------------------------------------------------------------
        //the players health and magic has a string
        std::stringstream play1h;
        std::stringstream play1th;
        std::stringstream play1m;
        std::stringstream play1tm;

        std::stringstream play2h;
        std::stringstream play2th;
        std::stringstream play2m;
        std::stringstream play2tm;

        std::stringstream play3h;
        std::stringstream play3th;
        std::stringstream play3m;
        std::stringstream play3tm;

        //convert the player attributes to string
        play1h << player1_health;
        play1th << player1_total_health;
        play1m << player1_magic;
        play1tm << player1_total_magic;
        play2h << player2_health;
        play2th << player2_total_health;
        play2m << player2_magic;
        play2tm << player2_total_magic;
        play3h << player3_health;
        play3th << player3_total_health;
        play3m << player3_magic;
        play3tm << player3_total_magic;

    //Render the text

    //character1 attributes text
    character1_health = TTF_RenderText_Solid( font_small, play1h.str().c_str(), textColor );
    character1_total_health = TTF_RenderText_Solid( font_small, play1th.str().c_str(), textColor );
    character1_magic = TTF_RenderText_Solid( font_small, play1m.str().c_str(), textColor );
    character1_total_magic = TTF_RenderText_Solid( font_small, play1tm.str().c_str(), textColor );
    //character2 attributes text
    character2_health = TTF_RenderText_Solid( font_small, play2h.str().c_str(), textColor );
    character2_total_health = TTF_RenderText_Solid( font_small, play2th.str().c_str(), textColor );
    character2_magic = TTF_RenderText_Solid( font_small, play2m.str().c_str(), textColor );
    character2_total_magic = TTF_RenderText_Solid( font_small, play2tm.str().c_str(), textColor );
    //character3 attributes text
    character3_health = TTF_RenderText_Solid( font_small, play3h.str().c_str(), textColor );
    character3_total_health = TTF_RenderText_Solid( font_small, play3th.str().c_str(), textColor );
    character3_magic = TTF_RenderText_Solid( font_small, play3m.str().c_str(), textColor );
    character3_total_magic = TTF_RenderText_Solid( font_small, play3tm.str().c_str(), textColor );
    //primary selection text
    attack_text = TTF_RenderText_Solid( font, "ATTACK", textColor );
    magic_text = TTF_RenderText_Solid( font, "MAGIC", textColor );
    item_text = TTF_RenderText_Solid( font, "ITEM", textColor );

    //character names text
    character1_name = TTF_RenderText_Solid( font, "BECKETT", textColor );
    character2_name = TTF_RenderText_Solid( font, "SAMSON", textColor );
    character3_name = TTF_RenderText_Solid( font, "CHEERIO", textColor );
    //character 1 magic text
    rage_text = TTF_RenderText_Solid( font, "RAGE", textColor );
    hitx2_text = TTF_RenderText_Solid( font, "POWER X2", textColor );
    limit_text = TTF_RenderText_Solid( font, "LIMIT", textColor );
    //character2 magic text
    fire_text = TTF_RenderText_Solid( font, "BURN", textColor );
    ice_text = TTF_RenderText_Solid( font, "FREEZE", textColor );
    //character3 magic text
    protect_text = TTF_RenderText_Solid( font, "GUARD", textColor );
    taunt_text = TTF_RenderText_Solid( font, "TAUNT", textColor );

    //the names of items
    hi_potion_text = TTF_RenderText_Solid( font, "HI-POTION", textColor );
    potion_text = TTF_RenderText_Solid( font, "POTION", textColor );
    hi_ether_text = TTF_RenderText_Solid( font, "HI-ETHER", textColor );
    ether_text = TTF_RenderText_Solid( font, "ETHER", textColor );
    lazarus = TTF_RenderText_Solid( font, "LAZARUS", textColor );

    //the warning messages
    item_warning = TTF_RenderText_Solid( font, "NO ITEMS", textColor );
    magic_warning = TTF_RenderText_Solid( font, "NO MAGIC POINTS", textColor );

    //apply character 1 text
    apply_surface( 183, 347, character1_health, screen );
    apply_surface( 183, 367, character1_total_health, screen );
    apply_surface( 237, 347, character1_magic, screen );
    apply_surface( 237, 367, character1_total_magic, screen );
    apply_surface( 60, 355, character1_name, screen );
    //apply character 2 text
    apply_surface( 183, 387, character2_health, screen );
    apply_surface( 183, 407, character2_total_health, screen );
    apply_surface( 237, 387, character2_magic, screen );
    apply_surface( 237, 407, character2_total_magic, screen );
    apply_surface( 60, 395, character2_name, screen );
    //apply character 3 text
    apply_surface( 183, 427, character3_health, screen );
    apply_surface( 183, 447, character3_total_health, screen );
    apply_surface( 237, 427, character3_magic, screen );
    apply_surface( 237, 447, character3_total_magic, screen );
    apply_surface( 60, 435, character3_name, screen );

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
    }
    while(gameplay_text == true)
    {break;}
    while(boss == true)
    {break;}
    while(boss_text == true)
    {break;}
    while(end == true)
    {break;}
    while(credits == true)
    {break;}

    break;
}
    //Free the surface and quit SDL
    clean_up();

    return 0;
}

