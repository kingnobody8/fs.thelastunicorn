//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <sstream>

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

// the arrow location
int arx = 15;
int ary = 350;

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

//make the character selection, the primary selection, and sub selection
int choose1 = 0;
int choose2 = 0;
int choose3 = 0;

//The surfaces
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;
SDL_Surface *sky = NULL;
SDL_Surface *command_background = NULL;
SDL_Surface *character_background = NULL;
SDL_Surface *arrow = NULL;
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
SDL_Surface *lightning_text = NULL;
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

SDL_Surface *choose4 = NULL;
SDL_Surface *choose5 = NULL;
SDL_Surface *choose6 = NULL;

//The event structure that will be used
SDL_Event event;

//The font that's going to be used
TTF_Font *font = NULL;
TTF_Font *font_small = NULL;

//The color of the font
SDL_Color textColor = { 0, 0, 0 };



SDL_Surface *load_image( std::string filename )
{
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
    arrow = load_image( "arrow.png" );
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
    font = TTF_OpenFont( "tnr.ttf", 22 );
    font_small = TTF_OpenFont( "tnr.ttf", 15 );
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
    if( arrow == NULL )
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
    SDL_FreeSurface( arrow );
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

    //While the user hasn't quit
    while( quit == false )
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
                        if( ary != 350 )
                        { ary = ary - 40; break;}
                        else
                        {ary = 430; break;}
                    }
                    case SDLK_DOWN:
                    {
                        if( ary != 430 )
                        { ary = ary + 40; break;}
                        else
                        {ary = 350; break;}
                    }
                    case SDLK_a:
                    {
                        //character selection
                        if( ary == 350 && arx == 15 )
                        { choose1 = 1; ary = 350; arx = 280; break;}
                        if( ary == 390 && arx == 15 )
                        { choose1 = 2; ary = 350; arx = 280; break;}
                        if( ary == 430 && arx == 15 )
                        { choose1 = 3; ary = 350; arx = 280; break;}

                        //primary selection
                        //this one is the attack one, it is special because it has no sub selection
                        if( ary == 350 && arx == 280 )
                        { choose2 = 1; break;}

                        if( ary == 390 && arx == 280 )
                        { choose2 = 2; arx = 445; ary = 350; break;}
                        if( ary == 430 && arx == 280 )
                        { choose2 = 3; arx = 445; ary = 350; break;}

                        //sub selection
                        if( ary == 350 && arx == 445 )
                        { choose3 = 1; arx = 445; break;}
                        if( ary == 390 && arx == 445 )
                        { choose3 = 2; arx = 445; break;}
                        if( ary == 430 && arx == 445 )
                        { choose3 = 3; arx = 445; break;}

                    }
                    case SDLK_s:
                    {
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
                    }
                }
            }
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
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
                apply_surface( 505, 350, lightning_text, screen );
                apply_surface( 505, 390, fire_text, screen );
                apply_surface( 505, 430, ice_text, screen );
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

    apply_surface( arx, ary, arrow, screen);

    apply_surface( char1x, char1y, character1, screen);
    apply_surface( char2x, char2y, character1, screen);
    apply_surface( char3x, char3y, character1, screen);

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



    apply_surface( 470, 85, enemy1, screen);
    apply_surface( 470, 165, enemy1, screen);
    apply_surface( 470, 245, enemy1, screen);
    apply_surface( 550, 85, enemy1, screen);
    apply_surface( 550, 165, enemy1, screen);
    apply_surface( 550, 245, enemy1, screen);



    //see the choices
        if( running == true )
        {
            //The timer's time as a string
            std::stringstream ch1;
            std::stringstream ch2;
            std::stringstream ch3;

            //Convert the timer's time to a string
            ch1 << "CHOOSE1 is " << choose1;
            ch2 << "CHOOSE2 is " << choose2;
            ch3 << "CHOOSE3 is " << choose3;

            //Render the time surface
            choose4 = TTF_RenderText_Solid( font, ch1.str().c_str(), textColor );
            choose5 = TTF_RenderText_Solid( font, ch2.str().c_str(), textColor );
            choose6 = TTF_RenderText_Solid( font, ch3.str().c_str(), textColor );

            //Apply the time surface
            apply_surface( 300, 150,choose4, screen );
            apply_surface( 300, 170, choose5, screen );
            apply_surface( 300, 190, choose6, screen );

            //Free the time surface
            SDL_FreeSurface( choose4 );
             SDL_FreeSurface( choose5 );
              SDL_FreeSurface( choose6 );
        }

    //Render the text

    attack_text = TTF_RenderText_Solid( font, "ATTACK", textColor );
    magic_text = TTF_RenderText_Solid( font, "MAGIC", textColor );
    item_text = TTF_RenderText_Solid( font, "ITEM", textColor );
    character1_health = TTF_RenderText_Solid( font_small, "XXX", textColor );
    character1_total_health = TTF_RenderText_Solid( font_small, "XXX", textColor );
    character1_magic = TTF_RenderText_Solid( font_small, "XXX", textColor );
    character1_total_magic = TTF_RenderText_Solid( font_small, "XXX", textColor );

    character2_health = TTF_RenderText_Solid( font_small, "XXX", textColor );
    character2_total_health = TTF_RenderText_Solid( font_small, "XXX", textColor );
    character2_magic = TTF_RenderText_Solid( font_small, "XXX", textColor );
    character2_total_magic = TTF_RenderText_Solid( font_small, "XXX", textColor );

    character3_health = TTF_RenderText_Solid( font_small, "XXX", textColor );
    character3_total_health = TTF_RenderText_Solid( font_small, "XXX", textColor );
    character3_magic = TTF_RenderText_Solid( font_small, "XXX", textColor );
    character3_total_magic = TTF_RenderText_Solid( font_small, "XXX", textColor );

    character1_name = TTF_RenderText_Solid( font, "BECKETT", textColor );
    character2_name = TTF_RenderText_Solid( font, "SAMSON", textColor );
    character3_name = TTF_RenderText_Solid( font, "CHEERIO", textColor );

    rage_text = TTF_RenderText_Solid( font, "RAGE", textColor );
    hitx2_text = TTF_RenderText_Solid( font, "HIT X 2", textColor );
    limit_text = TTF_RenderText_Solid( font, "LIMIT", textColor );

    lightning_text = TTF_RenderText_Solid( font, "LIGHTNING", textColor );
    fire_text = TTF_RenderText_Solid( font, "FIRE", textColor );
    ice_text = TTF_RenderText_Solid( font, "ICICLE", textColor );

    protect_text = TTF_RenderText_Solid( font, "PROTECT", textColor );
    taunt_text = TTF_RenderText_Solid( font, "TAUNT", textColor );




    //apply character 1 text
    apply_surface( 180, 347, character1_health, screen );
    apply_surface( 180, 367, character1_total_health, screen );
    apply_surface( 230, 347, character1_magic, screen );
    apply_surface( 230, 367, character1_total_magic, screen );
    apply_surface( 60, 355, character1_name, screen );
    //apply character 2 text
    apply_surface( 180, 387, character2_health, screen );
    apply_surface( 180, 407, character2_total_health, screen );
    apply_surface( 230, 387, character2_magic, screen );
    apply_surface( 230, 407, character2_total_magic, screen );
    apply_surface( 60, 395, character2_name, screen );
    //apply character 3 text
    apply_surface( 180, 427, character3_health, screen );
    apply_surface( 180, 447, character3_total_health, screen );
    apply_surface( 230, 427, character3_magic, screen );
    apply_surface( 230, 447, character3_total_magic, screen );
    apply_surface( 60, 435, character3_name, screen );











    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }
    }

    //Free the surface and quit SDL
    clean_up();

    return 0;
}

