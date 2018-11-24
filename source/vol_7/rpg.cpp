//The headers
#include "SDL.h"
#undef main
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <string>
#include <sstream>
#include <time.h>


//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//the frame rate
int FRAMES_PER_SECOND = 30;

//what is the type of screen being shown
//show title screen
bool title_screen = true;
bool text_screen = false;
bool gameplay = false;
bool gameplay_text = false;
bool boss1 = false;
bool boss2 = false;
bool boss3 = false;
bool boss1_text = false;
bool boss2_text = false;
bool boss3_text = false;
bool end = false;
bool credits = false;

//the outcomes
bool win = false;
bool lose = false;

//which battle is being fought
int battle = 0;

//the music that will be played
Mix_Music *dark_winds = NULL;
Mix_Music *battle_theme = NULL;
Mix_Music *walking = NULL;
Mix_Music *win_music = NULL;
Mix_Music *loss_music = NULL;
Mix_Music *hood_on = NULL;
Mix_Music *hood_off = NULL;
Mix_Music *climax = NULL;
Mix_Music *end_music = NULL;



//the beats per minute for the songs
int dark_winds_bpms = 120;
int battle_theme_bpms = 300;

//which characters should attack
bool good1 = true;
bool good2 = true;
bool good3 = true;

// which enemies are shown on screen
bool bad1 = true;
bool bad2 = true;
bool bad3 = true;

bool bad4 = true;
bool bad5 = true;
bool bad6 = true;

bool evil = false;

// the arrow location
int arx = 15;
int ary = 350;

//what arrow to show
bool right = true;
bool left = false;

//the characters locations
int char1x = 65, char1y = 85;
int char2x = 15, char2y = 155;
int char3x = 15, char3y = 230;

//the enemy locations
int ene1x = 440, ene1y = 85;
int ene2x = 440, ene2y = 165;
int ene3x = 440, ene3y = 230;
int ene4x = 550, ene4y = 85;
int ene5x = 550, ene5y = 165;
int ene6x = 550, ene6y = 230;

//the final boss location
int bossx, bossy;

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
int enemy1_health = 800;
int enemy2_health  = 800;
int enemy3_health  = 800;
int enemy4_health  = 800;
int enemy5_health  = 800;
int enemy6_health  = 800;

//enemy types attack power

//the final boss health
int boss_health = 1500;
int boss_power = 5;
SDL_Surface *boss_health_text;

//the players attack and magic power
int player1_attack_power = 3;
int player1_magic_power = 1;
int player2_attack_power = 1;
int player2_magic_power = 3;
int player3_attack_power = 2;
int player3_magic_power = 2;

//the enemy attack power
int enemy1_attack = 3;
int enemy2_attack = 4;
int enemy3_attack = 5;
int enemy4_attack = 6;
int enemy5_attack = 7;
int enemy6_attack = 8;

//the values of magic
int rage_magic = 10;
int power_magic = 10;
int burn_magic = 10;
int freeze_magic = 10;


//the mulitpliers
int rage = 5;
int limit1_power = 0;
int limit2_power = 0;
int limit3_power = 0;
int burn = 3;
int freeze = 3;

//the counter for power x2
int power_counter = 0;

//the players counts of items
int player1_item1_count = 5;
int player1_item2_count = 5;
int player1_item3_count = 5;
int player2_item1_count = 5;
int player2_item2_count = 5;
int player2_item3_count = 5;
int player3_item1_count = 5;
int player3_item2_count = 5;
int player3_item3_count = 5;

//the values of items
int spirit = 50;
int hi_spirit = 100;
int ether = 10;
int hi_ether = 20;

//make the character selection, the primary selection, sub selection, and target selection
int choose1 = 0;
int choose2 = 0;
int choose3 = 0;
int choose4 = 0;

//make an array for each character to hold their selections
int player1_array[3] = {0};
int player2_array[3] = {0};
int player3_array[3] = {0};

int attack_number = 0;

//check whether or not the sub selection can even be accessed
bool play1m = true;
bool play2m = true;
bool play3m = true;
bool play1i = true;
bool play2i = true;
bool play3i = true;
//check whether or not a part of the magic sub selection can be used
bool play1m1 = true;
bool play1m2 = true;
bool play2m1 = true;
bool play2m2 = true;
bool play3m1 = true;
bool play3m2 = true;
//check whether or not a part of the item sub selection can be used
bool play1i1 = true;
bool play1i2 = true;
bool play1i3 = true;
bool play2i1 = true;
bool play2i2 = true;
bool play2i3 = true;
bool play3i1 = true;
bool play3i2 = true;
bool play3i3 = true;



//The surfaces
SDL_Surface *screen = NULL;

SDL_Surface *title_screen_background = NULL;
SDL_Surface *start_button_on = NULL;
SDL_Surface *start_button_off = NULL;
SDL_Surface *direction_button_on = NULL;
SDL_Surface *direction_button_off = NULL;

SDL_Surface *text_background = NULL;

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
//the characters
SDL_Surface *warrior_stance = NULL;
SDL_Surface *warrior_out = NULL;
SDL_Surface *warrior_stab = NULL;
SDL_Surface *mage_stance = NULL;
SDL_Surface *mage_out = NULL;
SDL_Surface *mage_stab = NULL;
SDL_Surface *marine_stance = NULL;
SDL_Surface *marine_out = NULL;
SDL_Surface *marine_shoot = NULL;
SDL_Surface *enemy1 = NULL;
SDL_Surface *enemy2 = NULL;
SDL_Surface *enemy3 = NULL;
SDL_Surface *enemy4 = NULL;
SDL_Surface *enemy5 = NULL;
SDL_Surface *enemy6 = NULL;
SDL_Surface *enemy1dead = NULL;
SDL_Surface *enemy2dead = NULL;
SDL_Surface *enemy3dead = NULL;
SDL_Surface *enemy4dead = NULL;
SDL_Surface *enemy5dead = NULL;
SDL_Surface *enemy6dead = NULL;
SDL_Surface *warrior_dead = NULL;
SDL_Surface *mage_dead = NULL;
SDL_Surface *marine_dead = NULL;
SDL_Surface *unicorn = NULL;
SDL_Surface *unicorn_stab = NULL;

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
// primary selection attributes
SDL_Surface *attack_text = NULL;
SDL_Surface *magic_text = NULL;
SDL_Surface *item_text = NULL;
//sub selection attributes
//magic
SDL_Surface *rage_text = NULL;
SDL_Surface *hitx2_text = NULL;
SDL_Surface *limit_text = NULL;
SDL_Surface *fire_text = NULL;
SDL_Surface *ice_text = NULL;
//item sub selection options
SDL_Surface *player1_spirits_text = NULL;
SDL_Surface *player1_hi_spirits_text = NULL;
SDL_Surface *player1_lazarus_text = NULL;
SDL_Surface *player2_ether_text = NULL;
SDL_Surface *player2_hi_ether_text = NULL;
SDL_Surface *player2_lazarus_text = NULL;
SDL_Surface *player3_hi_spirits_text = NULL;
SDL_Surface *player3_hi_ether_text = NULL;
SDL_Surface *player3_lazarus_text = NULL;
//the enemy health text
SDL_Surface *enemy1_health_text = NULL;
SDL_Surface *enemy2_health_text = NULL;
SDL_Surface *enemy3_health_text = NULL;
SDL_Surface *enemy4_health_text = NULL;
SDL_Surface *enemy5_health_text = NULL;
SDL_Surface *enemy6_health_text = NULL;

//the hit/attack text
SDL_Surface *hit1_text = NULL;
SDL_Surface *hit2_text = NULL;
SDL_Surface *hit3_text = NULL;

//The event structure that will be used
SDL_Event event;

//The font that's going to be used
TTF_Font *font = NULL;
TTF_Font *font_small = NULL;

//The color of the font
SDL_Color textColor = { 0, 0, 0 };
SDL_Color alertColor = { 237, 28, 36 };
SDL_Color itemColor = { 63, 72, 204 };
SDL_Color introColor = {255, 255, 255};

//the intro text
SDL_Surface *text1 = NULL;
SDL_Surface *text2 = NULL;
SDL_Surface *text3 = NULL;
SDL_Surface *text4 = NULL;
SDL_Surface *text5 = NULL;
SDL_Surface *text6 = NULL;
SDL_Surface *text7 = NULL;
SDL_Surface *text8 = NULL;
SDL_Surface *text9 = NULL;
SDL_Surface *text10 = NULL;
SDL_Surface *text11 = NULL;
SDL_Surface *text12 = NULL;
SDL_Surface *text13 = NULL;
SDL_Surface *text14 = NULL;
SDL_Surface *text15 = NULL;

SDL_Surface *blerb1 = NULL;
SDL_Surface *blerb2 = NULL;
SDL_Surface *blerb3 = NULL;
SDL_Surface *blerb4 = NULL;
SDL_Surface *blerb5 = NULL;
SDL_Surface *blerb6 = NULL;
SDL_Surface *blerb7 = NULL;
SDL_Surface *blerb8 = NULL;
SDL_Surface *blerb9 = NULL;
SDL_Surface *blerb10 = NULL;
SDL_Surface *blerb11 = NULL;
SDL_Surface *blerb12 = NULL;
SDL_Surface *blerb13 = NULL;
SDL_Surface *blerb14 = NULL;
SDL_Surface *blerb15 = NULL;
SDL_Surface *blerb16 = NULL;
SDL_Surface *blerb17 = NULL;
SDL_Surface *blerb18 = NULL;
SDL_Surface *blerb19 = NULL;
SDL_Surface *blerb20 = NULL;
SDL_Surface *blerb21 = NULL;
SDL_Surface *blerb22 = NULL;
SDL_Surface *blerb23 = NULL;
SDL_Surface *blerb24 = NULL;
SDL_Surface *blerb25 = NULL;
SDL_Surface *blerb26 = NULL;
SDL_Surface *blerb27 = NULL;
SDL_Surface *blerb28 = NULL;
SDL_Surface *blerb29 = NULL;
SDL_Surface *blerb30 = NULL;
SDL_Surface *blerb31 = NULL;
SDL_Surface *blerb32 = NULL;
SDL_Surface *blerb33 = NULL;
SDL_Surface *blerb34 = NULL;
SDL_Surface *blerb35 = NULL;
SDL_Surface *blerb36 = NULL;
SDL_Surface *blerb37 = NULL;
SDL_Surface *blerb38 = NULL;
SDL_Surface *blerb39 = NULL;
SDL_Surface *blerb40 = NULL;
SDL_Surface *blerb41 = NULL;
SDL_Surface *blerb42 = NULL;
SDL_Surface *blerb43 = NULL;
SDL_Surface *blerb44 = NULL;
SDL_Surface *blerb45 = NULL;
SDL_Surface *blerb46 = NULL;
SDL_Surface *blerb47 = NULL;
SDL_Surface *blerb48 = NULL;


SDL_Surface *credits_picture = NULL;


SDL_Surface *mage_left = NULL;
SDL_Surface *mage_left_stab = NULL;

SDL_Surface *megacorn = NULL;
SDL_Surface *megacorn_stab = NULL;

SDL_Surface *attack_number_text = NULL;


//The timer
class Timer
{
private:
    //The clock time when the timer started
    int startTicks;

    //The ticks stored when the timer was paused
    int pausedTicks;

    //The timer status
    bool paused;
    bool started;

public:
    //Initializes variables
    Timer();

    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    int get_ticks();

    //Checks the status of the timer
    bool is_started();
    bool is_paused();
};

SDL_Surface *load_image( std::string filename )
{
	std::string prepath("assets/vol_7/");
	filename = prepath + filename;

    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if ( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );

        //If the image was optimized just fine
        if ( optimizedImage != NULL )
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
    if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if ( screen == NULL )
    {
        return false;
    }
    //Initialize SDL_ttf
    if ( TTF_Init() == -1 )
    {
        return false;
    }

    //Initialize SDL_mixer
    if ( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
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
    //Load the music
    dark_winds = Mix_LoadMUS( "assets/vol_7/Dark Winds.wav" );
    battle_theme = Mix_LoadMUS( "assets/vol_7/Battle Theme.wav" );
    walking = Mix_LoadMUS( "assets/vol_7/A Walk in the Land of the Last Unicorn.wav" );
    win_music = Mix_LoadMUS( "assets/vol_7/FTW.wav" );
    loss_music = Mix_LoadMUS( "assets/vol_7/Epic Loss.wav" );
    hood_on = Mix_LoadMUS( "assets/vol_7/The Hood Is On.wav" );
    hood_off = Mix_LoadMUS( "assets/vol_7/The Hood Is Off.wav" );
    climax = Mix_LoadMUS( "assets/vol_7/Climax.wav" );
    end_music = Mix_LoadMUS( "assets/vol_7/Ending Title.wav" );


    //If there was a problem loading the music
    if ( dark_winds == NULL )
    {
        return false;
    }
    if ( battle_theme == NULL )
    {
        return false;
    }
    if ( walking == NULL )
    {
        return false;
    }
    //Load
    if ( win_music == NULL )
    {
        return false;
    }
    if ( loss_music == NULL )
    {
        return false;
    }
    if ( hood_on == NULL )
    {
        return false;
    }
    if ( hood_off == NULL )
    {
        return false;
    }
    if ( climax == NULL )
    {
        return false;
    }
    if ( end_music == NULL )
    {
        return false;
    }
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
    warrior_stance = load_image( "warrior_sheath.png" );
    warrior_out = load_image( "warrior_out.png" );
    warrior_stab = load_image( "warrior_stab.png" );
    mage_stance = load_image( "mage_stance.png" );
    mage_out = load_image( "mage_out.png" );
    mage_stab = load_image( "mage_stab.png" );
    marine_stance = load_image( "marine_stance.png" );
    marine_out = load_image( "marine_out.png" );
    marine_shoot = load_image( "marine_shoot.png" );
    enemy1 = load_image( "enemy_orange.png" );
    enemy2 = load_image( "enemy_purple.png" );
    enemy3 = load_image( "enemy_green.png" );
    enemy4 = load_image( "enemy_orange_bonk.png" );
    enemy5 = load_image( "enemy_purple_bonk.png" );
    enemy6 = load_image( "enemy_green_bonk.png" );
    warrior_dead = load_image( "warrior_dead.png" );
    mage_dead = load_image( "mage_dead.png" );
    marine_dead = load_image( "marine_dead.png" );
    enemy1dead = load_image( "enemy_orange_dead.png" );
    enemy2dead = load_image( "enemy_purple_dead.png" );
    enemy3dead = load_image( "enemy_green_dead.png" );
    enemy4dead = load_image( "enemy_orange_bonk_dead.png" );
    enemy5dead = load_image( "enemy_purple_bonk_dead.png" );
    enemy6dead = load_image( "enemy_green_bonk_dead.png" );
    sky = load_image( "sky.png" );
    start_button_on = load_image( "start_button_on.png" );
    start_button_off = load_image( "start_button_off.png" );
    direction_button_on = load_image( "directions_button_on.png" );
    direction_button_off = load_image( "directions_button_off.png" );
    text_background = load_image( "text_background.png" );
    unicorn = load_image( "unicorn.png" );
    unicorn_stab = load_image( "unicorn_stab.png" );
    megacorn = load_image( "megacorn.png" );
    megacorn_stab = load_image( "megacorn_laser.png" );

    credits_picture = load_image( "credits.png" );

    blerb1 = load_image( "blerb1.png" );
    blerb2 = load_image( "blerb2.png" );
    blerb3 = load_image( "blerb3.png" );
    blerb4 = load_image( "blerb4.png" );
    blerb5 = load_image( "blerb5.png" );
    blerb6 = load_image( "blerb6.png" );
    blerb7 = load_image( "blerb7.png" );
    blerb8 = load_image( "blerb8.png" );
    blerb9 = load_image( "blerb9.png" );
    blerb10 = load_image( "blerb10.png" );
    blerb11 = load_image( "blerb11.png" );
    blerb12 = load_image( "blerb12.png" );
    blerb13 = load_image( "blerb13.png" );
    blerb14 = load_image( "blerb14.png" );
    blerb15 = load_image( "blerb15.png" );
    blerb16 = load_image( "blerb16.png" );
    blerb17 = load_image( "blerb17.png" );
    blerb18 = load_image( "blerb18.png" );
    blerb19 = load_image( "blerb19.png" );
    blerb20 = load_image( "blerb20.png" );
    blerb21 = load_image( "blerb21.png" );
    blerb22 = load_image( "blerb22.png" );
    blerb23 = load_image( "blerb23.png" );
    blerb24 = load_image( "blerb24.png" );
    blerb25 = load_image( "blerb25.png" );
    blerb26 = load_image( "blerb26.png" );
    blerb27 = load_image( "blerb27.png" );
    blerb28 = load_image( "blerb28.png" );
    blerb29 = load_image( "blerb29.png" );
    blerb30 = load_image( "blerb30.png" );
    blerb31 = load_image( "blerb31.png" );
    blerb32 = load_image( "blerb32.png" );
    blerb33 = load_image( "blerb33.png" );
    blerb34 = load_image( "blerb34.png" );
    blerb35 = load_image( "blerb35.png" );
    blerb36 = load_image( "blerb36.png" );
    blerb37 = load_image( "blerb37.png" );
    blerb38 = load_image( "blerb38.png" );
    blerb39 = load_image( "blerb39.png" );
    blerb40 = load_image( "blerb40.png" );
    blerb41 = load_image( "blerb41.png" );
    blerb42 = load_image( "blerb42.png" );
    blerb43 = load_image( "blerb43.png" );
    blerb44 = load_image( "blerb44.png" );
    blerb45 = load_image( "blerb45.png" );
    blerb46 = load_image( "blerb46.png" );
    blerb47 = load_image( "blerb47.png" );
    blerb48 = load_image( "blerb48.png" );

    mage_left = load_image( "mage_left.png" );
    mage_left_stab = load_image( "mage_left_stab.png" );

    //Open the font
    font = TTF_OpenFont( "assets/vol_7/tnr.ttf", 22 );
    font_small = TTF_OpenFont( "assets/vol_7/tnr.ttf", 15 );
    //If there was an error in loading the font
    if ( font == NULL )
    {
        return false;
    }
    if ( font_small == NULL )
    {
        return false;
    }
    //If there was an error in loading the image
    if ( start_button_on == NULL )
    {
        return false;
    }
    if ( start_button_off == NULL )
    {
        return false;
    }
    if ( direction_button_on == NULL )
    {
        return false;
    }
    if ( direction_button_off == NULL )
    {
        return false;
    }
    if ( background == NULL )
    {
        return false;
    }
    if ( command_background == NULL )
    {
        return false;
    }
    if ( character_background == NULL )
    {
        return false;
    }
    if ( arrow_right == NULL )
    {
        return false;
    }
    if ( arrow_left == NULL )
    {
        return false;
    }
    if ( health_counter == NULL )
    {
        return false;
    }
    if ( magic_counter == NULL )
    {
        return false;
    }
    if ( attack_background == NULL )
    {
        return false;
    }
    if ( magic_background == NULL )
    {
        return false;
    }
    if ( item_background == NULL )
    {
        return false;
    }
    if ( magic_sub_selection == NULL )
    {
        return false;
    }
    if ( item_sub_selection == NULL )
    {
        return false;
    }
    if ( warrior_stance == NULL )
    {
        return false;
    }
    if ( warrior_out == NULL )
    {
        return false;
    }
    if ( warrior_stab == NULL )
    {
        return false;
    }
    if ( mage_stance == NULL )
    {
        return false;
    }
    if ( mage_out == NULL )
    {
        return false;
    }
    if ( mage_stab == NULL )
    {
        return false;
    }
    if ( marine_stance == NULL )
    {
        return false;
    }
    if ( marine_out == NULL )
    {
        return false;
    }
    if ( marine_shoot == NULL )
    {
        return false;
    }
    if ( enemy1 == NULL )
    {
        return false;
    }
    if ( enemy2 == NULL )
    {
        return false;
    }
    if ( enemy3 == NULL )
    {
        return false;
    }
    if ( enemy4 == NULL )
    {
        return false;
    }
    if ( enemy5 == NULL )
    {
        return false;
    }
    if ( enemy6 == NULL )
    {
        return false;
    }
    if ( enemy1dead == NULL )
    {
        return false;
    }
    if ( enemy2dead == NULL )
    {
        return false;
    }
    if ( enemy3dead == NULL )
    {
        return false;
    }
    if ( enemy4dead == NULL )
    {
        return false;
    }
    if ( enemy5dead == NULL )
    {
        return false;
    }
    if ( enemy6dead == NULL )
    {
        return false;
    }
    if ( sky == NULL )
    {
        return false;
    }
    if ( text_background == NULL )
    {
        return false;
    }
    if ( blerb1  == NULL || blerb2 == NULL || blerb3  == NULL || blerb4 == NULL || blerb5  == NULL || blerb6 == NULL || blerb7  == NULL || blerb8 == NULL || blerb9  == NULL || blerb10 == NULL || blerb11  == NULL || blerb12 == NULL || blerb13  == NULL || blerb14 == NULL || blerb15  == NULL || blerb16 == NULL || blerb17  == NULL || blerb18 == NULL)
    {
        return false;
    }
    if ( blerb19  == NULL || blerb20 == NULL || blerb21  == NULL || blerb22 == NULL || blerb23  == NULL || blerb24 == NULL || blerb25  == NULL || blerb26 == NULL || blerb27  == NULL || blerb28 == NULL || blerb29  == NULL || blerb30 == NULL || blerb31  == NULL || blerb32 == NULL || blerb33  == NULL || blerb34 == NULL || blerb35  == NULL || blerb36 == NULL)
    {
        return false;
    }
    if ( blerb37  == NULL || blerb38 == NULL || blerb39  == NULL || blerb40 == NULL || blerb41  == NULL || blerb42 == NULL || blerb43  == NULL || blerb44 == NULL || blerb45  == NULL || blerb46 == NULL || blerb47  == NULL || blerb48 == NULL)
    {
        return false;
    }
    if ( mage_left == NULL )
    {
        return false;
    }
    if ( mage_left_stab == NULL )
    {
        return false;
    }
    if ( warrior_dead == NULL )
    {
        return false;
    }
    if ( mage_dead == NULL )
    {
        return false;
    }
    if ( marine_dead == NULL )
    {
        return false;
    }
    if ( unicorn == NULL )
    {
        return false;
    }
    if ( unicorn_stab == NULL )
    {
        return false;
    }
    if ( megacorn == NULL )
    {
        return false;
    }
    if ( megacorn_stab == NULL )
    {
        return false;
    }
    if ( credits_picture == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the music
    Mix_FreeMusic( dark_winds );
    Mix_FreeMusic( battle_theme );
    Mix_FreeMusic( walking );
    Mix_FreeMusic( win_music );
    Mix_FreeMusic( loss_music );
    Mix_FreeMusic( hood_on );
    Mix_FreeMusic( hood_off );
    Mix_FreeMusic( climax );
    Mix_FreeMusic( end_music );

    //Quit SDL_mixer
    Mix_CloseAudio();

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
    SDL_FreeSurface( warrior_stance );
    SDL_FreeSurface( warrior_out );
    SDL_FreeSurface( warrior_stab );
    SDL_FreeSurface( mage_stance );
    SDL_FreeSurface( mage_out );
    SDL_FreeSurface( mage_stab );
    SDL_FreeSurface( marine_stance );
    SDL_FreeSurface( marine_out );
    SDL_FreeSurface( marine_shoot );
    SDL_FreeSurface( enemy1 );
    SDL_FreeSurface( enemy2 );
    SDL_FreeSurface( enemy3 );
    SDL_FreeSurface( enemy4 );
    SDL_FreeSurface( enemy5 );
    SDL_FreeSurface( enemy6 );
    SDL_FreeSurface( enemy1dead );
    SDL_FreeSurface( enemy2dead );
    SDL_FreeSurface( enemy3dead );
    SDL_FreeSurface( enemy4dead );
    SDL_FreeSurface( enemy5dead );
    SDL_FreeSurface( enemy6dead );
    SDL_FreeSurface( warrior_dead );
    SDL_FreeSurface( mage_dead );
    SDL_FreeSurface( marine_dead );
    SDL_FreeSurface( sky );
    SDL_FreeSurface( start_button_on );
    SDL_FreeSurface( start_button_off );
    SDL_FreeSurface( direction_button_on );
    SDL_FreeSurface( direction_button_off );
    SDL_FreeSurface( text_background );
    SDL_FreeSurface( blerb1 );
    SDL_FreeSurface( blerb2 );
    SDL_FreeSurface( blerb3 );
    SDL_FreeSurface( blerb4 );
    SDL_FreeSurface( blerb5 );
    SDL_FreeSurface( blerb6 );
    SDL_FreeSurface( blerb7 );
    SDL_FreeSurface( blerb8 );
    SDL_FreeSurface( blerb9 );
    SDL_FreeSurface( blerb10 );
    SDL_FreeSurface( blerb11 );
    SDL_FreeSurface( blerb12 );
    SDL_FreeSurface( blerb13 );
    SDL_FreeSurface( blerb14 );
    SDL_FreeSurface( blerb15 );
    SDL_FreeSurface( blerb16 );
    SDL_FreeSurface( blerb17 );
    SDL_FreeSurface( blerb18 );
    SDL_FreeSurface( blerb19 );
    SDL_FreeSurface( blerb20 );
    SDL_FreeSurface( blerb21 );
    SDL_FreeSurface( blerb22 );
    SDL_FreeSurface( blerb23 );
    SDL_FreeSurface( blerb24 );
    SDL_FreeSurface( blerb25 );
    SDL_FreeSurface( blerb26 );
    SDL_FreeSurface( blerb27 );
    SDL_FreeSurface( blerb28 );
    SDL_FreeSurface( blerb29 );
    SDL_FreeSurface( blerb30 );
    SDL_FreeSurface( blerb31 );
    SDL_FreeSurface( blerb32 );
    SDL_FreeSurface( blerb33 );
    SDL_FreeSurface( blerb34 );
    SDL_FreeSurface( blerb35 );
    SDL_FreeSurface( blerb36 );
    SDL_FreeSurface( blerb37 );
    SDL_FreeSurface( blerb38 );
    SDL_FreeSurface( blerb39 );
    SDL_FreeSurface( blerb40 );
    SDL_FreeSurface( blerb41 );
    SDL_FreeSurface( blerb42 );
    SDL_FreeSurface( blerb43 );
    SDL_FreeSurface( blerb44 );
    SDL_FreeSurface( blerb45 );
    SDL_FreeSurface( blerb46 );
    SDL_FreeSurface( blerb47 );
    SDL_FreeSurface( blerb48 );
    SDL_FreeSurface( credits_picture );
    SDL_FreeSurface( mage_left );
    SDL_FreeSurface( mage_left_stab );
    SDL_FreeSurface( unicorn );
    SDL_FreeSurface( unicorn_stab );
    SDL_FreeSurface( megacorn );
    SDL_FreeSurface( megacorn_stab );

    //Close the font that was used
    TTF_CloseFont( font );

    //Quit SDL_ttf
    TTF_Quit();

    //Quit SDL
    SDL_Quit();
}

Timer::Timer()
{
    //Initialize the variables
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

void Timer::start()
{
    //Start the timer
    started = true;

    //Unpause the timer
    paused = false;

    //Get the current clock time
    startTicks = SDL_GetTicks();
}

void Timer::stop()
{
    //Stop the timer
    started = false;

    //Unpause the timer
    paused = false;
}

void Timer::pause()
{
    //If the timer is running and isn't already paused
    if ( ( started == true ) && ( paused == false ) )
    {
        //Pause the timer
        paused = true;

        //Calculate the paused ticks
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::unpause()
{
    //If the timer is paused
    if ( paused == true )
    {
        //Unpause the timer
        paused = false;

        //Reset the starting ticks
        startTicks = SDL_GetTicks() - pausedTicks;

        //Reset the paused ticks
        pausedTicks = 0;
    }
}

int Timer::get_ticks()
{
    //If the timer is running
    if ( started == true )
    {
        //If the timer is paused
        if ( paused == true )
        {
            //Return the number of ticks when the timer was paused
            return pausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            return SDL_GetTicks() - startTicks;
        }
    }

    //If the timer isn't running
    return 0;
}

bool Timer::is_started()
{
    return started;
}

bool Timer::is_paused()
{
    return paused;
}

int main( int argc, char* args[] )
{
    //Make sure the program waits for a quit
    bool quit = false;

    bool running = true;

    bool start_button = true;

    bool fight = false;
    int fight_turn = 0;

    bool music_stop = false;
    bool battle_start = true;

    bool boos = true;


    //the offsets of the sky background
    float bgX = 0, bgY = 0;

    //The frame rate regulator
    Timer fps;
    //the bpm for the title screen
    Timer title_time;
    //timer for the character animations
    Timer character1_time;
    Timer character2_time;
    Timer character3_time;

    //timer for the win music
    Timer win_time;

    //the timer for the intro text
    Timer intro_text;
    Timer exit_text;

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
    srand( time(0) );

    int text_counter = 0;

    //Initialize
    if ( init() == false )
    {
        return 1;
    }

    //Load the files
    if ( load_files() == false )
    {
        return 1;
    }



    while (quit == false)
    {
        while (title_screen == true)
        {


            //If there is no music playing
            if ( Mix_PlayingMusic() == 0 )
            {
                title_time.start();
                //Play the music
                if ( Mix_PlayMusic( dark_winds, -1 ) == 1 )
                {
                    return 1;
                }
            }

            //While there's an event to handle
            while ( SDL_PollEvent( &event ) )
            {
                //If a key was pressed
                if ( event.type == SDL_KEYDOWN )
                {
                    switch ( event.key.keysym.sym )
                    {
                    case SDLK_UP:
                    {
                        if ( start_button == true)
                        {
                            start_button = false;
                            break;
                        }
                        else if (start_button == false)
                        {
                            start_button = true;
                            break;
                        }
                    }
                    case SDLK_DOWN:
                    {
                        if ( start_button == true)
                        {
                            start_button = false;
                            break;
                        }
                        else if (start_button == false)
                        {
                            start_button = true;
                            break;
                        }
                    }
                    case SDLK_a:
                    {
                        if (start_button == true)
                        {
                            title_screen = false;
                            text_screen = true;
                            break;
                        }
                    }
                    case SDLK_RETURN:
                    {
                        if (start_button == true)
                        {
                            title_screen = false;
                            text_screen = true;
                            break;
                        }
                    }
                    case SDLK_SPACE:
                    {
                        if (start_button == true)
                        {
                            if ( Mix_PlayingMusic() != 0 )
                            {
                                //Pause the music
                                Mix_HaltMusic();
                            }


                            title_screen = false;
                            text_screen = true;
                            break;
                        }
                    }
                    default:
                    {
                        break;
                    }
                    }
                }
                //If the user has Xed out the window
                if ( event.type == SDL_QUIT )
                {
                    //Quit the program
                    title_screen = false;
                }
                apply_surface(0, 0, text_background, screen);

                if (start_button == true)
                {
                    apply_surface(220, 220, start_button_on, screen );
                    apply_surface(120, 350, direction_button_off, screen );
                    break;
                }
                else
                {
                    apply_surface(220, 220, start_button_off, screen );
                    apply_surface(120, 350, direction_button_on, screen );
                    break;
                }

            }

            //Update the screen
            if ( SDL_Flip( screen ) == -1 )
            {
                return 1;
            }

            //Cap the frame rate
            if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
            {
                SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
            }

        }
        while (text_screen == true)
        {

            intro_text.start();
            bool texting = true;

            while (texting == true)
            {
                //If there is no music playing
                if ( Mix_PlayingMusic() == 0 )
                {
                    title_time.start();
                    //Play the music
                    if ( Mix_PlayMusic( dark_winds, -1 ) == 1 )
                    {
                        return 1;
                    }
                }
                apply_surface(0, 0, text_background, screen);

                apply_surface(50, 40, text1, screen);
                apply_surface(50, 70, text2, screen);
                apply_surface(50, 100, text3, screen);
                apply_surface(50, 130, text4, screen);
                apply_surface(50, 160, text5, screen);
                apply_surface(50, 190, text6, screen);
                apply_surface(50, 220, text7, screen);
                apply_surface(50, 250, text8, screen);
                apply_surface(50, 280, text9, screen);
                apply_surface(50, 310, text10, screen);
                apply_surface(50, 340, text11, screen);
                apply_surface(50, 370, text12, screen);
                apply_surface(50, 400, text13, screen);
                apply_surface(50, 430, text14, screen);
                apply_surface(400, 430, text15, screen);



                while ( SDL_PollEvent( &event ) )
                {

                    //If a key was pressed
                    if ( event.type == SDL_KEYDOWN )
                    {
                        switch ( event.key.keysym.sym )
                        {
                        case SDLK_a:
                        {
                            texting = false;
                            gameplay_text = true;
                        }
                        default:
                        {
                            texting = false;
                            gameplay_text = true;
                        }
                        }
                    }
                    //If the user has Xed out the window
                    if ( event.type == SDL_QUIT )
                    {
                        //Quit the program
                        texting = false;
                    }
                }



                //Update the screen
                if ( SDL_Flip( screen ) == -1 )
                {
                    return 1;
                }

                //Cap the frame rate
                if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                {
                    SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                }
                if (intro_text.get_ticks() > 1000)
                {
                    text1 = TTF_RenderText_Solid( font, "In the far away land of Canadia, evil dwells among the citizens.", introColor );
                }
                if (intro_text.get_ticks() > 5000)
                    text2 = TTF_RenderText_Solid( font, "The immortal Dark Overlord and his armies have wrought havoc ", introColor );
                if (intro_text.get_ticks() > 5000)
                    text3 = TTF_RenderText_Solid( font, "upon the land, while on the path to kill The Duke of Canadia.", introColor );
                if (intro_text.get_ticks() > 12000)
                    text4 = TTF_RenderText_Solid( font, "The Duke has lost nearly all control of his dominion and ", introColor );
                if (intro_text.get_ticks() > 12000)
                    text5 = TTF_RenderText_Solid( font, "The Overlord's armies have surrounded his castle.", introColor );
                if (intro_text.get_ticks() > 17000)
                    text6 = TTF_RenderText_Solid( font, "Prophecy foretold of the Overlord's only weakness,", introColor );
                if (intro_text.get_ticks() > 21000)
                    text7 = TTF_RenderText_Solid( font, "the horn of a unicorn.", introColor );
                if (intro_text.get_ticks() > 23000)
                    text8 = TTF_RenderText_Solid( font, "However, the unicorns have been extinct for some time. ", introColor );
                if (intro_text.get_ticks() > 27000)
                    text9 = TTF_RenderText_Solid( font, "All were killed in the early days of the Dark Overlord.", introColor );
                if (intro_text.get_ticks() > 31000)
                    text10 = TTF_RenderText_Solid( font, "In the final battle, the last of The Duke's armies were defeated. ", introColor );
                if (intro_text.get_ticks() > 35000)
                    text11 = TTF_RenderText_Solid( font, "The Duke and his leading generals fled.", introColor );
                if (intro_text.get_ticks() > 38000)
                    text12 = TTF_RenderText_Solid( font, "Out of desperation, The Duke sent two of his most noble men", introColor );
                if (intro_text.get_ticks() > 41000)
                    text13 = TTF_RenderText_Solid( font, "to the past in search of a unicorn horn. ", introColor );
                if (intro_text.get_ticks() > 44000)
                    text14 = TTF_RenderText_Solid( font, "This is their last hope...", introColor );
                if (intro_text.get_ticks() > 46000)
                    text15 = TTF_RenderText_Solid( font, "Click to Continue", introColor );

            }
            Mix_HaltMusic();
            text_screen = false;
            break;
        }
        while (gameplay_text == true)
        {
            if ( Mix_PlayingMusic() == 0 )
            {
                title_time.start();
                //Play the music
                if ( Mix_PlayMusic( walking, -1 ) == 1 )
                {
                    return 1;
                }
            }

            //Apply the surface to the screen
            apply_surface(bgX, bgY, sky, screen );
            apply_surface( bgX + background->w, bgY, sky, screen );

            apply_surface( 0, 0, background, screen );
            apply_surface( 0, 330, command_background, screen );
            apply_surface( 50, 345, character_background, screen);
            apply_surface( 50, 385, character_background, screen);
            apply_surface( 50, 425, character_background, screen);
            apply_surface( 170, 345, health_counter, screen);
            apply_surface( 220, 345, magic_counter, screen);


            //While there's an event to handle
            while ( SDL_PollEvent( &event ) )
            {
                //If a key was pressed
                if ( event.type == SDL_KEYDOWN )
                {
                    switch ( event.key.keysym.sym )
                    {
                    case SDLK_a:
                    {
                        text_counter = text_counter + 1;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                    }
                }
                //If the user has Xed out the window
                if ( event.type == SDL_QUIT )
                {
                    //Quit the program
                    gameplay_text = false;
                }
            }
            if (text_counter == 0)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(ene1x, ene1y, enemy1, screen);
                apply_surface(50, 190, blerb1, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);

            }
            if (text_counter == 1)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(ene1x, ene1y, enemy1, screen);
                apply_surface(90, 30, blerb2, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);

            }
            if (text_counter == 2)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(ene1x, ene1y, enemy1, screen);
                apply_surface(ene4x-90, ene4y-50, blerb3, screen);
                apply_surface(ene4x, ene4y, mage_left_stab, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 3)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(ene1x, ene1y, enemy1dead, screen);
                apply_surface(ene4x-90, ene4y-50, blerb3, screen);
                apply_surface(ene4x, ene4y, mage_left_stab, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 4)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(80, 30, blerb4, screen);
                apply_surface(ene5x, ene5y, mage_left , screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 5)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(ene5x-250, ene5y-60, blerb5, screen);
                apply_surface(ene5x, ene5y, mage_left, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 6)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(90, 10, blerb6, screen);
                apply_surface(ene5x, ene5y, mage_left, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 7)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(ene5x-250, ene5y-70, blerb7, screen);
                apply_surface(ene5x, ene5y, mage_left, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 8)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(ene5x-280, ene5y-70, blerb8, screen);
                apply_surface(ene5x, ene5y, mage_left, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 9)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(90, 10, blerb9, screen);
                apply_surface(ene5x, ene5y, mage_left, screen);
                apply_surface(char1x, char1y, warrior_out, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 10)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(ene5x-130, ene5y-40, blerb10, screen);
                apply_surface(ene5x, ene5y, mage_left, screen);
                apply_surface(char1x, char1y, warrior_out, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 11)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(ene5x-260, ene5y-60, blerb11, screen);
                apply_surface(ene5x, ene5y, mage_left, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 12)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(50, 190, blerb12, screen);
                apply_surface(ene5x, ene5y, mage_left, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 13)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(90, 0, blerb13, screen);
                apply_surface(ene5x, ene5y, mage_left, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 14)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(ene5x-50,ene5y-30, blerb14, screen);
                apply_surface(ene5x, ene5y, mage_left, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 15)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(ene5x-260,ene5y-60, blerb15, screen);
                apply_surface(ene5x, ene5y, mage_left, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 16)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(ene5x-260,ene5y-40, blerb16, screen);
                apply_surface(ene5x, ene5y, mage_left, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 17)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(ene5x-270, ene5y-60, blerb17, screen);
                apply_surface(ene5x, ene5y, mage_left, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 18)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(90, 10, blerb18, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char2x, char2y, mage_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 19)
            {
                if ( Mix_PlayingMusic() != 0 )
                {
                    //Pause the music
                    Mix_HaltMusic();
                }
                gameplay_text = false;
                gameplay = true;
            }








            //Update the screen
            if ( SDL_Flip( screen ) == -1 )
            {
                return 1;
            }

            //Cap the frame rate
            if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
            {
                SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
            }
        }
        while (gameplay == true)
        {
            if ( Mix_PlayingMusic() == 0 )
            {
                //Play the music
                if ( Mix_PlayMusic( battle_theme, -1 ) == 1 )
                {
                    return 1;
                }
            }

            //Start the frame timer
            fps.start();

            if (battle == 0 && battle_start == true)
            {
                player1_health = player1_total_health;
                player2_health = player2_total_health;
                player3_health = player3_total_health;
                player1_magic = player1_total_magic;
                player2_magic = player2_total_magic;
                player3_magic = player3_total_magic;

                enemy1_health = 800;

                bad1 = true;
                bad2 = false;
                bad3 = false;
                bad4 = false;
                bad5 = false;
                bad6 = false;
                battle_start = false;
            }
            if (battle == 1 && battle_start == true)
            {
                player1_health = player1_total_health;
                player2_health = player2_total_health;
                player3_health = player3_total_health;

                enemy1_health = 800;
                enemy2_health = 900;

                bad1 = true;
                bad2 = true;
                bad3 = false;
                bad4 = false;
                bad5 = false;
                bad6 = false;
                battle_start = false;
            }
            if (battle == 2 && battle_start == true)
            {
                player1_health = player1_total_health;
                player2_health = player2_total_health;
                player3_health = player3_total_health;

                enemy1_health = 800;
                enemy2_health = 900;
                enemy3_health = 1000;

                bad1 = true;
                bad2 = true;
                bad3 = true;
                bad4 = false;
                bad5 = false;
                bad6 = false;
                battle_start = false;
            }
            if (battle == 3 && battle_start == true)
            {
                player1_health = player1_total_health;
                player2_health = player2_total_health;
                player3_health = player3_total_health;

                enemy1_health = 800;
                enemy2_health = 900;
                enemy3_health = 1000;
                enemy4_health = 1100;

                bad1 = true;
                bad2 = true;
                bad3 = true;
                bad4 = true;
                bad5 = false;
                bad6 = false;
                battle_start = false;
            }
            if (battle == 4 && battle_start == true)
            {
                player1_health = player1_total_health;
                player2_health = player2_total_health;
                player3_health = player3_total_health;
                player1_magic = player1_total_magic;
                player2_magic = player2_total_magic;
                player3_magic = player3_total_magic;

                player1_attack_power = 4;
                player1_magic_power = 2;
                player2_attack_power = 2;
                player2_magic_power = 4;
                player3_attack_power = 3;
                player3_magic_power = 3;

                enemy1_health = 500;
                enemy2_health = 600;
                enemy3_health = 700;
                enemy4_health = 800;
                enemy5_health = 900;
                enemy6_health = 1000;

                bad1 = true;
                bad2 = true;
                bad3 = true;
                bad4 = true;
                bad5 = true;
                bad6 = true;
                battle_start = false;
            }
            if (battle == 5 && battle_start == true)
            {
                player1_health = player1_total_health;
                player2_health = player2_total_health;
                player3_health = player3_total_health;
                player1_magic = player1_total_magic;
                player2_magic = player2_total_magic;
                player3_magic = player3_total_magic;

                player1_item1_count = 5;
                player1_item2_count = 5;
                player1_item3_count = 5;
                player2_item1_count = 5;
                player2_item2_count = 5;
                player2_item3_count = 5;
                player3_item1_count = 5;
                player3_item2_count = 5;
                player3_item3_count = 5;


                gameplay = false;
                boss1_text = true;
            }

            //Apply the surface to the screen
            apply_surface(bgX, bgY, sky, screen );
            apply_surface( bgX + background->w, bgY, sky, screen );

            apply_surface( 0, 0, background, screen );
            apply_surface( 0, 330, command_background, screen );
            apply_surface( 50, 345, character_background, screen);
            apply_surface( 50, 385, character_background, screen);
            apply_surface( 50, 425, character_background, screen);
            apply_surface( 170, 345, health_counter, screen);
            apply_surface( 220, 345, magic_counter, screen);




            //While there's an event to handle
            while ( SDL_PollEvent( &event ) )
            {
                //If a key was pressed
                if ( event.type == SDL_KEYDOWN )
                {
                    switch ( event.key.keysym.sym )
                    {
                    case SDLK_UP:
                    {

                        //selecting the characters
                        if (arx == 15)
                        {
                            if (ary == 350)
                            {
                                if (order1 == 3 || good3 == false)
                                {
                                    if ( order2 == 2 || good2 == false)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        ary = 390;
                                        break;
                                    }
                                }
                                else
                                {
                                    ary = 430;
                                    break;
                                }
                            }
                            else if (ary == 390)
                            {
                                if (order1 == 1 || good1 == false)
                                {
                                    if (order2 == 3 || good3 == false)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        ary = 430;
                                        break;
                                    }
                                }
                                else
                                {
                                    ary = 350;
                                    break;
                                }
                            }
                            else if (ary == 430)
                            {
                                if (order1 == 2 || good2 == false)
                                {
                                    if (order2 == 1 || good1 == false)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        ary = 350;
                                        break;
                                    }
                                }
                                else
                                {
                                    ary = 390;
                                    break;
                                }
                            }
                        }
                        //this is for selecting primaries and subs
                        else if ( ary >= 350)
                        {
                            if (arx != 15 && ary != 350)
                            {
                                ary = ary - 40;
                                break;
                            }
                            else
                            {
                                ary = 430;
                                break;
                            }
                        }
                        // this is for selecting who will receive the action
                        else if (ary < 350 && arx != 140)
                        {
                            //for characters
                            if (arx == 15)
                            {
                                ary = ary - 80;
                                break;
                            }
                            //for first row bad guys if they are all present
                            if (arx == 435 && bad1 == true && bad2 == true && bad3 == true)
                            {
                                if (ary == 110)
                                {
                                    ary = 270;
                                    break;
                                }
                                else
                                {
                                    ary = ary - 80;
                                    break;
                                }
                            }
                            //for second row bad guys if they are all present
                            if (arx == 540 && bad4 == true && bad5 == true && bad6 == true)
                            {
                                if (ary == 110)
                                {
                                    ary = 270;
                                    break;
                                }
                                else
                                {
                                    ary = ary - 80;
                                    break;
                                }
                            }
                            //for first row depending on which ones are present
                            else if (arx == 435)
                            {
                                if (ary == 110)
                                {
                                    if (bad3 == false)
                                    {
                                        if (bad2 == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            ary = 190;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        ary = 270;
                                        break;
                                    }
                                }
                                if (ary == 190)
                                {
                                    if (bad1 == false)
                                    {
                                        if (bad3 == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            ary = 270;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        ary = 110;
                                        break;
                                    }
                                }
                                if (ary == 270)
                                {
                                    if (bad2 == false)
                                    {
                                        if (bad1 == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            ary = 110;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        ary = 190;
                                        break;
                                    }
                                }

                            }
                            //for the second row depending on which ones are present
                            else if (arx == 540)
                            {
                                if (ary == 110)
                                {
                                    if (bad6 == false)
                                    {
                                        if (bad5 == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            ary = 190;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        ary = 270;
                                        break;
                                    }
                                }
                                if (ary == 190)
                                {
                                    if (bad4 == false)
                                    {
                                        if (bad6 == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            ary = 270;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        ary = 110;
                                        break;
                                    }
                                }
                                if (ary == 270)
                                {
                                    if (bad5 == false)
                                    {
                                        if (bad4 == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            ary = 110;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        ary = 190;
                                        break;
                                    }
                                }

                            }
                        }
                        else if (arx == 140)
                        {
                            if (ary == 110)
                            {
                                ary = 270;
                                break;
                            }
                            else
                            {
                                ary = ary - 80;
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    case SDLK_DOWN:
                    {

                        if (arx == 15)
                        {
                            if (ary == 350)
                            {
                                if (order1 == 2 || good2 == false)
                                {
                                    if ( order2 == 3 || good3 == false)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        ary = 430;
                                    }
                                }
                                else
                                {
                                    ary = 390;
                                }
                            }
                            else if (ary == 390)
                            {
                                if (order1 == 3 || good3 == false)
                                {
                                    if (order2 == 1 || good1 == false)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        ary = 350;
                                    }
                                }
                                else
                                {
                                    ary = 430;
                                }
                            }
                            else if (ary == 430)
                            {
                                if (order1 == 1 || good1 == false)
                                {
                                    if (order2 == 2 || good2 == false)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        ary = 390;
                                    }
                                }
                                else
                                {
                                    ary = 350;
                                }
                            }
                        }
                        else if (ary >= 350)
                        {
                            if (arx != 15 && ary != 430)
                            {
                                ary = ary + 40;
                                break;
                            }
                            else
                            {
                                ary = 350;
                                break;
                            }
                        }
                        else if ( ary == 430)
                        {
                            if (order1 == 0)
                            {
                                ary = 350;
                                break;
                            }
                            else if (arx != 15)
                            {
                                ary = 350;
                                break;
                            }
                            else if (arx == 15 && order1 ==1 && order2 == 0)
                            {
                                ary = 390;
                                break;
                            }
                            else if (arx == 15 && order1 == 2 && order2 == 0)
                            {
                                ary = 350;
                                break;
                            }
                            else if (arx == 15 && order1 != 0 && order2 != 0)
                            {
                                break;
                            }
                        }
                        //this is for selecting who will receive the action
                        else if (ary < 350 && arx != 140)
                        {
                            //for characters
                            if (arx == 15)
                            {
                                ary = ary + 80;
                                break;
                            }
                            //for first row bad guys if they are all present
                            if (arx == 435 && bad1 == true && bad2 == true && bad3 == true)
                            {
                                if (ary == 270)
                                {
                                    ary = 110;
                                    break;
                                }
                                else
                                {
                                    ary = ary + 80;
                                    break;
                                }
                            }
                            //for second row bad guys if they are all present
                            if (arx == 540 && bad4 == true && bad5 == true && bad6 == true)
                            {
                                if (ary == 270)
                                {
                                    ary = 110;
                                    break;
                                }
                                else
                                {
                                    ary = ary + 80;
                                    break;
                                }
                            }
                            //for first row depending on which ones are present
                            else if (arx == 435)
                            {
                                if (ary == 110)
                                {
                                    if (bad2 == false)
                                    {
                                        if (bad3 == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            ary = 270;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        ary = 190;
                                        break;
                                    }
                                }
                                if (ary == 190)
                                {
                                    if (bad3 == false)
                                    {
                                        if (bad1 == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            ary = 110;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        ary = 270;
                                        break;
                                    }
                                }
                                if (ary == 270)
                                {
                                    if (bad1 == false)
                                    {
                                        if (bad2 == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            ary = 190;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        ary = 110;
                                        break;
                                    }
                                }
                            }
                            //for the second row depending on which ones are present
                            else if (arx == 540)
                            {
                                if (ary == 110)
                                {
                                    if (bad5 == false)
                                    {
                                        if (bad6 == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            ary = 270;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        ary = 190;
                                        break;
                                    }
                                }
                                if (ary == 190)
                                {
                                    if (bad6 == false)
                                    {
                                        if (bad4 == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            ary = 110;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        ary = 270;
                                        break;
                                    }
                                }
                                if (ary == 270)
                                {
                                    if (bad4 == false)
                                    {
                                        if (bad5 == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            ary = 190;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        ary = 110;
                                        break;
                                    }
                                }
                            }
                        }
                        else if (arx == 140)
                        {
                            if (ary == 270)
                            {
                                ary = 110;
                                break;
                            }
                            else
                            {
                                ary = ary + 80;
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    case SDLK_RIGHT:
                    {
                        //moving from first row to second row
                        if (ary < 350 && arx == 435)
                        {
                            if (ary == 110)
                            {
                                if (bad4 == true)
                                {
                                    arx = 540;
                                    ary = 110;
                                    break;
                                }
                                else if (bad5 == true)
                                {
                                    arx = 540;
                                    ary = 190;
                                    break;
                                }
                                else if (bad6 == true)
                                {
                                    arx = 540;
                                    ary = 270;
                                    break;
                                }
                                else
                                {
                                    break;
                                }
                            }
                            if (ary == 190)
                            {
                                if (bad5 == true)
                                {
                                    arx = 540;
                                    ary = 190;
                                    break;
                                }
                                else if (bad4 == true)
                                {
                                    arx = 540;
                                    ary = 110;
                                    break;
                                }
                                else if (bad6 == true)
                                {
                                    arx = 540;
                                    ary = 270;
                                    break;
                                }
                                else
                                {
                                    break;
                                }
                            }
                            if (ary == 270)
                            {
                                if (bad6 == true)
                                {
                                    arx = 540;
                                    ary = 270;
                                    break;
                                }
                                else if (bad5 == true)
                                {
                                    arx = 540;
                                    ary = 190;
                                    break;
                                }
                                else if (bad4 == true)
                                {
                                    arx = 540;
                                    ary = 110;
                                    break;
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }
                        //moving from the characters to the first or second row
                        else if (ary < 350 && arx == 140)
                        {
                            //if the first row is all there
                            if (bad1 == true && bad2 == true && bad3 == true)
                            {
                                arx = 435;
                                right = true;
                                left = false;
                                break;
                            }
                            //if the any are missing from the front row
                            else
                            {
                                if (ary == 110)
                                {
                                    if (bad1 == false)
                                    {
                                        if (bad2 == false)
                                        {
                                            if (bad3 == false)
                                            {
                                                if (bad4 == false)
                                                {
                                                    if (bad5 == false)
                                                    {
                                                        arx = 540;
                                                        ary = 270;
                                                        right = true;
                                                        left = false;
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        arx = 540;
                                                        ary = 190;
                                                        right = true;
                                                        left = false;
                                                        break;
                                                    }
                                                }
                                                else
                                                {
                                                    arx = 540;
                                                    ary = 110;
                                                    right = true;
                                                    left = false;
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                arx = 435;
                                                ary = 270;
                                                right = true;
                                                left = false;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            arx = 435;
                                            ary = 190;
                                            right = true;
                                            left = false;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        arx = 435;
                                        ary = 110;
                                        right = true;
                                        left = false;
                                        break;
                                    }
                                }
                                if (ary == 190)
                                {
                                    if (bad2 == false)
                                    {
                                        if (bad1 == false)
                                        {
                                            if (bad3 == false)
                                            {
                                                if (bad5 == false)
                                                {
                                                    if (bad4 == false)
                                                    {
                                                        arx = 540;
                                                        ary = 270;
                                                        right = true;
                                                        left = false;
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        arx = 540;
                                                        ary = 110;
                                                        right = true;
                                                        left = false;
                                                        break;
                                                    }
                                                }
                                                else
                                                {
                                                    arx = 540;
                                                    ary = 190;
                                                    right = true;
                                                    left = false;
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                arx = 435;
                                                ary = 270;
                                                right = true;
                                                left = false;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            arx = 435;
                                            ary = 110;
                                            right = true;
                                            left = false;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        arx = 435;
                                        ary = 190;
                                        right = true;
                                        left = false;
                                        break;
                                    }


                                }
                                if (ary == 270)
                                {
                                    if (bad3 == false)
                                    {
                                        if (bad2 == false)
                                        {
                                            if (bad1 == false)
                                            {
                                                if (bad6 == false)
                                                {
                                                    if (bad5 == false)
                                                    {
                                                        arx = 540;
                                                        ary = 110;
                                                        right = true;
                                                        left = false;
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        arx = 540;
                                                        ary = 190;
                                                        right = true;
                                                        left = false;
                                                        break;
                                                    }
                                                }
                                                else
                                                {
                                                    arx = 540;
                                                    ary = 270;
                                                    right = true;
                                                    left = false;
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                arx = 435;
                                                ary = 110;
                                                right = true;
                                                left = false;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            arx = 435;
                                            ary = 190;
                                            right = true;
                                            left = false;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        arx = 435;
                                        ary = 270;
                                        right = true;
                                        left = false;
                                        break;
                                    }

                                }
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    case SDLK_LEFT:
                    {
                        if (ary < 350 && arx == 540)
                        {
                            if (ary == 110)
                            {
                                if (bad1 == true)
                                {
                                    arx = 435;
                                    ary = 110;
                                    break;
                                }
                                else if (bad2 == true)
                                {
                                    arx = 435;
                                    ary = 190;
                                    break;
                                }
                                else if (bad3 == true)
                                {
                                    arx = 435;
                                    ary = 270;
                                    break;
                                }
                                else
                                {
                                    arx = 140;
                                    right = false;
                                    left = true;
                                    break;
                                }
                            }
                            if (ary == 190)
                            {
                                if (bad2 == true)
                                {
                                    arx = 435;
                                    ary = 190;
                                    break;
                                }
                                else if (bad1 == true)
                                {
                                    arx = 435;
                                    ary = 110;
                                    break;
                                }
                                else if (bad3 == true)
                                {
                                    arx = 435;
                                    ary = 270;
                                    break;
                                }
                                else
                                {
                                    arx = 140;
                                    right = false;
                                    left = true;
                                    break;
                                }
                            }
                            if (ary == 270)
                            {
                                if (bad3 == true)
                                {
                                    arx = 435;
                                    ary = 270;
                                    break;
                                }
                                else if (bad2 == true)
                                {
                                    arx = 435;
                                    ary = 190;
                                    break;
                                }
                                else if (bad1 == true)
                                {
                                    arx = 435;
                                    ary = 110;
                                    break;
                                }
                                else
                                {
                                    arx = 140;
                                    right = false;
                                    left = true;
                                    break;
                                }
                            }
                        }
                        else if ( ary < 350 && arx == 435)
                        {
                            arx = 140;
                            right = false;
                            left = true;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    case SDLK_a:
                    {
                        if (fight == false)
                        {
                            // check first for target selection
                            if ( ary < 350 )
                            {
                                if ( arx == 140 && ary == 110)
                                {
                                    choose4 = 1;
                                }
                                else if ( arx == 140 && ary == 190)
                                {
                                    choose4 = 2;
                                }
                                else if ( arx == 140 && ary == 270)
                                {
                                    choose4 = 3;
                                }
                                else if ( arx == 435 && ary == 110)
                                {
                                    choose4 = 4;
                                }
                                else if ( arx == 435 && ary == 190)
                                {
                                    choose4 = 5;
                                }
                                else if ( arx == 435 && ary == 270)
                                {
                                    choose4 = 6;
                                }
                                else if ( arx == 540 && ary == 110)
                                {
                                    choose4 = 7;
                                }
                                else if ( arx == 540 && ary == 190)
                                {
                                    choose4 = 8;
                                }
                                else if ( arx == 540 && ary == 270)
                                {
                                    choose4 = 9;
                                }

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
                                if (order1==0)
                                {
                                    order1 = choose1;
                                    if (player1_health == 0 && player2_health == 0)
                                    {
                                        good1 == false;
                                        good2 == false;
                                        fight = true;
                                    }
                                    if (player1_health == 0 && player3_health == 0)
                                    {
                                        good1 = false;
                                        good3 = false;
                                        fight = true;
                                    }
                                    if (player2_health == 0 && player3_health == 0)
                                    {
                                        good2 = false;
                                        good3 = false;
                                        fight = true;
                                    }
                                    if (order1 == 1 || good1 == false)
                                    {
                                        if (order1 == 2 || good2 == false)
                                        {
                                            arx = 15;
                                            ary = 430;
                                        }
                                        else
                                        {
                                            arx = 15;
                                            ary = 390;
                                        }
                                    }
                                    else
                                    {
                                        arx = 15;
                                        ary = 350;
                                    }

                                    right = true;
                                    left = false;
                                    choose1 = 0;
                                    choose2 = 0;
                                    choose3 = 0;
                                    choose4 = 0;
                                }
                                else if (order2==0)
                                {
                                    order2 = choose1;
                                    if (player1_health == 0)
                                    {
                                        good1 = false;
                                        fight = true;
                                    }
                                    if (player2_health == 0)
                                    {
                                        good2 = false;
                                        fight = true;
                                    }
                                    if (player3_health == 0)
                                    {
                                        good3 = false;
                                        fight = true;
                                    }
                                    if (order1 == 1 && order2 == 2)
                                    {
                                        arx = 15;
                                        ary = 430;
                                    }
                                    else if (order1 == 1 && order2 == 3)
                                    {
                                        arx = 15;
                                        ary = 390;
                                    }
                                    else if (order1 == 2 && order2 == 1)
                                    {
                                        arx = 15;
                                        ary = 430;
                                    }
                                    else if (order1 == 3 && order2 == 1)
                                    {
                                        arx = 15;
                                        ary = 390;
                                    }
                                    else
                                    {
                                        arx = 15;
                                        ary = 350;
                                    }
                                    right = true;
                                    left = false;
                                    choose1 = 0;
                                    choose2 = 0;
                                    choose3 = 0;
                                    choose4 = 0;
                                }
                                else if (order3==0)
                                {
                                    order3 = choose1;
                                    fight = true;
                                }
                            }
                            //check second for sub selection
                            else if (arx == 445)
                            {
                                if (choose2 == 2 && (player1_magic == 0 || player2_magic == 0 || player3_magic == 0))
                                {
                                    if (choose1 == 1)
                                    {
                                        if (choose2 == 2 && player1_magic == 0)
                                        {
                                            break;
                                        }

                                    }
                                    else if (choose1 == 2)
                                    {
                                        if (choose2 == 2 && player2_magic == 0)
                                        {
                                            break;
                                        }

                                    }
                                    else if (choose1 == 3)
                                    {
                                        if (choose2 == 2 && player3_magic == 0)
                                        {
                                            break;
                                        }

                                    }
                                }
                                if ((choose1 == 1 && choose2 == 3) && (player1_item1_count == 0 || player1_item2_count == 0 || player1_item3_count == 0))
                                {
                                    if (ary == 350 && player1_item1_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 390 && player1_item2_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 430 && player1_item3_count == 0)
                                    {
                                        break;
                                    }
                                }
                                else if ((choose1 == 2 && choose2 == 3) && (player2_item1_count == 0 || player2_item2_count == 0 || player2_item3_count == 0))
                                {
                                    if (ary == 350 && player2_item1_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 390 && player2_item2_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 430 && player2_item3_count == 0)
                                    {
                                        break;
                                    }
                                }
                                else if ((choose1 == 3 && choose2 == 3) &&(player3_item1_count == 0 || player3_item2_count == 0 || player3_item3_count == 0))
                                {
                                    if (ary == 350 && player3_item1_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 390 && player3_item2_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 430 && player3_item3_count == 0)
                                    {
                                        break;
                                    }
                                }
                                if ( ary == 350 )
                                {
                                    if (choose2 == 2)
                                    {
                                        choose3 = 1;
                                        if (bad1 == false)
                                        {
                                            if (bad2 == false)
                                            {
                                                if (bad3 == false)
                                                {
                                                    if (bad4 == false)
                                                    {
                                                        if (bad5 == false)
                                                        {
                                                            arx = 540;
                                                            ary = 270;
                                                            right = true;
                                                            left = false;
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            arx = 540;
                                                            ary = 190;
                                                            right = true;
                                                            left = false;
                                                            break;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        arx = 540;
                                                        ary = 110;
                                                        right = true;
                                                        left = false;
                                                        break;
                                                    }
                                                }
                                                else
                                                {
                                                    arx = 435;
                                                    ary = 270;
                                                    right = true;
                                                    left = false;
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                arx = 435;
                                                ary = 190;
                                                right = true;
                                                left = false;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            arx = 435;
                                            ary = 110;
                                            right = true;
                                            left = false;
                                            break;
                                        }
                                    }
                                    else if (choose2 == 3)
                                    {
                                        choose3 = 1;
                                        arx = 140;
                                        ary = 110;
                                        right = false;
                                        left = true;
                                        break;
                                    }
                                }
                                else if ( ary == 390 )
                                {
                                    if (choose2 == 2)
                                    {
                                        choose3 = 2;
                                        if (bad1 == false)
                                        {
                                            if (bad2 == false)
                                            {
                                                if (bad3 == false)
                                                {
                                                    if (bad4 == false)
                                                    {
                                                        if (bad5 == false)
                                                        {
                                                            arx = 540;
                                                            ary = 270;
                                                            right = true;
                                                            left = false;
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            arx = 540;
                                                            ary = 190;
                                                            right = true;
                                                            left = false;
                                                            break;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        arx = 540;
                                                        ary = 110;
                                                        right = true;
                                                        left = false;
                                                        break;
                                                    }
                                                }
                                                else
                                                {
                                                    arx = 435;
                                                    ary = 270;
                                                    right = true;
                                                    left = false;
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                arx = 435;
                                                ary = 190;
                                                right = true;
                                                left = false;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            arx = 435;
                                            ary = 110;
                                            right = true;
                                            left = false;
                                            break;
                                        }
                                    }
                                    else if (choose2 == 3)
                                    {
                                        choose3 = 2;
                                        arx = 140;
                                        ary = 110;
                                        right = false;
                                        left = true;
                                        break;
                                    }
                                }
                                else if ( ary == 430 )
                                {
                                    if (choose2 == 2)
                                    {
                                        choose3 = 3;
                                        if (bad1 == false)
                                        {
                                            if (bad2 == false)
                                            {
                                                if (bad3 == false)
                                                {
                                                    if (bad4 == false)
                                                    {
                                                        if (bad5 == false)
                                                        {
                                                            arx = 540;
                                                            ary = 270;
                                                            right = true;
                                                            left = false;
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            arx = 540;
                                                            ary = 190;
                                                            right = true;
                                                            left = false;
                                                            break;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        arx = 540;
                                                        ary = 110;
                                                        right = true;
                                                        left = false;
                                                        break;
                                                    }
                                                }
                                                else
                                                {
                                                    arx = 435;
                                                    ary = 270;
                                                    right = true;
                                                    left = false;
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                arx = 435;
                                                ary = 190;
                                                right = true;
                                                left = false;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            arx = 435;
                                            ary = 110;
                                            right = true;
                                            left = false;
                                            break;
                                        }
                                    }
                                    else if (choose2 == 3)
                                    {
                                        choose3 = 3;
                                        arx = 140;
                                        ary = 110;
                                        right = false;
                                        left = true;
                                        break;
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }

                            // check third for primary selection
                            else if (arx == 280)
                            {
                                //this one is the attack one, it is special because it has no sub selection
                                if ( ary == 350 )
                                {
                                    choose2 = 1;
                                    if (bad1 == false)
                                    {
                                        if (bad2 == false)
                                        {
                                            if (bad3 == false)
                                            {
                                                if (bad4 == false)
                                                {
                                                    if (bad5 == false)
                                                    {
                                                        arx = 540;
                                                        ary = 270;
                                                        right = true;
                                                        left = false;
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        arx = 540;
                                                        ary = 190;
                                                        right = true;
                                                        left = false;
                                                        break;
                                                    }
                                                }
                                                else
                                                {
                                                    arx = 540;
                                                    ary = 110;
                                                    right = true;
                                                    left = false;
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                arx = 435;
                                                ary = 270;
                                                right = true;
                                                left = false;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            arx = 435;
                                            ary = 190;
                                            right = true;
                                            left = false;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        arx = 435;
                                        ary = 110;
                                        right = true;
                                        left = false;
                                        break;
                                    }
                                }
                                // now back to the other options
                                else if ( ary == 390 )
                                {
                                    choose2 = 2;
                                    arx = 445;
                                    ary = 350;
                                    break;
                                }
                                else if ( ary == 430 )
                                {
                                    if (choose1 == 1)
                                    {
                                        if (play1i == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            choose2 = 3;
                                            arx = 445;
                                            ary = 350;
                                            break;
                                        }
                                    }
                                    else if (choose1 == 2)
                                    {
                                        if (play2i == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            choose2 = 3;
                                            arx = 445;
                                            ary = 350;
                                            break;
                                        }
                                    }
                                    else if (choose1 == 3)
                                    {
                                        if (play3i == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            choose2 = 3;
                                            arx = 445;
                                            ary = 350;
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }

                            // check last for character selection
                            else if (arx == 15)
                            {
                                if ( ary == 350 )
                                {
                                    choose1 = 1;
                                    ary = 350;
                                    arx = 280;
                                    break;
                                }
                                if ( ary == 390 )
                                {
                                    choose1 = 2;
                                    ary = 350;
                                    arx = 280;
                                    break;
                                }
                                if ( ary == 430 )
                                {
                                    choose1 = 3;
                                    ary = 350;
                                    arx = 280;
                                    break;
                                }
                                else
                                {
                                    break;
                                }
                            }

                            else
                            {
                                break;
                            }

                        }
                    }
                    case SDLK_s:
                    {
                        //go back and undo sub selection
                        if (ary < 350 && choose3 == 0)
                        {
                            arx = 280;
                            ary = 350;
                            choose2 = 0;
                            right = true;
                            left = false;
                            break;
                        }
                        if (ary < 350 && choose3 == 1)
                        {
                            arx = 445;
                            ary = 350;
                            choose3 = 0;
                            right = true;
                            left = false;
                            break;
                        }
                        if (ary < 350 && choose3 == 2)
                        {
                            arx = 445;
                            ary = 390;
                            choose3 = 0;
                            right = true;
                            left = false;
                            break;
                        }
                        if (ary < 350 && choose3 == 3)
                        {
                            arx = 445;
                            ary = 430;
                            choose3 = 0;
                            right = true;
                            left = false;
                            break;
                        }
                        //go back and undo primary selection
                        if ( arx == 445 && choose2 == 1)
                        {
                            arx = 280;
                            ary = 350;
                            choose2 = 0;
                            break;
                        }
                        if ( arx == 445 && choose2 == 2)
                        {
                            arx = 280;
                            ary = 390;
                            choose2 = 0;
                            break;
                        }
                        if ( arx == 445 && choose2 == 3)
                        {
                            arx = 280;
                            ary = 430;
                            choose2 = 0;
                            break;
                        }
                        //go back and undo character selection
                        if ( arx == 280 && choose1 == 1)
                        {
                            arx = 15;
                            ary = 350;
                            choose1 = 0;
                            break;
                        }
                        if ( arx == 280 && choose1 == 2)
                        {
                            arx = 15;
                            ary = 390;
                            choose1 = 0;
                            break;
                        }
                        if ( arx == 280 && choose1 == 3)
                        {
                            arx = 15;
                            ary = 430;
                            choose1 = 0;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    default:
                    {
                        break;
                    }
                    }
                }
            }
            //If the user has Xed out the window
            if ( event.type == SDL_QUIT )
            {
                //Quit the program
                gameplay = false;
            }

            if (fight == true)
            {
                if (bad1 == false && bad2 == false && bad3 == false && bad4 == false && bad5 == false && bad6 == false)
                {
                    evil = true;
                }
                if (bad1 == true || bad2 == true || bad3 == true || bad4 == true || bad5 == true || bad6 == true)
                {
                    evil = false;
                }

                if (fight_turn == 1 && evil == false)
                {
                    if (order1 == 1)
                    {
                        //if the primary choice is attack then find the target and calculate the results
                        if (player1_array[0] == 1)
                        {
                            if (player1_array[2] == 1)
                            {
                                if (player1_attack_power*50 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 2)
                            {
                                if (player1_attack_power*50 >= player2_health)
                                {
                                    player2_health = 0;
                                }
                                else
                                {
                                    player2_health = player2_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 3)
                            {
                                if (player1_attack_power*50 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 4)
                            {
                                if (player1_attack_power*50 >= enemy1_health)
                                {
                                    enemy1_health = 0;
                                    bad1 = false;
                                }
                                else
                                {
                                    enemy1_health = enemy1_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 5)
                            {
                                if (player1_attack_power*50 >= enemy2_health)
                                {
                                    enemy2_health = 0;
                                    bad2 = false;
                                }
                                else
                                {
                                    enemy2_health = enemy2_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 6)
                            {
                                if (player1_attack_power*50 >= enemy3_health)
                                {
                                    enemy3_health = 0;
                                    bad3 = false;
                                }
                                else
                                {
                                    enemy3_health = enemy3_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 7)
                            {
                                if (player1_attack_power*50 >= enemy4_health)
                                {
                                    enemy4_health = 0;
                                    bad4 = false;
                                }
                                else
                                {
                                    enemy4_health = enemy4_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 8)
                            {
                                if (player1_attack_power*50 >= enemy5_health)
                                {
                                    enemy5_health = 0;
                                    bad5 = false;
                                }
                                else
                                    enemy5_health = enemy5_health - (player1_attack_power*50);
                            }
                            else if (player1_array[2] == 9)
                            {
                                if (player1_attack_power*50 >= enemy6_health)
                                {
                                    enemy6_health = 0;
                                    bad6 = false;
                                }
                                else
                                {
                                    enemy6_health = enemy6_health - (player1_attack_power*50);
                                }
                            }
                            attack_number = player1_attack_power*50;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player1_array[0] == 2)
                        {
                            //if the magic sub selection is Rage
                            if (player1_array[1] == 1)
                            {
                                player1_magic = player1_magic - rage_magic;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_attack_power*50*rage >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player1_attack_power*50*rage >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player1_attack_power*50*rage >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 4)
                                {
                                    if (player1_attack_power*50*rage >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (player1_attack_power*50*rage >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 6)
                                {
                                    if (player1_attack_power*50*rage >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 7)
                                {
                                    if (player1_attack_power*50*rage >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 8)
                                {
                                    if (player1_attack_power*50*rage >= enemy1_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                    {
                                        enemy5_health = enemy5_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 9)
                                {
                                    if (player1_attack_power*50*rage >= enemy1_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health -(player1_attack_power*50*rage);
                                    }
                                }
                                attack_number = player1_attack_power*50*rage;
                            }
                            //if the magic sub selection is Burn
                            if (player1_array[1] == 2)
                            {
                                player1_magic = player1_magic - burn_magic;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player1_magic_power*50 >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player1_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 4)
                                {
                                    if (player1_magic_power*50*burn >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (player1_magic_power*50*burn);
                                    }
                                    attack_number = player1_magic_power*50*burn;
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (player1_magic_power*50 >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 6)
                                {
                                    if (player1_magic_power*50 >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 7)
                                {
                                    if (player1_magic_power*50*burn >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (player1_magic_power*50*burn);
                                    }
                                    attack_number = player1_magic_power*50*burn;
                                }
                                else if (player1_array[2] == 8)
                                {
                                    if (player1_magic_power*50 >= enemy5_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                        enemy5_health = enemy5_health - (player1_magic_power*50);
                                }
                                else if (player1_array[2] == 9)
                                {
                                    if (player1_magic_power*50 >= enemy6_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (player1_magic_power*50);
                                    }
                                }
                                if (player1_array[2] != 4 && player1_array[2] != 7)
                                {
                                    attack_number = player1_magic_power*50;
                                }
                            }
                            //if the magic sub selection is LIMIT
                            else if (player1_array[1] == 3)
                            {
                                limit1_power = player1_magic;
                                player1_magic = 0;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player2_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 4)
                                {
                                    if (enemy1_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (enemy2_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 6)
                                {
                                    if (enemy3_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 7)
                                {
                                    if (enemy4_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 8)
                                {
                                    if (enemy5_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                    {
                                        enemy5_health = enemy5_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 9)
                                {
                                    if (enemy6_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                attack_number = limit1_power*player1_attack_power*player1_magic_power;
                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player1_array[0] == 3)
                        {
                            //if the item sub selection is spirit
                            if (player1_array[1] == 1)
                            {
                                player1_item1_count = player1_item1_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player1_health+spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player2_health+spirit > player2_total_health)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                    {
                                        player2_health = player2_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player3_health+spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 4)
                                {
                                    enemy1_health = enemy1_health + spirit;
                                }
                                else if (player1_array[2] == 5)
                                {
                                    enemy2_health = enemy2_health + spirit;
                                }
                                else if (player1_array[2] == 6)
                                {
                                    enemy3_health = enemy3_health + spirit;
                                }
                                else if (player1_array[2] == 7)
                                {
                                    enemy4_health = enemy4_health + spirit;
                                }
                                else if (player1_array[2] == 8)
                                {
                                    enemy5_health = enemy5_health + spirit;
                                }
                                else if (player1_array[2] == 9)
                                {
                                    enemy6_health = enemy6_health + spirit;
                                }
                            }
                            //if the item sub selection is hi-spirit
                            if (player1_array[1] == 2)
                            {
                                player1_item2_count = player1_item2_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player1_health+hi_spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player2_health+hi_spirit > player2_total_health)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                    {
                                        player2_health = player2_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player3_health+hi_spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 4)
                                {
                                    enemy1_health = enemy1_health + hi_spirit;
                                }
                                else if (player1_array[2] == 5)
                                {
                                    enemy2_health = enemy2_health + hi_spirit;
                                }
                                else if (player1_array[2] == 6)
                                {
                                    enemy3_health = enemy3_health + hi_spirit;
                                }
                                else if (player1_array[2] == 7)
                                {
                                    enemy4_health = enemy4_health + hi_spirit;
                                }
                                else if (player1_array[2] == 8)
                                {
                                    enemy5_health = enemy5_health + hi_spirit;
                                }
                                else if (player1_array[2] == 9)
                                {
                                    enemy6_health = enemy6_health + hi_spirit;
                                }
                            }
                            //if the item sub selection is lazarus
                            if (player1_array[1] ==3)
                            {
                                player1_item3_count = player1_item3_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 4)
                                    {}
                                else if (player1_array[2] == 5)
                                    {}
                                else if (player1_array[2] == 6)
                                    {}
                                else if (player1_array[2] == 7)
                                    {}
                                else if (player1_array[2] == 8)
                                    {}
                                else if (player1_array[2] == 9)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );

                        char1x = 65;
                        char2x = 15;
                        char3x = 15;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);


                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stab, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player2_health != 0)
                        {
                            apply_surface( char2x, char2y, mage_stance, screen);
                        }
                        else
                        {
                            apply_surface( char2x, char2y, mage_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_stance, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }


                        apply_surface( 200, 150, attack_number_text, screen );
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

                        // show the enemies
                        if (bad1 == true)
                        {
                            apply_surface( ene1x, ene1y, enemy1, screen);
                            apply_surface( 420, 160, enemy1_health_text, screen);
                        }
                        if (bad2 == true)
                        {
                            apply_surface( ene2x, ene2y, enemy2, screen);
                            apply_surface( 420, 240, enemy2_health_text, screen);
                        }
                        if (bad3 == true)
                        {
                            apply_surface( ene3x, ene3y, enemy3, screen);
                            apply_surface( 420, 300, enemy3_health_text, screen);
                        }
                        if (bad4 == true)
                        {
                            apply_surface( ene4x, ene4y, enemy4, screen);
                            apply_surface( 530, 160, enemy4_health_text, screen);
                        }
                        if (bad5 == true)
                        {
                            apply_surface( ene5x, ene5y, enemy5, screen);
                            apply_surface( 530, 240, enemy5_health_text, screen);
                        }
                        if (bad6 == true)
                        {
                            apply_surface( ene6x, ene6y, enemy6, screen);
                            apply_surface( 530, 300, enemy6_health_text, screen);
                        }

                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char1x = 15;

                    }
                    else if (order1 == 2)
                    {
                        char2x = 65;
                        //the animations will go right here
                        //if the primary choice is attack then find the target and calculate the results
                        if (player2_array[0] == 1)
                        {
                            if (player2_array[2] == 1)
                            {
                                if (player2_attack_power*30 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 2)
                            {
                                if (player2_attack_power*30 >= player2_health)
                                {
                                    player2_health = 0;
                                }
                                else
                                {
                                    player2_health = player2_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 3)
                            {
                                if (player2_attack_power*30 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 4)
                            {
                                if (player2_attack_power*30 >= enemy1_health)
                                {
                                    enemy1_health = 0;
                                    bad1 = false;
                                }
                                else
                                {
                                    enemy1_health = enemy1_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 5)
                            {
                                if (player2_attack_power*30 >= enemy2_health)
                                {
                                    enemy2_health = 0;
                                    bad2 = false;
                                }
                                else
                                {
                                    enemy2_health = enemy2_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 6)
                            {
                                if (player2_attack_power*30 >= enemy3_health)
                                {
                                    enemy3_health = 0;
                                    bad3 = false;
                                }
                                else
                                {
                                    enemy3_health = enemy3_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 7)
                            {
                                if (player2_attack_power*30 >= enemy4_health)
                                {
                                    enemy4_health = 0;
                                    bad4 = false;
                                }
                                else
                                {
                                    enemy4_health = enemy4_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 8)
                            {
                                if (player2_attack_power*30 >= enemy5_health)
                                {
                                    enemy5_health = 0;
                                    bad5 = false;
                                }
                                else
                                    enemy5_health = enemy5_health - (player2_attack_power*30);
                            }
                            else if (player2_array[2] == 9)
                            {
                                if (player2_attack_power*30 >= enemy6_health)
                                {
                                    enemy6_health = 0;
                                    bad6 = false;
                                }
                                else
                                {
                                    enemy6_health = enemy6_health - (player2_attack_power*30);
                                }
                            }
                            attack_number = player2_attack_power*30;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player2_array[0] == 2)
                        {
                            //if the magic sub selection is Burn
                            if (player2_array[1] == 1)
                            {
                                player2_magic = player2_magic - burn_magic;

                                if (player2_array[2] == 1)
                                {
                                    if (player2_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_magic_power*50 >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player2_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 4)
                                {
                                    if (player2_magic_power*50*burn >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (player2_magic_power*50*burn);
                                    }
                                    attack_number = player2_magic_power*50*burn;
                                }
                                else if (player2_array[2] == 5)
                                {
                                    if (player2_magic_power*50 >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 6)
                                {
                                    if (player2_magic_power*50 >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 7)
                                {
                                    if (player2_magic_power*50*burn >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (player2_magic_power*50*burn);
                                    }
                                    attack_number = player2_magic_power*50*burn;
                                }
                                else if (player2_array[2] == 8)
                                {
                                    if (player2_magic_power*50 >= enemy5_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                        enemy5_health = enemy5_health - (player2_magic_power*50);
                                }
                                else if (player2_array[2] == 9)
                                {
                                    if (player2_magic_power*50 >= enemy6_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (player2_magic_power*50);
                                    }
                                }
                                if (player2_array[2] != 4 && player2_array[2] != 7)
                                {
                                    attack_number = player2_magic_power*50;
                                }
                            }
                            //if the magic sub selection is Freeze
                            else if (player2_array[1] == 2)
                            {
                                player2_magic = player2_magic - freeze_magic;

                                if (player2_array[2] == 1)
                                {
                                    if (player2_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_magic_power*50 >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player2_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 4)
                                {
                                    if (player2_magic_power*50 >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 5)
                                {
                                    if (player2_magic_power*50*freeze >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (player2_magic_power*50*freeze);
                                    }
                                    attack_number = player2_magic_power*50*freeze;
                                }
                                else if (player2_array[2] == 6)
                                {
                                    if (player2_magic_power*50 >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 7)
                                {
                                    if (player2_magic_power*50 >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 8)
                                {
                                    if (player2_magic_power*50*freeze >= enemy5_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                        enemy5_health = enemy5_health - (player2_magic_power*50*freeze);
                                    attack_number = player2_magic_power*50*freeze;
                                }
                                else if (player2_array[2] == 9)
                                {
                                    if (player2_magic_power*50 >= enemy6_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (player2_magic_power*50);
                                    }
                                }
                                if (player2_array[2] != 5 && player2_array[2]  != 8)
                                {
                                    attack_number = player2_magic_power*50;
                                }
                            }
                            //if the magic sub selection is LIMIT
                            else if (player2_array[1] == 3)
                            {
                                limit2_power = player2_magic;
                                player2_magic = 0;

                                if (player2_array[2] == 1)
                                {
                                    if (player1_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player3_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 4)
                                {
                                    if (enemy1_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 5)
                                {
                                    if (enemy2_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 6)
                                {
                                    if (enemy3_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 7)
                                {
                                    if (enemy4_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 8)
                                {
                                    if (enemy5_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                    {
                                        enemy5_health = enemy5_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 9)
                                {
                                    if (enemy6_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                attack_number = limit2_power*player2_attack_power*player2_magic_power;

                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player2_array[0] == 3)
                        {
                            //if the item sub selection is ether
                            if (player2_array[1] == 1)
                            {
                                player2_item1_count = player2_item1_count - 1;

                                if (player2_array[2] == 1)
                                {
                                    if (player1_magic+ether > player1_total_magic)
                                    {
                                        player1_magic = player1_total_magic;
                                    }
                                    else
                                    {
                                        player1_magic = player1_magic + ether;
                                    }
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_magic+ether > player2_total_magic)
                                    {
                                        player2_magic = player2_total_magic;
                                    }
                                    else
                                    {
                                        player2_magic = player2_magic + ether;
                                    }
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player3_magic+ether > player3_total_magic)
                                    {
                                        player3_magic = player3_total_magic;
                                    }
                                    else
                                    {
                                        player3_magic = player3_magic + ether;
                                    }
                                }
                                else if (player2_array[2] == 4)
                                    {}
                                else if (player2_array[2] == 5)
                                    {}
                                else if (player2_array[2] == 6)
                                    {}
                                else if (player2_array[2] == 7)
                                    {}
                                else if (player2_array[2] == 8)
                                    {}
                                else if (player2_array[2] == 9)
                                    {}
                            }
                            //if the item sub selection is hi-ether
                            if (player2_array[1] == 2)
                            {
                                player2_item2_count = player1_item2_count - 1;

                                if (player2_array[2] == 1)
                                {
                                    if (player1_magic+hi_ether > player1_total_magic)
                                    {
                                        player1_magic = player1_total_magic;
                                    }
                                    else
                                    {
                                        player1_magic = player1_magic + hi_ether;
                                    }
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_magic+hi_ether > player2_total_magic)
                                    {
                                        player2_magic = player2_total_magic;
                                    }
                                    else
                                    {
                                        player2_magic = player2_magic + hi_ether;
                                    }
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player3_magic+hi_ether > player3_total_magic)
                                    {
                                        player3_magic = player3_total_magic;
                                    }
                                    else
                                    {
                                        player3_magic = player3_magic + hi_ether;
                                    }
                                }
                                else if (player2_array[2] == 4)
                                {

                                }
                                else if (player2_array[2] == 5)
                                {

                                }
                                else if (player2_array[2] == 6)
                                {

                                }
                                else if (player2_array[2] == 7)
                                {

                                }
                                else if (player2_array[2] == 8)
                                    {}
                                else if (player2_array[2] == 9)
                                    {}
                            }
                            //if the item sub selection is lazarus
                            if (player2_array[1] ==3)
                            {
                                player2_item3_count = player2_item3_count - 1;

                                if (player2_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player2_array[2] == 4)
                                    {}
                                else if (player2_array[2] == 5)
                                    {}
                                else if (player2_array[2] == 6)
                                    {}
                                else if (player2_array[2] == 7)
                                    {}
                                else if (player2_array[2] == 8)
                                    {}
                                else if (player2_array[2] == 9)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );

                        char1x = 15;
                        char2x = 65;
                        char3x = 15;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stance, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player2_health != 0)
                        {
                            apply_surface( char2x, char2y, mage_stab, screen);
                        }
                        else
                        {
                            apply_surface( char2x, char2y, mage_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_stance, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        apply_surface( 200, 220, attack_number_text, screen );
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

                        // show the enemies
                        if (bad1 == true)
                        {
                            apply_surface( ene1x, ene1y, enemy1, screen);
                            apply_surface( 420, 160, enemy1_health_text, screen);
                        }
                        if (bad2 == true)
                        {
                            apply_surface( ene2x, ene2y, enemy2, screen);
                            apply_surface( 420, 240, enemy2_health_text, screen);
                        }
                        if (bad3 == true)
                        {
                            apply_surface( ene3x, ene3y, enemy3, screen);
                            apply_surface( 420, 300, enemy3_health_text, screen);
                        }
                        if (bad4 == true)
                        {
                            apply_surface( ene4x, ene4y, enemy4, screen);
                            apply_surface( 530, 160, enemy4_health_text, screen);
                        }
                        if (bad5 == true)
                        {
                            apply_surface( ene5x, ene5y, enemy5, screen);
                            apply_surface( 530, 240, enemy5_health_text, screen);
                        }
                        if (bad6 == true)
                        {
                            apply_surface( ene6x, ene6y, enemy6, screen);
                            apply_surface( 530, 300, enemy6_health_text, screen);
                        }

                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char1x = 15;


                    }
                    else if (order1 == 3)
                    {
                        char3x = 65;
                        //the animations will go right here
                        //if the primary choice is attack then find the target and calculate the results
                        if (player3_array[0] == 1)
                        {
                            if (player3_array[2] == 1)
                            {
                                if (player3_attack_power*40 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 2)
                            {
                                if (player3_attack_power*40 >= player2_health)
                                {
                                    player2_health = 0;
                                }
                                else
                                {
                                    player2_health = player2_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 3)
                            {
                                if (player3_attack_power*40 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 4)
                            {
                                if (player3_attack_power*40 >= enemy1_health)
                                {
                                    enemy1_health = 0;
                                    bad1 = false;
                                }
                                else
                                {
                                    enemy1_health = enemy1_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 5)
                            {
                                if (player3_attack_power*40 >= enemy2_health)
                                {
                                    enemy2_health = 0;
                                    bad2 = false;
                                }
                                else
                                {
                                    enemy2_health = enemy2_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 6)
                            {
                                if (player3_attack_power*40 >= enemy3_health)
                                {
                                    enemy3_health = 0;
                                    bad3 = false;
                                }
                                else
                                {
                                    enemy3_health = enemy3_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 7)
                            {
                                if (player3_attack_power*40 >= enemy4_health)
                                {
                                    enemy4_health = 0;
                                    bad4 = false;
                                }
                                else
                                {
                                    enemy4_health = enemy4_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 8)
                            {
                                if (player3_attack_power*40 >= enemy5_health)
                                {
                                    enemy5_health = 0;
                                    bad5 = false;
                                }
                                else
                                    enemy5_health = enemy5_health - (player3_attack_power*40);
                            }
                            else if (player3_array[2] == 9)
                            {
                                if (player3_attack_power*40 >= enemy6_health)
                                {
                                    enemy6_health = 0;
                                    bad6 = false;
                                }
                                else
                                {
                                    enemy6_health = enemy6_health - (player3_attack_power*40);
                                }
                            }
                            attack_number = player3_attack_power*40;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player3_array[0] == 2)
                        {
                            //if the magic sub selection is Freeze
                            if (player3_array[1] == 1)
                            {
                                player3_magic = player3_magic - freeze_magic;

                                if (player3_array[2] == 1)
                                {
                                    if (player3_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player3_magic_power*50 >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    if (player3_magic_power*50 >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 5)
                                {
                                    if (player3_magic_power*50*freeze >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (player3_magic_power*50*freeze);
                                    }
                                    attack_number = player3_magic_power*50*freeze;
                                }
                                else if (player3_array[2] == 6)
                                {
                                    if (player3_magic_power*50 >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 7)
                                {
                                    if (player3_magic_power*50 >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 8)
                                {
                                    if (player3_magic_power*50*freeze >= enemy5_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                        enemy5_health = enemy5_health - (player3_magic_power*50*freeze);
                                    attack_number = player3_magic_power*50*freeze;
                                }
                                else if (player3_array[2] == 9)
                                {
                                    if (player3_magic_power*50 >= enemy6_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (player3_magic_power*50);
                                    }
                                }
                                if (player3_array[2] != 5 && player3_array[2] != 8)
                                {
                                    attack_number = player3_magic_power*50;
                                }
                            }
                            //if the magic sub selection is Power X2
                            else if (player3_array[1] == 2)
                            {
                                player3_magic = player3_magic - power_magic;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player1_attack_power = player1_attack_power*2;
                                    }
                                }
                                else  if (player3_array[2] == 2)
                                {
                                    if (player2_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player2_attack_power = player2_attack_power*2;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player3_attack_power = player3_attack_power*2;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                                attack_number = 0;

                            }
                            //if the magic sub selection is LIMIT
                            else if (player3_array[1] == 3)
                            {
                                limit3_power = player3_magic;
                                player3_magic = 0;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    if (enemy1_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 5)
                                {
                                    if (enemy2_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 6)
                                {
                                    if (enemy3_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 7)
                                {
                                    if (enemy4_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 8)
                                {
                                    if (enemy5_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                    {
                                        enemy5_health = enemy5_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 9)
                                {
                                    if (enemy6_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                attack_number = limit3_power*player3_attack_power*player3_magic_power;
                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player3_array[0] == 3)
                        {
                            //if the item sub selection is hi-spirit
                            if (player3_array[1] == 1)
                            {
                                player3_item1_count = player3_item1_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health+hi_spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health+hi_spirit > player2_total_health)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                    {
                                        player2_health = player2_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health+hi_spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    enemy1_health = enemy1_health + hi_spirit;
                                }
                                else if (player3_array[2] == 5)
                                {
                                    enemy2_health = enemy2_health + hi_spirit;
                                }
                                else if (player3_array[2] == 6)
                                {
                                    enemy3_health = enemy3_health + hi_spirit;
                                }
                                else if (player3_array[2] == 7)
                                {
                                    enemy4_health = enemy4_health + hi_spirit;
                                }
                                else if (player3_array[2] == 8)
                                {
                                    enemy5_health = enemy5_health + hi_spirit;
                                }
                                else if (player3_array[2] == 9)
                                {
                                    enemy6_health = enemy6_health + hi_spirit;
                                }
                            }
                            //use this for the hi-ether
                            if (player3_array[1] == 2)
                            {
                                player3_item2_count = player3_item2_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_magic+hi_ether > player1_total_magic)
                                    {
                                        player1_magic = player1_total_magic;
                                    }
                                    else
                                    {
                                        player1_magic = player1_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_magic+hi_ether > player2_total_magic)
                                    {
                                        player2_magic = player2_total_magic;
                                    }
                                    else
                                    {
                                        player2_magic = player2_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_magic+hi_ether > player3_total_magic)
                                    {
                                        player3_magic = player3_total_magic;
                                    }
                                    else
                                    {
                                        player3_magic = player3_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                            }
                            //if the item sub selection is lazarus
                            if (player3_array[1] ==3)
                            {
                                player3_item3_count = player3_item3_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );

                        char1x = 15;
                        char2x = 15;
                        char3x = 65;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stance, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player2_health != 0)
                        {
                            apply_surface( char2x, char2y, mage_stance, screen);
                        }
                        else
                        {
                            apply_surface( char2x, char2y, mage_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_shoot, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        apply_surface( 200, 290, attack_number_text, screen );
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

                        // show the enemies
                        if (bad1 == true)
                        {
                            apply_surface( ene1x, ene1y, enemy1, screen);
                            apply_surface( 420, 160, enemy1_health_text, screen);
                        }
                        if (bad2 == true)
                        {
                            apply_surface( ene2x, ene2y, enemy2, screen);
                            apply_surface( 420, 240, enemy2_health_text, screen);
                        }
                        if (bad3 == true)
                        {
                            apply_surface( ene3x, ene3y, enemy3, screen);
                            apply_surface( 420, 300, enemy3_health_text, screen);
                        }
                        if (bad4 == true)
                        {
                            apply_surface( ene4x, ene4y, enemy4, screen);
                            apply_surface( 530, 160, enemy4_health_text, screen);
                        }
                        if (bad5 == true)
                        {
                            apply_surface( ene5x, ene5y, enemy5, screen);
                            apply_surface( 530, 240, enemy5_health_text, screen);
                        }
                        if (bad6 == true)
                        {
                            apply_surface( ene6x, ene6y, enemy6, screen);
                            apply_surface( 530, 300, enemy6_health_text, screen);
                        }

                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char3x = 15;

                    }
                }
                else if (fight_turn == 2)
                {
                    if (bad1 == true)
                    {
                        if (good1 == true && good2 == true && good3 == true)
                        {
                            enemy_random = 1 + rand() % 3;
                        }
                        else if (good1 == false)
                        {
                            if (good2 == false)
                            {
                                enemy_random = 3;
                            }
                            else if (good3 == false)
                            {
                                enemy_random = 2;
                            }
                            else
                            {
                                enemy_random = 2 + rand() %2;
                            }
                        }
                        else
                        {
                            if (good2 == false)
                            {
                                if (good3 == true)
                                {
                                    if (1+rand()%2 == 1)
                                    {
                                        enemy_random = 1;
                                    }
                                    else
                                    {
                                        enemy_random = 3;
                                    }
                                }
                                else
                                {
                                    enemy_random =1;
                                }
                            }
                            else
                            {
                                if (good3 == false)
                                {
                                    enemy_random = 1 + rand()%2;
                                }
                            }
                        }

                        if (enemy_random == 1)
                        {
                            if (enemy1_attack*30 > player1_health)
                            {
                                player1_health = 0;
                            }
                            else
                            {
                                player1_health = player1_health - enemy1_attack*30;
                            }
                        }
                        else if (enemy_random == 2)
                        {
                            if (enemy1_attack*30 > player2_health)
                            {
                                player2_health = 0;
                            }
                            else
                            {
                                player2_health = player2_health - enemy1_attack*30;
                            }
                        }
                        else if (enemy_random == 3)
                        {
                            if (enemy1_attack*30 > player3_health)
                            {
                                player3_health = 0;
                            }
                            else
                            {
                                player3_health = player3_health - enemy1_attack*30;
                            }
                        }
                        attack_number = enemy1_attack*30;
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), alertColor );

                        char1x = 15;
                        char2x = 15;
                        char3x = 15;
                        ene1x = 320;
                        ene2x = 440;
                        ene3x = 440;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stance, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }
                        if (player2_health != 0)
                        {
                            apply_surface( char2x, char2y, mage_stance, screen);
                        }
                        else
                        {
                            apply_surface( char2x, char2y, mage_dead, screen);
                        }
                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_stance, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        if (enemy_random == 1)
                        {
                            apply_surface( 150, 140, attack_number_text, screen );
                        }
                        else if (enemy_random == 2)
                        {
                            apply_surface( 150, 210, attack_number_text, screen );
                        }
                        else if (enemy_random == 3)
                        {
                            apply_surface( 150, 290, attack_number_text, screen );
                        }

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

                        // show the enemies
                        if (bad1 == true)
                        {
                            apply_surface( ene1x, ene1y, enemy1, screen);
                            apply_surface( 420, 160, enemy1_health_text, screen);
                        }
                        if (bad2 == true)
                        {
                            apply_surface( ene2x, ene2y, enemy2, screen);
                            apply_surface( 420, 240, enemy2_health_text, screen);
                        }
                        if (bad3 == true)
                        {
                            apply_surface( ene3x, ene3y, enemy3, screen);
                            apply_surface( 420, 300, enemy3_health_text, screen);
                        }
                        if (bad4 == true)
                        {
                            apply_surface( ene4x, ene4y, enemy4, screen);
                            apply_surface( 530, 160, enemy4_health_text, screen);
                        }
                        if (bad5 == true)
                        {
                            apply_surface( ene5x, ene5y, enemy5, screen);
                            apply_surface( 530, 240, enemy5_health_text, screen);
                        }
                        if (bad6 == true)
                        {
                            apply_surface( ene6x, ene6y, enemy6, screen);
                            apply_surface( 530, 300, enemy6_health_text, screen);
                        }

                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        ene1x = 440;
                    }
                }
                else if (fight_turn == 3)
                {
                    if (bad2 == true)
                    {
                        if (good1 == true && good2 == true && good3 == true)
                        {
                            enemy_random = 1 + rand() % 3;
                        }
                        else if (good1 == false)
                        {
                            if (good2 == false)
                            {
                                enemy_random = 3;
                            }
                            else if (good3 == false)
                            {
                                enemy_random = 2;
                            }
                            else
                            {
                                enemy_random = 2 + rand() %2;
                            }
                        }
                        else
                        {
                            if (good2 == false)
                            {
                                if (good3 == true)
                                {
                                    if (1+rand()%2 == 1)
                                    {
                                        enemy_random = 1;
                                    }
                                    else
                                    {
                                        enemy_random = 3;
                                    }
                                }
                                else
                                {
                                    enemy_random =1;
                                }
                            }
                            else
                            {
                                if (good3 == false)
                                {
                                    enemy_random = 1 + rand()%2;
                                }
                            }
                        }

                        if (enemy_random == 1)
                        {
                            if (enemy2_attack*30 > player1_health)
                            {
                                player1_health = 0;
                            }
                            else
                            {
                                player1_health = player1_health - enemy1_attack*30;
                            }
                        }
                        else if (enemy_random == 2)
                        {
                            if (enemy2_attack*30 > player2_health)
                            {
                                player2_health = 0;
                            }
                            else
                            {
                                player2_health = player2_health - enemy1_attack*30;
                            }
                        }
                        else if (enemy_random == 3)
                        {
                            if (enemy2_attack*30 > player3_health)
                            {
                                player3_health = 0;
                            }
                            else
                            {
                                player3_health = player3_health - enemy1_attack*30;
                            }
                        }
                        //insert enemy2 animation
                        attack_number = enemy2_attack*30;
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), alertColor );

                        char1x = 15;
                        char2x = 15;
                        char3x = 15;
                        ene1x = 440;
                        ene2x = 320;
                        ene3x = 440;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stance, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }
                        if (player2_health != 0)
                        {
                            apply_surface( char2x, char2y, mage_stance, screen);
                        }
                        else
                        {
                            apply_surface( char2x, char2y, mage_dead, screen);
                        }
                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_stance, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        if (enemy_random == 1)
                        {
                            apply_surface( 150, 140, attack_number_text, screen );
                        }
                        else if (enemy_random == 2)
                        {
                            apply_surface( 150, 210, attack_number_text, screen );
                        }
                        else if (enemy_random == 3)
                        {
                            apply_surface( 150, 290, attack_number_text, screen );
                        }

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

                        // show the enemies
                        if (bad1 == true)
                        {
                            apply_surface( ene1x, ene1y, enemy1, screen);
                            apply_surface( 420, 160, enemy1_health_text, screen);
                        }
                        if (bad2 == true)
                        {
                            apply_surface( ene2x, ene2y, enemy2, screen);
                            apply_surface( 420, 240, enemy2_health_text, screen);
                        }
                        if (bad3 == true)
                        {
                            apply_surface( ene3x, ene3y, enemy3, screen);
                            apply_surface( 420, 300, enemy3_health_text, screen);
                        }
                        if (bad4 == true)
                        {
                            apply_surface( ene4x, ene4y, enemy4, screen);
                            apply_surface( 530, 160, enemy4_health_text, screen);
                        }
                        if (bad5 == true)
                        {
                            apply_surface( ene5x, ene5y, enemy5, screen);
                            apply_surface( 530, 240, enemy5_health_text, screen);
                        }
                        if (bad6 == true)
                        {
                            apply_surface( ene6x, ene6y, enemy6, screen);
                            apply_surface( 530, 300, enemy6_health_text, screen);
                        }

                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        ene2x = 440;
                    }
                }
                else if (fight_turn == 4 && evil == false)
                {
                    if (order2 == 1 && good1 == true)
                    {
                        //if the primary choice is attack then find the target and calculate the results
                        if (player1_array[0] == 1)
                        {
                            if (player1_array[2] == 1)
                            {
                                if (player1_attack_power*50 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 2)
                            {
                                if (player1_attack_power*50 >= player2_health)
                                {
                                    player2_health = 0;
                                }
                                else
                                {
                                    player2_health = player2_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 3)
                            {
                                if (player1_attack_power*50 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 4)
                            {
                                if (player1_attack_power*50 >= enemy1_health)
                                {
                                    enemy1_health = 0;
                                    bad1 = false;
                                }
                                else
                                {
                                    enemy1_health = enemy1_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 5)
                            {
                                if (player1_attack_power*50 >= enemy2_health)
                                {
                                    enemy2_health = 0;
                                    bad2 = false;
                                }
                                else
                                {
                                    enemy2_health = enemy2_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 6)
                            {
                                if (player1_attack_power*50 >= enemy3_health)
                                {
                                    enemy3_health = 0;
                                    bad3 = false;
                                }
                                else
                                {
                                    enemy3_health = enemy3_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 7)
                            {
                                if (player1_attack_power*50 >= enemy4_health)
                                {
                                    enemy4_health = 0;
                                    bad4 = false;
                                }
                                else
                                {
                                    enemy4_health = enemy4_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 8)
                            {
                                if (player1_attack_power*50 >= enemy5_health)
                                {
                                    enemy5_health = 0;
                                    bad5 = false;
                                }
                                else
                                    enemy5_health = enemy5_health - (player1_attack_power*50);
                            }
                            else if (player1_array[2] == 9)
                            {
                                if (player1_attack_power*50 >= enemy6_health)
                                {
                                    enemy6_health = 0;
                                    bad6 = false;
                                }
                                else
                                {
                                    enemy6_health = enemy6_health - (player1_attack_power*50);
                                }
                            }
                            attack_number = player1_attack_power*50;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player1_array[0] == 2)
                        {
                            //if the magic sub selection is Rage
                            if (player1_array[1] == 1)
                            {
                                player1_magic = player1_magic - rage_magic;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_attack_power*50*rage >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player1_attack_power*50*rage >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player1_attack_power*50*rage >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 4)
                                {
                                    if (player1_attack_power*50*rage >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (player1_attack_power*50*rage >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 6)
                                {
                                    if (player1_attack_power*50*rage >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 7)
                                {
                                    if (player1_attack_power*50*rage >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 8)
                                {
                                    if (player1_attack_power*50*rage >= enemy1_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                    {
                                        enemy5_health = enemy5_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 9)
                                {
                                    if (player1_attack_power*50*rage >= enemy1_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health -(player1_attack_power*50*rage);
                                    }
                                }
                                attack_number = player1_attack_power*50*rage;
                            }
                            //if the magic sub selection is Burn
                            if (player1_array[1] == 2)
                            {
                                player1_magic = player1_magic - burn_magic;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player1_magic_power*50 >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player1_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 4)
                                {
                                    if (player1_magic_power*50*burn >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (player1_magic_power*50*burn);
                                    }
                                    attack_number = player1_magic_power*50*burn;
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (player1_magic_power*50 >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 6)
                                {
                                    if (player1_magic_power*50 >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 7)
                                {
                                    if (player1_magic_power*50*burn >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (player1_magic_power*50*burn);
                                    }
                                    attack_number = player1_magic_power*50*burn;
                                }
                                else if (player1_array[2] == 8)
                                {
                                    if (player1_magic_power*50 >= enemy5_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                        enemy5_health = enemy5_health - (player1_magic_power*50);
                                }
                                else if (player1_array[2] == 9)
                                {
                                    if (player1_magic_power*50 >= enemy6_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (player1_magic_power*50);
                                    }
                                }
                                if (player1_array[2] != 4 && player1_array[2] != 7)
                                {
                                    attack_number = player1_magic_power*50;
                                }
                            }
                            //if the magic sub selection is LIMIT
                            else if (player1_array[1] == 3)
                            {
                                limit1_power = player1_magic;
                                player1_magic = 0;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player2_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 4)
                                {
                                    if (enemy1_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (enemy2_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 6)
                                {
                                    if (enemy3_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 7)
                                {
                                    if (enemy4_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 8)
                                {
                                    if (enemy5_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                    {
                                        enemy5_health = enemy5_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 9)
                                {
                                    if (enemy6_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                attack_number = limit1_power*player1_attack_power*player1_magic_power;
                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player1_array[0] == 3)
                        {
                            //if the item sub selection is spirit
                            if (player1_array[1] == 1)
                            {
                                player1_item1_count = player1_item1_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player1_health+spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player2_health+spirit > player2_total_health)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                    {
                                        player2_health = player2_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player3_health+spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 4)
                                {
                                    enemy1_health = enemy1_health + spirit;
                                }
                                else if (player1_array[2] == 5)
                                {
                                    enemy2_health = enemy2_health + spirit;
                                }
                                else if (player1_array[2] == 6)
                                {
                                    enemy3_health = enemy3_health + spirit;
                                }
                                else if (player1_array[2] == 7)
                                {
                                    enemy4_health = enemy4_health + spirit;
                                }
                                else if (player1_array[2] == 8)
                                {
                                    enemy5_health = enemy5_health + spirit;
                                }
                                else if (player1_array[2] == 9)
                                {
                                    enemy6_health = enemy6_health + spirit;
                                }
                            }
                            //if the item sub selection is hi-spirit
                            if (player1_array[1] == 2)
                            {
                                player1_item2_count = player1_item2_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player1_health+hi_spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player2_health+hi_spirit > player2_total_health)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                    {
                                        player2_health = player2_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player3_health+hi_spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 4)
                                {
                                    enemy1_health = enemy1_health + hi_spirit;
                                }
                                else if (player1_array[2] == 5)
                                {
                                    enemy2_health = enemy2_health + hi_spirit;
                                }
                                else if (player1_array[2] == 6)
                                {
                                    enemy3_health = enemy3_health + hi_spirit;
                                }
                                else if (player1_array[2] == 7)
                                {
                                    enemy4_health = enemy4_health + hi_spirit;
                                }
                                else if (player1_array[2] == 8)
                                {
                                    enemy5_health = enemy5_health + hi_spirit;
                                }
                                else if (player1_array[2] == 9)
                                {
                                    enemy6_health = enemy6_health + hi_spirit;
                                }
                            }
                            //if the item sub selection is lazarus
                            if (player1_array[1] ==3)
                            {
                                player1_item3_count = player1_item3_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 4)
                                    {}
                                else if (player1_array[2] == 5)
                                    {}
                                else if (player1_array[2] == 6)
                                    {}
                                else if (player1_array[2] == 7)
                                    {}
                                else if (player1_array[2] == 8)
                                    {}
                                else if (player1_array[2] == 9)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );

                        char1x = 65;
                        char2x = 15;
                        char3x = 15;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);


                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stab, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player2_health != 0)
                        {
                            apply_surface( char2x, char2y, mage_stance, screen);
                        }
                        else
                        {
                            apply_surface( char2x, char2y, mage_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_stance, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }


                        apply_surface( 200, 150, attack_number_text, screen );
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

                        // show the enemies
                        if (bad1 == true)
                        {
                            apply_surface( ene1x, ene1y, enemy1, screen);
                            apply_surface( 420, 160, enemy1_health_text, screen);
                        }
                        if (bad2 == true)
                        {
                            apply_surface( ene2x, ene2y, enemy2, screen);
                            apply_surface( 420, 240, enemy2_health_text, screen);
                        }
                        if (bad3 == true)
                        {
                            apply_surface( ene3x, ene3y, enemy3, screen);
                            apply_surface( 420, 300, enemy3_health_text, screen);
                        }
                        if (bad4 == true)
                        {
                            apply_surface( ene4x, ene4y, enemy4, screen);
                            apply_surface( 530, 160, enemy4_health_text, screen);
                        }
                        if (bad5 == true)
                        {
                            apply_surface( ene5x, ene5y, enemy5, screen);
                            apply_surface( 530, 240, enemy5_health_text, screen);
                        }
                        if (bad6 == true)
                        {
                            apply_surface( ene6x, ene6y, enemy6, screen);
                            apply_surface( 530, 300, enemy6_health_text, screen);
                        }

                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char1x = 15;

                    }
                    else if (order2 == 2 && good2 == true)
                    {
                        char2x = 65;
                        //the animations will go right here
                        //if the primary choice is attack then find the target and calculate the results
                        if (player2_array[0] == 1)
                        {
                            if (player2_array[2] == 1)
                            {
                                if (player2_attack_power*30 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 2)
                            {
                                if (player2_attack_power*30 >= player2_health)
                                {
                                    player2_health = 0;
                                }
                                else
                                {
                                    player2_health = player2_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 3)
                            {
                                if (player2_attack_power*30 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 4)
                            {
                                if (player2_attack_power*30 >= enemy1_health)
                                {
                                    enemy1_health = 0;
                                    bad1 = false;
                                }
                                else
                                {
                                    enemy1_health = enemy1_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 5)
                            {
                                if (player2_attack_power*30 >= enemy2_health)
                                {
                                    enemy2_health = 0;
                                    bad2 = false;
                                }
                                else
                                {
                                    enemy2_health = enemy2_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 6)
                            {
                                if (player2_attack_power*30 >= enemy3_health)
                                {
                                    enemy3_health = 0;
                                    bad3 = false;
                                }
                                else
                                {
                                    enemy3_health = enemy3_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 7)
                            {
                                if (player2_attack_power*30 >= enemy4_health)
                                {
                                    enemy4_health = 0;
                                    bad4 = false;
                                }
                                else
                                {
                                    enemy4_health = enemy4_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 8)
                            {
                                if (player2_attack_power*30 >= enemy5_health)
                                {
                                    enemy5_health = 0;
                                    bad5 = false;
                                }
                                else
                                    enemy5_health = enemy5_health - (player2_attack_power*30);
                            }
                            else if (player2_array[2] == 9)
                            {
                                if (player2_attack_power*30 >= enemy6_health)
                                {
                                    enemy6_health = 0;
                                    bad6 = false;
                                }
                                else
                                {
                                    enemy6_health = enemy6_health - (player2_attack_power*30);
                                }
                            }
                            attack_number = player2_attack_power*30;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player2_array[0] == 2)
                        {
                            //if the magic sub selection is Burn
                            if (player2_array[1] == 1)
                            {
                                player2_magic = player2_magic - burn_magic;

                                if (player2_array[2] == 1)
                                {
                                    if (player2_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_magic_power*50 >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player2_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 4)
                                {
                                    if (player2_magic_power*50*burn >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (player2_magic_power*50*burn);
                                    }
                                    attack_number = player2_magic_power*50*burn;
                                }
                                else if (player2_array[2] == 5)
                                {
                                    if (player2_magic_power*50 >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 6)
                                {
                                    if (player2_magic_power*50 >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 7)
                                {
                                    if (player2_magic_power*50*burn >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (player2_magic_power*50*burn);
                                    }
                                    attack_number = player2_magic_power*50*burn;
                                }
                                else if (player2_array[2] == 8)
                                {
                                    if (player2_magic_power*50 >= enemy5_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                        enemy5_health = enemy5_health - (player2_magic_power*50);
                                }
                                else if (player2_array[2] == 9)
                                {
                                    if (player2_magic_power*50 >= enemy6_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (player2_magic_power*50);
                                    }
                                }
                                if (player2_array[2] != 4 && player2_array[2] != 7)
                                {
                                    attack_number = player2_magic_power*50;
                                }
                            }
                            //if the magic sub selection is Freeze
                            else if (player2_array[1] == 2)
                            {
                                player2_magic = player2_magic - freeze_magic;

                                if (player2_array[2] == 1)
                                {
                                    if (player2_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_magic_power*50 >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player2_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 4)
                                {
                                    if (player2_magic_power*50 >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 5)
                                {
                                    if (player2_magic_power*50*freeze >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (player2_magic_power*50*freeze);
                                    }
                                    attack_number = player2_magic_power*50*freeze;
                                }
                                else if (player2_array[2] == 6)
                                {
                                    if (player2_magic_power*50 >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 7)
                                {
                                    if (player2_magic_power*50 >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 8)
                                {
                                    if (player2_magic_power*50*freeze >= enemy5_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                        enemy5_health = enemy5_health - (player2_magic_power*50*freeze);
                                    attack_number = player2_magic_power*50*freeze;
                                }
                                else if (player2_array[2] == 9)
                                {
                                    if (player2_magic_power*50 >= enemy6_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (player2_magic_power*50);
                                    }
                                }
                                if (player2_array[2] != 5 && player2_array[2]  != 8)
                                {
                                    attack_number = player2_magic_power*50;
                                }
                            }
                            //if the magic sub selection is LIMIT
                            else if (player2_array[1] == 3)
                            {
                                limit2_power = player2_magic;
                                player2_magic = 0;

                                if (player2_array[2] == 1)
                                {
                                    if (player1_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player3_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 4)
                                {
                                    if (enemy1_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 5)
                                {
                                    if (enemy2_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 6)
                                {
                                    if (enemy3_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 7)
                                {
                                    if (enemy4_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 8)
                                {
                                    if (enemy5_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                    {
                                        enemy5_health = enemy5_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 9)
                                {
                                    if (enemy6_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                attack_number = limit2_power*player2_attack_power*player2_magic_power;

                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player2_array[0] == 3)
                        {
                            //if the item sub selection is ether
                            if (player2_array[1] == 1)
                            {
                                player2_item1_count = player2_item1_count - 1;

                                if (player2_array[2] == 1)
                                {
                                    if (player1_magic+ether > player1_total_magic)
                                    {
                                        player1_magic = player1_total_magic;
                                    }
                                    else
                                    {
                                        player1_magic = player1_magic + ether;
                                    }
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_magic+ether > player2_total_magic)
                                    {
                                        player2_magic = player2_total_magic;
                                    }
                                    else
                                    {
                                        player2_magic = player2_magic + ether;
                                    }
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player3_magic+ether > player3_total_magic)
                                    {
                                        player3_magic = player3_total_magic;
                                    }
                                    else
                                    {
                                        player3_magic = player3_magic + ether;
                                    }
                                }
                                else if (player2_array[2] == 4)
                                    {}
                                else if (player2_array[2] == 5)
                                    {}
                                else if (player2_array[2] == 6)
                                    {}
                                else if (player2_array[2] == 7)
                                    {}
                                else if (player2_array[2] == 8)
                                    {}
                                else if (player2_array[2] == 9)
                                    {}
                            }
                            //if the item sub selection is hi-ether
                            if (player2_array[1] == 2)
                            {
                                player2_item2_count = player1_item2_count - 1;

                                if (player2_array[2] == 1)
                                {
                                    if (player1_magic+hi_ether > player1_total_magic)
                                    {
                                        player1_magic = player1_total_magic;
                                    }
                                    else
                                    {
                                        player1_magic = player1_magic + hi_ether;
                                    }
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_magic+hi_ether > player2_total_magic)
                                    {
                                        player2_magic = player2_total_magic;
                                    }
                                    else
                                    {
                                        player2_magic = player2_magic + hi_ether;
                                    }
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player3_magic+hi_ether > player3_total_magic)
                                    {
                                        player3_magic = player3_total_magic;
                                    }
                                    else
                                    {
                                        player3_magic = player3_magic + hi_ether;
                                    }
                                }
                                else if (player2_array[2] == 4)
                                {

                                }
                                else if (player2_array[2] == 5)
                                {

                                }
                                else if (player2_array[2] == 6)
                                {

                                }
                                else if (player2_array[2] == 7)
                                {

                                }
                                else if (player2_array[2] == 8)
                                    {}
                                else if (player2_array[2] == 9)
                                    {}
                            }
                            //if the item sub selection is lazarus
                            if (player2_array[1] ==3)
                            {
                                player2_item3_count = player2_item3_count - 1;

                                if (player2_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player2_array[2] == 4)
                                    {}
                                else if (player2_array[2] == 5)
                                    {}
                                else if (player2_array[2] == 6)
                                    {}
                                else if (player2_array[2] == 7)
                                    {}
                                else if (player2_array[2] == 8)
                                    {}
                                else if (player2_array[2] == 9)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );

                        char1x = 15;
                        char2x = 65;
                        char3x = 15;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stance, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player2_health != 0)
                        {
                            apply_surface( char2x, char2y, mage_stab, screen);
                        }
                        else
                        {
                            apply_surface( char2x, char2y, mage_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_stance, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        apply_surface( 200, 220, attack_number_text, screen );
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

                        // show the enemies
                        if (bad1 == true)
                        {
                            apply_surface( ene1x, ene1y, enemy1, screen);
                            apply_surface( 420, 160, enemy1_health_text, screen);
                        }
                        if (bad2 == true)
                        {
                            apply_surface( ene2x, ene2y, enemy2, screen);
                            apply_surface( 420, 240, enemy2_health_text, screen);
                        }
                        if (bad3 == true)
                        {
                            apply_surface( ene3x, ene3y, enemy3, screen);
                            apply_surface( 420, 300, enemy3_health_text, screen);
                        }
                        if (bad4 == true)
                        {
                            apply_surface( ene4x, ene4y, enemy4, screen);
                            apply_surface( 530, 160, enemy4_health_text, screen);
                        }
                        if (bad5 == true)
                        {
                            apply_surface( ene5x, ene5y, enemy5, screen);
                            apply_surface( 530, 240, enemy5_health_text, screen);
                        }
                        if (bad6 == true)
                        {
                            apply_surface( ene6x, ene6y, enemy6, screen);
                            apply_surface( 530, 300, enemy6_health_text, screen);
                        }

                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char1x = 15;


                    }
                    else if (order2 == 3 && good3 == true)
                    {
                        char3x = 65;
                        //the animations will go right here
                        //if the primary choice is attack then find the target and calculate the results
                        if (player3_array[0] == 1)
                        {
                            if (player3_array[2] == 1)
                            {
                                if (player3_attack_power*40 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 2)
                            {
                                if (player3_attack_power*40 >= player2_health)
                                {
                                    player2_health = 0;
                                }
                                else
                                {
                                    player2_health = player2_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 3)
                            {
                                if (player3_attack_power*40 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 4)
                            {
                                if (player3_attack_power*40 >= enemy1_health)
                                {
                                    enemy1_health = 0;
                                    bad1 = false;
                                }
                                else
                                {
                                    enemy1_health = enemy1_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 5)
                            {
                                if (player3_attack_power*40 >= enemy2_health)
                                {
                                    enemy2_health = 0;
                                    bad2 = false;
                                }
                                else
                                {
                                    enemy2_health = enemy2_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 6)
                            {
                                if (player3_attack_power*40 >= enemy3_health)
                                {
                                    enemy3_health = 0;
                                    bad3 = false;
                                }
                                else
                                {
                                    enemy3_health = enemy3_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 7)
                            {
                                if (player3_attack_power*40 >= enemy4_health)
                                {
                                    enemy4_health = 0;
                                    bad4 = false;
                                }
                                else
                                {
                                    enemy4_health = enemy4_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 8)
                            {
                                if (player3_attack_power*40 >= enemy5_health)
                                {
                                    enemy5_health = 0;
                                    bad5 = false;
                                }
                                else
                                    enemy5_health = enemy5_health - (player3_attack_power*40);
                            }
                            else if (player3_array[2] == 9)
                            {
                                if (player3_attack_power*40 >= enemy6_health)
                                {
                                    enemy6_health = 0;
                                    bad6 = false;
                                }
                                else
                                {
                                    enemy6_health = enemy6_health - (player3_attack_power*40);
                                }
                            }
                            attack_number = player3_attack_power*40;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player3_array[0] == 2)
                        {
                            //if the magic sub selection is Freeze
                            if (player3_array[1] == 1)
                            {
                                player3_magic = player3_magic - freeze_magic;

                                if (player3_array[2] == 1)
                                {
                                    if (player3_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player3_magic_power*50 >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    if (player3_magic_power*50 >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 5)
                                {
                                    if (player3_magic_power*50*freeze >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (player3_magic_power*50*freeze);
                                    }
                                    attack_number = player3_magic_power*50*freeze;
                                }
                                else if (player3_array[2] == 6)
                                {
                                    if (player3_magic_power*50 >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 7)
                                {
                                    if (player3_magic_power*50 >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 8)
                                {
                                    if (player3_magic_power*50*freeze >= enemy5_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                        enemy5_health = enemy5_health - (player3_magic_power*50*freeze);
                                    attack_number = player3_magic_power*50*freeze;
                                }
                                else if (player3_array[2] == 9)
                                {
                                    if (player3_magic_power*50 >= enemy6_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (player3_magic_power*50);
                                    }
                                }
                                if (player3_array[2] != 5 && player3_array[2] != 8)
                                {
                                    attack_number = player3_magic_power*50;
                                }
                            }
                            //if the magic sub selection is Power X2
                            else if (player3_array[1] == 2)
                            {
                                player3_magic = player3_magic - power_magic;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player1_attack_power = player1_attack_power*2;
                                    }
                                }
                                else  if (player3_array[2] == 2)
                                {
                                    if (player2_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player2_attack_power = player2_attack_power*2;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player3_attack_power = player3_attack_power*2;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                                attack_number = 0;

                            }
                            //if the magic sub selection is LIMIT
                            else if (player3_array[1] == 3)
                            {
                                limit3_power = player3_magic;
                                player3_magic = 0;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    if (enemy1_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 5)
                                {
                                    if (enemy2_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 6)
                                {
                                    if (enemy3_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 7)
                                {
                                    if (enemy4_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 8)
                                {
                                    if (enemy5_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                    {
                                        enemy5_health = enemy5_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 9)
                                {
                                    if (enemy6_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                attack_number = limit3_power*player3_attack_power*player3_magic_power;
                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player3_array[0] == 3)
                        {
                            //if the item sub selection is hi-spirit
                            if (player3_array[1] == 1)
                            {
                                player3_item1_count = player3_item1_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health+hi_spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health+hi_spirit > player2_total_health)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                    {
                                        player2_health = player2_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health+hi_spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    enemy1_health = enemy1_health + hi_spirit;
                                }
                                else if (player3_array[2] == 5)
                                {
                                    enemy2_health = enemy2_health + hi_spirit;
                                }
                                else if (player3_array[2] == 6)
                                {
                                    enemy3_health = enemy3_health + hi_spirit;
                                }
                                else if (player3_array[2] == 7)
                                {
                                    enemy4_health = enemy4_health + hi_spirit;
                                }
                                else if (player3_array[2] == 8)
                                {
                                    enemy5_health = enemy5_health + hi_spirit;
                                }
                                else if (player3_array[2] == 9)
                                {
                                    enemy6_health = enemy6_health + hi_spirit;
                                }
                            }
                            //use this for the hi-ether
                            if (player3_array[1] == 2)
                            {
                                player3_item2_count = player3_item2_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_magic+hi_ether > player1_total_magic)
                                    {
                                        player1_magic = player1_total_magic;
                                    }
                                    else
                                    {
                                        player1_magic = player1_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_magic+hi_ether > player2_total_magic)
                                    {
                                        player2_magic = player2_total_magic;
                                    }
                                    else
                                    {
                                        player2_magic = player2_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_magic+hi_ether > player3_total_magic)
                                    {
                                        player3_magic = player3_total_magic;
                                    }
                                    else
                                    {
                                        player3_magic = player3_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                            }
                            //if the item sub selection is lazarus
                            if (player3_array[1] ==3)
                            {
                                player3_item3_count = player3_item3_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );

                        char1x = 15;
                        char2x = 15;
                        char3x = 65;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stance, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player2_health != 0)
                        {
                            apply_surface( char2x, char2y, mage_stance, screen);
                        }
                        else
                        {
                            apply_surface( char2x, char2y, mage_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_shoot, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        apply_surface( 200, 290, attack_number_text, screen );
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

                        // show the enemies
                        if (bad1 == true)
                        {
                            apply_surface( ene1x, ene1y, enemy1, screen);
                            apply_surface( 420, 160, enemy1_health_text, screen);
                        }
                        if (bad2 == true)
                        {
                            apply_surface( ene2x, ene2y, enemy2, screen);
                            apply_surface( 420, 240, enemy2_health_text, screen);
                        }
                        if (bad3 == true)
                        {
                            apply_surface( ene3x, ene3y, enemy3, screen);
                            apply_surface( 420, 300, enemy3_health_text, screen);
                        }
                        if (bad4 == true)
                        {
                            apply_surface( ene4x, ene4y, enemy4, screen);
                            apply_surface( 530, 160, enemy4_health_text, screen);
                        }
                        if (bad5 == true)
                        {
                            apply_surface( ene5x, ene5y, enemy5, screen);
                            apply_surface( 530, 240, enemy5_health_text, screen);
                        }
                        if (bad6 == true)
                        {
                            apply_surface( ene6x, ene6y, enemy6, screen);
                            apply_surface( 530, 300, enemy6_health_text, screen);
                        }

                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char3x = 15;

                    }
                }
                else if (fight_turn == 5)
                {
                    if (bad3 == true)
                    {
                        if (good1 == true && good2 == true && good3 == true)
                        {
                            enemy_random = 1 + rand() % 3;
                        }
                        else if (good1 == false)
                        {
                            if (good2 == false)
                            {
                                enemy_random = 3;
                            }
                            else if (good3 == false)
                            {
                                enemy_random = 2;
                            }
                            else
                            {
                                enemy_random = 2 + rand() %2;
                            }
                        }
                        else
                        {
                            if (good2 == false)
                            {
                                if (good3 == true)
                                {
                                    if (1+rand()%2 == 1)
                                    {
                                        enemy_random = 1;
                                    }
                                    else
                                    {
                                        enemy_random = 3;
                                    }
                                }
                                else
                                {
                                    enemy_random =1;
                                }
                            }
                            else
                            {
                                if (good3 == false)
                                {
                                    enemy_random = 1 + rand()%2;
                                }
                            }
                        }

                        if (enemy_random == 1)
                        {
                            if (enemy3_attack*30 > player1_health)
                            {
                                player1_health = 0;
                            }
                            else
                            {
                                player1_health = player1_health - enemy3_attack*30;
                            }
                        }
                        else if (enemy_random == 2)
                        {
                            if (enemy3_attack*30 > player2_health)
                            {
                                player2_health = 0;
                            }
                            else
                            {
                                player2_health = player2_health - enemy3_attack*30;
                            }
                        }
                        else if (enemy_random == 3)
                        {
                            if (enemy3_attack*30 > player3_health)
                            {
                                player3_health = 0;
                            }
                            else
                            {
                                player3_health = player3_health - enemy3_attack*30;
                            }
                        }
                        attack_number = enemy3_attack*30;
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), alertColor );

                        char1x = 15;
                        char2x = 15;
                        char3x = 15;
                        ene1x = 440;
                        ene2x = 440;
                        ene3x = 320;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stance, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }
                        if (player2_health != 0)
                        {
                            apply_surface( char2x, char2y, mage_stance, screen);
                        }
                        else
                        {
                            apply_surface( char2x, char2y, mage_dead, screen);
                        }
                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_stance, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        if (enemy_random == 1)
                        {
                            apply_surface( 150, 140, attack_number_text, screen );
                        }
                        else if (enemy_random == 2)
                        {
                            apply_surface( 150, 210, attack_number_text, screen );
                        }
                        else if (enemy_random == 3)
                        {
                            apply_surface( 150, 290, attack_number_text, screen );
                        }

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

                        // show the enemies
                        if (bad1 == true)
                        {
                            apply_surface( ene1x, ene1y, enemy1, screen);
                            apply_surface( 420, 160, enemy1_health_text, screen);
                        }
                        if (bad2 == true)
                        {
                            apply_surface( ene2x, ene2y, enemy2, screen);
                            apply_surface( 420, 240, enemy2_health_text, screen);
                        }
                        if (bad3 == true)
                        {
                            apply_surface( ene3x, ene3y, enemy3, screen);
                            apply_surface( 420, 300, enemy3_health_text, screen);
                        }
                        if (bad4 == true)
                        {
                            apply_surface( ene4x, ene4y, enemy4, screen);
                            apply_surface( 530, 160, enemy4_health_text, screen);
                        }
                        if (bad5 == true)
                        {
                            apply_surface( ene5x, ene5y, enemy5, screen);
                            apply_surface( 530, 240, enemy5_health_text, screen);
                        }
                        if (bad6 == true)
                        {
                            apply_surface( ene6x, ene6y, enemy6, screen);
                            apply_surface( 530, 300, enemy6_health_text, screen);
                        }

                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        ene3x = 440;
                    }
                }
                else if (fight_turn == 6)
                {
                    if (bad4 == true)
                    {
                        if (good1 == true && good2 == true && good3 == true)
                        {
                            enemy_random = 1 + rand() % 3;
                        }
                        else if (good1 == false)
                        {
                            if (good2 == false)
                            {
                                enemy_random = 3;
                            }
                            else if (good3 == false)
                            {
                                enemy_random = 2;
                            }
                            else
                            {
                                enemy_random = 2 + rand() %2;
                            }
                        }
                        else
                        {
                            if (good2 == false)
                            {
                                if (good3 == true)
                                {
                                    if (1+rand()%2 == 1)
                                    {
                                        enemy_random = 1;
                                    }
                                    else
                                    {
                                        enemy_random = 2;
                                    }
                                }
                                else
                                {
                                    enemy_random =1;
                                }
                            }
                            else
                            {
                                if (good3 == false)
                                {
                                    enemy_random = 1 + rand()%2;
                                }
                            }
                        }

                        if (enemy_random == 1)
                        {
                            if (enemy1_attack*30 > player1_health)
                            {
                                player1_health = 0;
                            }
                            else
                            {
                                player1_health = player1_health - enemy1_attack*30;
                            }
                        }
                        else if (enemy_random == 2)
                        {
                            if (enemy1_attack*30 > player2_health)
                            {
                                player2_health = 0;
                            }
                            else
                            {
                                player2_health = player2_health - enemy1_attack*30;
                            }
                        }
                        else if (enemy_random == 3)
                        {
                            if (enemy1_attack*30 > player3_health)
                            {
                                player3_health = 0;
                            }
                            else
                            {
                                player3_health = player3_health - enemy1_attack*30;
                            }
                        }
                        //insert enemy4 animation

                        attack_number = enemy4_attack*30;
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), alertColor );

                        char1x = 15;
                        char2x = 15;
                        char3x = 15;
                        ene1x = 440;
                        ene2x = 440;
                        ene3x = 440;
                        ene4x = 320;
                        ene5x = 550;
                        ene6x = 550;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stance, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }
                        if (player2_health != 0)
                        {
                            apply_surface( char2x, char2y, mage_stance, screen);
                        }
                        else
                        {
                            apply_surface( char2x, char2y, mage_dead, screen);
                        }
                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_stance, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        if (enemy_random == 1)
                        {
                            apply_surface( 150, 140, attack_number_text, screen );
                        }
                        else if (enemy_random == 2)
                        {
                            apply_surface( 150, 210, attack_number_text, screen );
                        }
                        else if (enemy_random == 3)
                        {
                            apply_surface( 150, 290, attack_number_text, screen );
                        }

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

                        // show the enemies
                        if (bad1 == true)
                        {
                            apply_surface( ene1x, ene1y, enemy1, screen);
                            apply_surface( 420, 160, enemy1_health_text, screen);
                        }
                        if (bad2 == true)
                        {
                            apply_surface( ene2x, ene2y, enemy2, screen);
                            apply_surface( 420, 240, enemy2_health_text, screen);
                        }
                        if (bad3 == true)
                        {
                            apply_surface( ene3x, ene3y, enemy3, screen);
                            apply_surface( 420, 300, enemy3_health_text, screen);
                        }
                        if (bad4 == true)
                        {
                            apply_surface( ene4x, ene4y, enemy4, screen);
                            apply_surface( 530, 160, enemy4_health_text, screen);
                        }
                        if (bad5 == true)
                        {
                            apply_surface( ene5x, ene5y, enemy5, screen);
                            apply_surface( 530, 240, enemy5_health_text, screen);
                        }
                        if (bad6 == true)
                        {
                            apply_surface( ene6x, ene6y, enemy6, screen);
                            apply_surface( 530, 300, enemy6_health_text, screen);
                        }

                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        ene4x = 550;
                    }
                }
                else if (fight_turn == 7 && evil == false)
                {
                    if (order3 == 1 && good1 == true)
                    {
                        //if the primary choice is attack then find the target and calculate the results
                        if (player1_array[0] == 1)
                        {
                            if (player1_array[2] == 1)
                            {
                                if (player1_attack_power*50 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 2)
                            {
                                if (player1_attack_power*50 >= player2_health)
                                {
                                    player2_health = 0;
                                }
                                else
                                {
                                    player2_health = player2_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 3)
                            {
                                if (player1_attack_power*50 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 4)
                            {
                                if (player1_attack_power*50 >= enemy1_health)
                                {
                                    enemy1_health = 0;
                                    bad1 = false;
                                }
                                else
                                {
                                    enemy1_health = enemy1_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 5)
                            {
                                if (player1_attack_power*50 >= enemy2_health)
                                {
                                    enemy2_health = 0;
                                    bad2 = false;
                                }
                                else
                                {
                                    enemy2_health = enemy2_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 6)
                            {
                                if (player1_attack_power*50 >= enemy3_health)
                                {
                                    enemy3_health = 0;
                                    bad3 = false;
                                }
                                else
                                {
                                    enemy3_health = enemy3_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 7)
                            {
                                if (player1_attack_power*50 >= enemy4_health)
                                {
                                    enemy4_health = 0;
                                    bad4 = false;
                                }
                                else
                                {
                                    enemy4_health = enemy4_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 8)
                            {
                                if (player1_attack_power*50 >= enemy5_health)
                                {
                                    enemy5_health = 0;
                                    bad5 = false;
                                }
                                else
                                    enemy5_health = enemy5_health - (player1_attack_power*50);
                            }
                            else if (player1_array[2] == 9)
                            {
                                if (player1_attack_power*50 >= enemy6_health)
                                {
                                    enemy6_health = 0;
                                    bad6 = false;
                                }
                                else
                                {
                                    enemy6_health = enemy6_health - (player1_attack_power*50);
                                }
                            }
                            attack_number = player1_attack_power*50;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player1_array[0] == 2)
                        {
                            //if the magic sub selection is Rage
                            if (player1_array[1] == 1)
                            {
                                player1_magic = player1_magic - rage_magic;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_attack_power*50*rage >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player1_attack_power*50*rage >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player1_attack_power*50*rage >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 4)
                                {
                                    if (player1_attack_power*50*rage >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (player1_attack_power*50*rage >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 6)
                                {
                                    if (player1_attack_power*50*rage >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 7)
                                {
                                    if (player1_attack_power*50*rage >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 8)
                                {
                                    if (player1_attack_power*50*rage >= enemy1_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                    {
                                        enemy5_health = enemy5_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 9)
                                {
                                    if (player1_attack_power*50*rage >= enemy1_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health -(player1_attack_power*50*rage);
                                    }
                                }
                                attack_number = player1_attack_power*50*rage;
                            }
                            //if the magic sub selection is Burn
                            if (player1_array[1] == 2)
                            {
                                player1_magic = player1_magic - burn_magic;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player1_magic_power*50 >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player1_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 4)
                                {
                                    if (player1_magic_power*50*burn >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (player1_magic_power*50*burn);
                                    }
                                    attack_number = player1_magic_power*50*burn;
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (player1_magic_power*50 >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 6)
                                {
                                    if (player1_magic_power*50 >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 7)
                                {
                                    if (player1_magic_power*50*burn >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (player1_magic_power*50*burn);
                                    }
                                    attack_number = player1_magic_power*50*burn;
                                }
                                else if (player1_array[2] == 8)
                                {
                                    if (player1_magic_power*50 >= enemy5_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                        enemy5_health = enemy5_health - (player1_magic_power*50);
                                }
                                else if (player1_array[2] == 9)
                                {
                                    if (player1_magic_power*50 >= enemy6_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (player1_magic_power*50);
                                    }
                                }
                                if (player1_array[2] != 4 && player1_array[2] != 7)
                                {
                                    attack_number = player1_magic_power*50;
                                }
                            }
                            //if the magic sub selection is LIMIT
                            else if (player1_array[1] == 3)
                            {
                                limit1_power = player1_magic;
                                player1_magic = 0;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player2_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 4)
                                {
                                    if (enemy1_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (enemy2_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 6)
                                {
                                    if (enemy3_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 7)
                                {
                                    if (enemy4_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 8)
                                {
                                    if (enemy5_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                    {
                                        enemy5_health = enemy5_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 9)
                                {
                                    if (enemy6_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                attack_number = limit1_power*player1_attack_power*player1_magic_power;
                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player1_array[0] == 3)
                        {
                            //if the item sub selection is spirit
                            if (player1_array[1] == 1)
                            {
                                player1_item1_count = player1_item1_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player1_health+spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player2_health+spirit > player2_total_health)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                    {
                                        player2_health = player2_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player3_health+spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 4)
                                {
                                    enemy1_health = enemy1_health + spirit;
                                }
                                else if (player1_array[2] == 5)
                                {
                                    enemy2_health = enemy2_health + spirit;
                                }
                                else if (player1_array[2] == 6)
                                {
                                    enemy3_health = enemy3_health + spirit;
                                }
                                else if (player1_array[2] == 7)
                                {
                                    enemy4_health = enemy4_health + spirit;
                                }
                                else if (player1_array[2] == 8)
                                {
                                    enemy5_health = enemy5_health + spirit;
                                }
                                else if (player1_array[2] == 9)
                                {
                                    enemy6_health = enemy6_health + spirit;
                                }
                            }
                            //if the item sub selection is hi-spirit
                            if (player1_array[1] == 2)
                            {
                                player1_item2_count = player1_item2_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player1_health+hi_spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player2_health+hi_spirit > player2_total_health)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                    {
                                        player2_health = player2_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player3_health+hi_spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 4)
                                {
                                    enemy1_health = enemy1_health + hi_spirit;
                                }
                                else if (player1_array[2] == 5)
                                {
                                    enemy2_health = enemy2_health + hi_spirit;
                                }
                                else if (player1_array[2] == 6)
                                {
                                    enemy3_health = enemy3_health + hi_spirit;
                                }
                                else if (player1_array[2] == 7)
                                {
                                    enemy4_health = enemy4_health + hi_spirit;
                                }
                                else if (player1_array[2] == 8)
                                {
                                    enemy5_health = enemy5_health + hi_spirit;
                                }
                                else if (player1_array[2] == 9)
                                {
                                    enemy6_health = enemy6_health + hi_spirit;
                                }
                            }
                            //if the item sub selection is lazarus
                            if (player1_array[1] ==3)
                            {
                                player1_item3_count = player1_item3_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 4)
                                    {}
                                else if (player1_array[2] == 5)
                                    {}
                                else if (player1_array[2] == 6)
                                    {}
                                else if (player1_array[2] == 7)
                                    {}
                                else if (player1_array[2] == 8)
                                    {}
                                else if (player1_array[2] == 9)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );

                        char1x = 65;
                        char2x = 15;
                        char3x = 15;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);


                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stab, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player2_health != 0)
                        {
                            apply_surface( char2x, char2y, mage_stance, screen);
                        }
                        else
                        {
                            apply_surface( char2x, char2y, mage_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_stance, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }


                        apply_surface( 200, 150, attack_number_text, screen );
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

                        // show the enemies
                        if (bad1 == true)
                        {
                            apply_surface( ene1x, ene1y, enemy1, screen);
                            apply_surface( 420, 160, enemy1_health_text, screen);
                        }
                        if (bad2 == true)
                        {
                            apply_surface( ene2x, ene2y, enemy2, screen);
                            apply_surface( 420, 240, enemy2_health_text, screen);
                        }
                        if (bad3 == true)
                        {
                            apply_surface( ene3x, ene3y, enemy3, screen);
                            apply_surface( 420, 300, enemy3_health_text, screen);
                        }
                        if (bad4 == true)
                        {
                            apply_surface( ene4x, ene4y, enemy4, screen);
                            apply_surface( 530, 160, enemy4_health_text, screen);
                        }
                        if (bad5 == true)
                        {
                            apply_surface( ene5x, ene5y, enemy5, screen);
                            apply_surface( 530, 240, enemy5_health_text, screen);
                        }
                        if (bad6 == true)
                        {
                            apply_surface( ene6x, ene6y, enemy6, screen);
                            apply_surface( 530, 300, enemy6_health_text, screen);
                        }

                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char1x = 15;

                    }
                    else if (order3 == 2 && good2 == true)
                    {
                        char2x = 65;
                        //the animations will go right here
                        //if the primary choice is attack then find the target and calculate the results
                        if (player2_array[0] == 1)
                        {
                            if (player2_array[2] == 1)
                            {
                                if (player2_attack_power*30 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 2)
                            {
                                if (player2_attack_power*30 >= player2_health)
                                {
                                    player2_health = 0;
                                }
                                else
                                {
                                    player2_health = player2_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 3)
                            {
                                if (player2_attack_power*30 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 4)
                            {
                                if (player2_attack_power*30 >= enemy1_health)
                                {
                                    enemy1_health = 0;
                                    bad1 = false;
                                }
                                else
                                {
                                    enemy1_health = enemy1_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 5)
                            {
                                if (player2_attack_power*30 >= enemy2_health)
                                {
                                    enemy2_health = 0;
                                    bad2 = false;
                                }
                                else
                                {
                                    enemy2_health = enemy2_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 6)
                            {
                                if (player2_attack_power*30 >= enemy3_health)
                                {
                                    enemy3_health = 0;
                                    bad3 = false;
                                }
                                else
                                {
                                    enemy3_health = enemy3_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 7)
                            {
                                if (player2_attack_power*30 >= enemy4_health)
                                {
                                    enemy4_health = 0;
                                    bad4 = false;
                                }
                                else
                                {
                                    enemy4_health = enemy4_health - (player2_attack_power*30);
                                }
                            }
                            else if (player2_array[2] == 8)
                            {
                                if (player2_attack_power*30 >= enemy5_health)
                                {
                                    enemy5_health = 0;
                                    bad5 = false;
                                }
                                else
                                    enemy5_health = enemy5_health - (player2_attack_power*30);
                            }
                            else if (player2_array[2] == 9)
                            {
                                if (player2_attack_power*30 >= enemy6_health)
                                {
                                    enemy6_health = 0;
                                    bad6 = false;
                                }
                                else
                                {
                                    enemy6_health = enemy6_health - (player2_attack_power*30);
                                }
                            }
                            attack_number = player2_attack_power*30;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player2_array[0] == 2)
                        {
                            //if the magic sub selection is Burn
                            if (player2_array[1] == 1)
                            {
                                player2_magic = player2_magic - burn_magic;

                                if (player2_array[2] == 1)
                                {
                                    if (player2_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_magic_power*50 >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player2_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 4)
                                {
                                    if (player2_magic_power*50*burn >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (player2_magic_power*50*burn);
                                    }
                                    attack_number = player2_magic_power*50*burn;
                                }
                                else if (player2_array[2] == 5)
                                {
                                    if (player2_magic_power*50 >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 6)
                                {
                                    if (player2_magic_power*50 >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 7)
                                {
                                    if (player2_magic_power*50*burn >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (player2_magic_power*50*burn);
                                    }
                                    attack_number = player2_magic_power*50*burn;
                                }
                                else if (player2_array[2] == 8)
                                {
                                    if (player2_magic_power*50 >= enemy5_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                        enemy5_health = enemy5_health - (player2_magic_power*50);
                                }
                                else if (player2_array[2] == 9)
                                {
                                    if (player2_magic_power*50 >= enemy6_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (player2_magic_power*50);
                                    }
                                }
                                if (player2_array[2] != 4 && player2_array[2] != 7)
                                {
                                    attack_number = player2_magic_power*50;
                                }
                            }
                            //if the magic sub selection is Freeze
                            else if (player2_array[1] == 2)
                            {
                                player2_magic = player2_magic - freeze_magic;

                                if (player2_array[2] == 1)
                                {
                                    if (player2_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_magic_power*50 >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player2_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 4)
                                {
                                    if (player2_magic_power*50 >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 5)
                                {
                                    if (player2_magic_power*50*freeze >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (player2_magic_power*50*freeze);
                                    }
                                    attack_number = player2_magic_power*50*freeze;
                                }
                                else if (player2_array[2] == 6)
                                {
                                    if (player2_magic_power*50 >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 7)
                                {
                                    if (player2_magic_power*50 >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (player2_magic_power*50);
                                    }
                                }
                                else if (player2_array[2] == 8)
                                {
                                    if (player2_magic_power*50*freeze >= enemy5_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                        enemy5_health = enemy5_health - (player2_magic_power*50*freeze);
                                    attack_number = player2_magic_power*50*freeze;
                                }
                                else if (player2_array[2] == 9)
                                {
                                    if (player2_magic_power*50 >= enemy6_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (player2_magic_power*50);
                                    }
                                }
                                if (player2_array[2] != 5 && player2_array[2]  != 8)
                                {
                                    attack_number = player2_magic_power*50;
                                }
                            }
                            //if the magic sub selection is LIMIT
                            else if (player2_array[1] == 3)
                            {
                                limit2_power = player2_magic;
                                player2_magic = 0;

                                if (player2_array[2] == 1)
                                {
                                    if (player1_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player3_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 4)
                                {
                                    if (enemy1_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 5)
                                {
                                    if (enemy2_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 6)
                                {
                                    if (enemy3_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 7)
                                {
                                    if (enemy4_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 8)
                                {
                                    if (enemy5_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                    {
                                        enemy5_health = enemy5_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                else if (player2_array[2] == 9)
                                {
                                    if (enemy6_health <= limit2_power*player2_attack_power*player2_magic_power)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (limit2_power*player2_attack_power*player2_magic_power);
                                    }
                                }
                                attack_number = limit2_power*player2_attack_power*player2_magic_power;

                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player2_array[0] == 3)
                        {
                            //if the item sub selection is ether
                            if (player2_array[1] == 1)
                            {
                                player2_item1_count = player2_item1_count - 1;

                                if (player2_array[2] == 1)
                                {
                                    if (player1_magic+ether > player1_total_magic)
                                    {
                                        player1_magic = player1_total_magic;
                                    }
                                    else
                                    {
                                        player1_magic = player1_magic + ether;
                                    }
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_magic+ether > player2_total_magic)
                                    {
                                        player2_magic = player2_total_magic;
                                    }
                                    else
                                    {
                                        player2_magic = player2_magic + ether;
                                    }
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player3_magic+ether > player3_total_magic)
                                    {
                                        player3_magic = player3_total_magic;
                                    }
                                    else
                                    {
                                        player3_magic = player3_magic + ether;
                                    }
                                }
                                else if (player2_array[2] == 4)
                                    {}
                                else if (player2_array[2] == 5)
                                    {}
                                else if (player2_array[2] == 6)
                                    {}
                                else if (player2_array[2] == 7)
                                    {}
                                else if (player2_array[2] == 8)
                                    {}
                                else if (player2_array[2] == 9)
                                    {}
                            }
                            //if the item sub selection is hi-ether
                            if (player2_array[1] == 2)
                            {
                                player2_item2_count = player1_item2_count - 1;

                                if (player2_array[2] == 1)
                                {
                                    if (player1_magic+hi_ether > player1_total_magic)
                                    {
                                        player1_magic = player1_total_magic;
                                    }
                                    else
                                    {
                                        player1_magic = player1_magic + hi_ether;
                                    }
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_magic+hi_ether > player2_total_magic)
                                    {
                                        player2_magic = player2_total_magic;
                                    }
                                    else
                                    {
                                        player2_magic = player2_magic + hi_ether;
                                    }
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player3_magic+hi_ether > player3_total_magic)
                                    {
                                        player3_magic = player3_total_magic;
                                    }
                                    else
                                    {
                                        player3_magic = player3_magic + hi_ether;
                                    }
                                }
                                else if (player2_array[2] == 4)
                                {

                                }
                                else if (player2_array[2] == 5)
                                {

                                }
                                else if (player2_array[2] == 6)
                                {

                                }
                                else if (player2_array[2] == 7)
                                {

                                }
                                else if (player2_array[2] == 8)
                                    {}
                                else if (player2_array[2] == 9)
                                    {}
                            }
                            //if the item sub selection is lazarus
                            if (player2_array[1] ==3)
                            {
                                player2_item3_count = player2_item3_count - 1;

                                if (player2_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player2_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player2_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player2_array[2] == 4)
                                    {}
                                else if (player2_array[2] == 5)
                                    {}
                                else if (player2_array[2] == 6)
                                    {}
                                else if (player2_array[2] == 7)
                                    {}
                                else if (player2_array[2] == 8)
                                    {}
                                else if (player2_array[2] == 9)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );

                        char1x = 15;
                        char2x = 65;
                        char3x = 15;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stance, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player2_health != 0)
                        {
                            apply_surface( char2x, char2y, mage_stab, screen);
                        }
                        else
                        {
                            apply_surface( char2x, char2y, mage_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_stance, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        apply_surface( 200, 220, attack_number_text, screen );
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

                        // show the enemies
                        if (bad1 == true)
                        {
                            apply_surface( ene1x, ene1y, enemy1, screen);
                            apply_surface( 420, 160, enemy1_health_text, screen);
                        }
                        if (bad2 == true)
                        {
                            apply_surface( ene2x, ene2y, enemy2, screen);
                            apply_surface( 420, 240, enemy2_health_text, screen);
                        }
                        if (bad3 == true)
                        {
                            apply_surface( ene3x, ene3y, enemy3, screen);
                            apply_surface( 420, 300, enemy3_health_text, screen);
                        }
                        if (bad4 == true)
                        {
                            apply_surface( ene4x, ene4y, enemy4, screen);
                            apply_surface( 530, 160, enemy4_health_text, screen);
                        }
                        if (bad5 == true)
                        {
                            apply_surface( ene5x, ene5y, enemy5, screen);
                            apply_surface( 530, 240, enemy5_health_text, screen);
                        }
                        if (bad6 == true)
                        {
                            apply_surface( ene6x, ene6y, enemy6, screen);
                            apply_surface( 530, 300, enemy6_health_text, screen);
                        }

                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char1x = 15;


                    }
                    else if (order3 == 3 && good3 == true)
                    {
                        char3x = 65;
                        //the animations will go right here
                        //if the primary choice is attack then find the target and calculate the results
                        if (player3_array[0] == 1)
                        {
                            if (player3_array[2] == 1)
                            {
                                if (player3_attack_power*40 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 2)
                            {
                                if (player3_attack_power*40 >= player2_health)
                                {
                                    player2_health = 0;
                                }
                                else
                                {
                                    player2_health = player2_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 3)
                            {
                                if (player3_attack_power*40 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 4)
                            {
                                if (player3_attack_power*40 >= enemy1_health)
                                {
                                    enemy1_health = 0;
                                    bad1 = false;
                                }
                                else
                                {
                                    enemy1_health = enemy1_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 5)
                            {
                                if (player3_attack_power*40 >= enemy2_health)
                                {
                                    enemy2_health = 0;
                                    bad2 = false;
                                }
                                else
                                {
                                    enemy2_health = enemy2_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 6)
                            {
                                if (player3_attack_power*40 >= enemy3_health)
                                {
                                    enemy3_health = 0;
                                    bad3 = false;
                                }
                                else
                                {
                                    enemy3_health = enemy3_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 7)
                            {
                                if (player3_attack_power*40 >= enemy4_health)
                                {
                                    enemy4_health = 0;
                                    bad4 = false;
                                }
                                else
                                {
                                    enemy4_health = enemy4_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 8)
                            {
                                if (player3_attack_power*40 >= enemy5_health)
                                {
                                    enemy5_health = 0;
                                    bad5 = false;
                                }
                                else
                                    enemy5_health = enemy5_health - (player3_attack_power*40);
                            }
                            else if (player3_array[2] == 9)
                            {
                                if (player3_attack_power*40 >= enemy6_health)
                                {
                                    enemy6_health = 0;
                                    bad6 = false;
                                }
                                else
                                {
                                    enemy6_health = enemy6_health - (player3_attack_power*40);
                                }
                            }
                            attack_number = player3_attack_power*40;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player3_array[0] == 2)
                        {
                            //if the magic sub selection is Freeze
                            if (player3_array[1] == 1)
                            {
                                player3_magic = player3_magic - freeze_magic;

                                if (player3_array[2] == 1)
                                {
                                    if (player3_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player3_magic_power*50 >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    if (player3_magic_power*50 >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 5)
                                {
                                    if (player3_magic_power*50*freeze >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (player3_magic_power*50*freeze);
                                    }
                                    attack_number = player3_magic_power*50*freeze;
                                }
                                else if (player3_array[2] == 6)
                                {
                                    if (player3_magic_power*50 >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 7)
                                {
                                    if (player3_magic_power*50 >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 8)
                                {
                                    if (player3_magic_power*50*freeze >= enemy5_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                        enemy5_health = enemy5_health - (player3_magic_power*50*freeze);
                                    attack_number = player3_magic_power*50*freeze;
                                }
                                else if (player3_array[2] == 9)
                                {
                                    if (player3_magic_power*50 >= enemy6_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (player3_magic_power*50);
                                    }
                                }
                                if (player3_array[2] != 5 && player3_array[2] != 8)
                                {
                                    attack_number = player3_magic_power*50;
                                }
                            }
                            //if the magic sub selection is Power X2
                            else if (player3_array[1] == 2)
                            {
                                player3_magic = player3_magic - power_magic;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player1_attack_power = player1_attack_power*2;
                                    }
                                }
                                else  if (player3_array[2] == 2)
                                {
                                    if (player2_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player2_attack_power = player2_attack_power*2;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player3_attack_power = player3_attack_power*2;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                                attack_number = 0;

                            }
                            //if the magic sub selection is LIMIT
                            else if (player3_array[1] == 3)
                            {
                                limit3_power = player3_magic;
                                player3_magic = 0;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    if (enemy1_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 5)
                                {
                                    if (enemy2_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 6)
                                {
                                    if (enemy3_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 7)
                                {
                                    if (enemy4_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 8)
                                {
                                    if (enemy5_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                    {
                                        enemy5_health = enemy5_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 9)
                                {
                                    if (enemy6_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                attack_number = limit3_power*player3_attack_power*player3_magic_power;
                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player3_array[0] == 3)
                        {
                            //if the item sub selection is hi-spirit
                            if (player3_array[1] == 1)
                            {
                                player3_item1_count = player3_item1_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health+hi_spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health+hi_spirit > player2_total_health)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                    {
                                        player2_health = player2_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health+hi_spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    enemy1_health = enemy1_health + hi_spirit;
                                }
                                else if (player3_array[2] == 5)
                                {
                                    enemy2_health = enemy2_health + hi_spirit;
                                }
                                else if (player3_array[2] == 6)
                                {
                                    enemy3_health = enemy3_health + hi_spirit;
                                }
                                else if (player3_array[2] == 7)
                                {
                                    enemy4_health = enemy4_health + hi_spirit;
                                }
                                else if (player3_array[2] == 8)
                                {
                                    enemy5_health = enemy5_health + hi_spirit;
                                }
                                else if (player3_array[2] == 9)
                                {
                                    enemy6_health = enemy6_health + hi_spirit;
                                }
                            }
                            //use this for the hi-ether
                            if (player3_array[1] == 2)
                            {
                                player3_item2_count = player3_item2_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_magic+hi_ether > player1_total_magic)
                                    {
                                        player1_magic = player1_total_magic;
                                    }
                                    else
                                    {
                                        player1_magic = player1_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_magic+hi_ether > player2_total_magic)
                                    {
                                        player2_magic = player2_total_magic;
                                    }
                                    else
                                    {
                                        player2_magic = player2_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_magic+hi_ether > player3_total_magic)
                                    {
                                        player3_magic = player3_total_magic;
                                    }
                                    else
                                    {
                                        player3_magic = player3_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                            }
                            //if the item sub selection is lazarus
                            if (player3_array[1] ==3)
                            {
                                player3_item3_count = player3_item3_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );

                        char1x = 15;
                        char2x = 15;
                        char3x = 65;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stance, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player2_health != 0)
                        {
                            apply_surface( char2x, char2y, mage_stance, screen);
                        }
                        else
                        {
                            apply_surface( char2x, char2y, mage_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_shoot, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        apply_surface( 200, 290, attack_number_text, screen );
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

                        // show the enemies
                        if (bad1 == true)
                        {
                            apply_surface( ene1x, ene1y, enemy1, screen);
                            apply_surface( 420, 160, enemy1_health_text, screen);
                        }
                        if (bad2 == true)
                        {
                            apply_surface( ene2x, ene2y, enemy2, screen);
                            apply_surface( 420, 240, enemy2_health_text, screen);
                        }
                        if (bad3 == true)
                        {
                            apply_surface( ene3x, ene3y, enemy3, screen);
                            apply_surface( 420, 300, enemy3_health_text, screen);
                        }
                        if (bad4 == true)
                        {
                            apply_surface( ene4x, ene4y, enemy4, screen);
                            apply_surface( 530, 160, enemy4_health_text, screen);
                        }
                        if (bad5 == true)
                        {
                            apply_surface( ene5x, ene5y, enemy5, screen);
                            apply_surface( 530, 240, enemy5_health_text, screen);
                        }
                        if (bad6 == true)
                        {
                            apply_surface( ene6x, ene6y, enemy6, screen);
                            apply_surface( 530, 300, enemy6_health_text, screen);
                        }

                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char3x = 15;

                    }
                }
                else if (fight_turn == 8)
                {
                    if (bad5 == true)
                    {
                        if (good1 == true && good2 == true && good3 == true)
                        {
                            enemy_random = 1 + rand() % 3;
                        }
                        else if (good1 == false)
                        {
                            if (good2 == false)
                            {
                                enemy_random = 3;
                            }
                            else if (good3 == false)
                            {
                                enemy_random = 2;
                            }
                            else
                            {
                                enemy_random = 2 + rand() %2;
                            }
                        }
                        else
                        {
                            if (good2 == false)
                            {
                                if (good3 == true)
                                {
                                    if (1+rand()%2 == 1)
                                    {
                                        enemy_random = 1;
                                    }
                                    else
                                    {
                                        enemy_random = 3;
                                    }
                                }
                                else
                                {
                                    enemy_random =1;
                                }
                            }
                            else
                            {
                                if (good3 == false)
                                {
                                    enemy_random = 1 + rand()%2;
                                }
                            }
                        }

                        if (enemy_random == 1)
                        {
                            if (enemy1_attack*30 > player1_health)
                            {
                                player1_health = 0;
                            }
                            else
                            {
                                player1_health = player1_health - enemy1_attack*30;
                            }
                        }
                        else if (enemy_random == 2)
                        {
                            if (enemy1_attack*30 > player2_health)
                            {
                                player2_health = 0;
                            }
                            else
                            {
                                player2_health = player2_health - enemy1_attack*30;
                            }
                        }
                        else if (enemy_random == 3)
                        {
                            if (enemy1_attack*30 > player3_health)
                            {
                                player3_health = 0;
                            }
                            else
                            {
                                player3_health = player3_health - enemy1_attack*30;
                            }
                        }
                        attack_number = enemy5_attack*30;
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), alertColor );

                        char1x = 15;
                        char2x = 15;
                        char3x = 15;
                        ene1x = 440;
                        ene2x = 440;
                        ene3x = 440;
                        ene4x = 550;
                        ene5x = 320;
                        ene6x = 550;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stance, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }
                        if (player2_health != 0)
                        {
                            apply_surface( char2x, char2y, mage_stance, screen);
                        }
                        else
                        {
                            apply_surface( char2x, char2y, mage_dead, screen);
                        }
                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_stance, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        if (enemy_random == 1)
                        {
                            apply_surface( 150, 140, attack_number_text, screen );
                        }
                        else if (enemy_random == 2)
                        {
                            apply_surface( 150, 210, attack_number_text, screen );
                        }
                        else if (enemy_random == 3)
                        {
                            apply_surface( 150, 290, attack_number_text, screen );
                        }

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

                        // show the enemies
                        if (bad1 == true)
                        {
                            apply_surface( ene1x, ene1y, enemy1, screen);
                            apply_surface( 420, 160, enemy1_health_text, screen);
                        }
                        if (bad2 == true)
                        {
                            apply_surface( ene2x, ene2y, enemy2, screen);
                            apply_surface( 420, 240, enemy2_health_text, screen);
                        }
                        if (bad3 == true)
                        {
                            apply_surface( ene3x, ene3y, enemy3, screen);
                            apply_surface( 420, 300, enemy3_health_text, screen);
                        }
                        if (bad4 == true)
                        {
                            apply_surface( ene4x, ene4y, enemy4, screen);
                            apply_surface( 530, 160, enemy4_health_text, screen);
                        }
                        if (bad5 == true)
                        {
                            apply_surface( ene5x, ene5y, enemy5, screen);
                            apply_surface( 530, 240, enemy5_health_text, screen);
                        }
                        if (bad6 == true)
                        {
                            apply_surface( ene6x, ene6y, enemy6, screen);
                            apply_surface( 530, 300, enemy6_health_text, screen);
                        }

                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        ene5x = 550;
                    }
                }
                else if (fight_turn == 9)
                {
                    if (bad6 == true)
                    {
                        if (good1 == true && good2 == true && good3 == true)
                        {
                            enemy_random = 1 + rand() % 3;
                        }
                        else if (good1 == false)
                        {
                            if (good2 == false)
                            {
                                enemy_random = 3;
                            }
                            else if (good3 == false)
                            {
                                enemy_random = 2;
                            }
                            else
                            {
                                enemy_random = 2 + rand() %2;
                            }
                        }
                        else
                        {
                            if (good2 == false)
                            {
                                if (good3 == true)
                                {
                                    if (1+rand()%2 == 1)
                                    {
                                        enemy_random = 1;
                                    }
                                    else
                                    {
                                        enemy_random = 3;
                                    }
                                }
                                else
                                {
                                    enemy_random =1;
                                }
                            }
                            else
                            {
                                if (good3 == false)
                                {
                                    enemy_random = 1 + rand()%2;
                                }
                            }
                        }

                        if (enemy_random == 1)
                        {
                            if (enemy1_attack*30 > player1_health)
                            {
                                player1_health = 0;
                            }
                            else
                            {
                                player1_health = player1_health - enemy1_attack*30;
                            }
                        }
                        else if (enemy_random == 2)
                        {
                            if (enemy1_attack*30 > player2_health)
                            {
                                player2_health = 0;
                            }
                            else
                            {
                                player2_health = player2_health - enemy1_attack*30;
                            }
                        }
                        else if (enemy_random == 3)
                        {
                            if (enemy1_attack*30 > player3_health)
                            {
                                player3_health = 0;
                            }
                            else
                            {
                                player3_health = player3_health - enemy1_attack*30;
                            }
                        }

                        attack_number = enemy4_attack*30;
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), alertColor );

                        char1x = 15;
                        char2x = 15;
                        char3x = 15;
                        ene1x = 440;
                        ene2x = 440;
                        ene3x = 440;
                        ene4x = 550;
                        ene5x = 550;
                        ene6x = 320;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stance, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }
                        if (player2_health != 0)
                        {
                            apply_surface( char2x, char2y, mage_stance, screen);
                        }
                        else
                        {
                            apply_surface( char2x, char2y, mage_dead, screen);
                        }
                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_stance, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        if (enemy_random == 1)
                        {
                            apply_surface( 150, 140, attack_number_text, screen );
                        }
                        else if (enemy_random == 2)
                        {
                            apply_surface( 150, 210, attack_number_text, screen );
                        }
                        else if (enemy_random == 3)
                        {
                            apply_surface( 150, 290, attack_number_text, screen );
                        }

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

                        // show the enemies
                        if (bad1 == true)
                        {
                            apply_surface( ene1x, ene1y, enemy1, screen);
                            apply_surface( 420, 160, enemy1_health_text, screen);
                        }
                        if (bad2 == true)
                        {
                            apply_surface( ene2x, ene2y, enemy2, screen);
                            apply_surface( 420, 240, enemy2_health_text, screen);
                        }
                        if (bad3 == true)
                        {
                            apply_surface( ene3x, ene3y, enemy3, screen);
                            apply_surface( 420, 300, enemy3_health_text, screen);
                        }
                        if (bad4 == true)
                        {
                            apply_surface( ene4x, ene4y, enemy4, screen);
                            apply_surface( 530, 160, enemy4_health_text, screen);
                        }
                        if (bad5 == true)
                        {
                            apply_surface( ene5x, ene5y, enemy5, screen);
                            apply_surface( 530, 240, enemy5_health_text, screen);
                        }
                        if (bad6 == true)
                        {
                            apply_surface( ene6x, ene6y, enemy6, screen);
                            apply_surface( 530, 300, enemy6_health_text, screen);
                        }

                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        ene6x = 550;
                    }
                }
                else if (fight_turn == 10)
                {
                    //now reset everything
                    if (player1_health != 0)
                    {
                        arx = 15;
                        ary = 350;
                    }
                    else if (player2_health != 0)
                    {
                        arx = 15;
                        ary = 390;
                    }
                    else if (player3_health != 0)
                    {
                        arx = 15;
                        ary = 430;
                    }
                    else
                    {
                        lose = true;
                    }
                    if (player1_health != 0)
                    {
                        good1 = true;
                    }
                    if (player2_health != 0)
                    {
                        good2 = true;
                    }
                    if (player3_health != 0)
                    {
                        good3 = true;
                    }

                    order1 = 0;
                    order2 = 0;
                    order3 = 0;

                    player1_array[0] = 0;
                    player1_array[1] = 0;
                    player1_array[2] = 0;

                    player2_array[0] = 0;
                    player2_array[1] = 0;
                    player2_array[2] = 0;

                    player3_array[0] = 0;
                    player3_array[1] = 0;
                    player3_array[2] = 0;

                    right = true;
                    left = false;
                    choose1 = 0;
                    choose2 = 0;
                    choose3 = 0;
                    choose4 = 0;
                    if (bad1 == false && bad2 == false && bad3 == false && bad4 == false && bad5 == false && bad6 == false)
                    {
                        win = true;
                    }

                    fight_turn = 0;
                    fight = false;
                }
                if (player1_health == 0)
                {
                    good1 = false;
                }
                if (player2_health == 0)
                {
                    good2 = false;
                }
                if (player3_health == 0)
                {
                    good3 = false;
                }
                if (enemy1_health == 0)
                {
                    bad1 = false;
                }
                if (enemy2_health == 0)
                {
                    bad2 = false;
                }
                if (enemy3_health == 0)
                {
                    bad3 = false;
                }
                if (enemy4_health == 0)
                {
                    bad4 = false;
                }
                if (enemy5_health == 0)
                {
                    bad5 = false;
                }
                if (enemy6_health == 0)
                {
                    bad6 = false;
                }

                fight_turn = fight_turn + 1;
                music_stop = true;
            }
            if (win == true)
            {
                if (music_stop == true)
                {
                    if ( Mix_PlayMusic(win_music, 1) == 1)
                    {
                        return 1;
                    }
                    music_stop = false;
                }

                SDL_Delay(3100);
                battle = battle + 1;
                battle_start = true;
                win = false;
            }
            if (lose == true)
            {
                if (music_stop == true)
                {
                    if ( Mix_PlayMusic(loss_music, 1) == 1)
                    {
                        return 1;
                    }
                    music_stop = false;
                }
                SDL_Delay(5500);
                battle_start = true;
                lose = false;
            }

            //Scroll background
            bgX -= .25;

            //If the background has gone too far
            if ( bgX <= -background->w )
            {
                //Reset the offset
                bgX = 0;
            }


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
                    if ( choose1 == 1 && choose2 == 2)
                    {
                        apply_surface( 505, 350, rage_text, screen );
                        apply_surface( 505, 390, fire_text, screen );
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
                        apply_surface( 505, 350, ice_text, screen );
                        apply_surface( 505, 390, hitx2_text, screen );
                        apply_surface( 505, 430, limit_text, screen );
                    }

                }
                if (choose2 == 3)
                {
                    if (choose1 == 1)
                    {
                        if (play1i == true)
                        {
                            if (play1i1 == true)
                            {
                                apply_surface( 500, 345, item_sub_selection, screen);
                                apply_surface( 505, 350, player1_spirits_text, screen);
                            }
                            if (play1i2 == true)
                            {
                                apply_surface( 500, 385, item_sub_selection, screen);
                                apply_surface( 505, 390, player1_hi_spirits_text, screen);
                            }
                            if (play1i3 == true)
                            {
                                apply_surface( 500, 425, item_sub_selection, screen);
                                apply_surface( 505, 430, player1_lazarus_text, screen);
                            }
                        }
                    }
                    else if (choose1 == 2)
                    {
                        if (choose2 == 3 && play2i == true)
                        {
                            if (play2i1 == true)
                            {
                                apply_surface( 500, 345, item_sub_selection, screen);
                                apply_surface( 505, 350, player2_ether_text, screen);
                            }
                            if (play2i2 == true)
                            {
                                apply_surface( 500, 385, item_sub_selection, screen);
                                apply_surface( 505, 390, player2_hi_ether_text, screen);
                            }
                            if (play2i3 == true)
                            {
                                apply_surface( 500, 425, item_sub_selection, screen);
                                apply_surface( 505, 430, player2_lazarus_text, screen);
                            }
                        }
                    }
                    else if (choose1 == 3)
                    {
                        if (choose2 == 3 && play3i == true)
                        {
                            if (play3i1 == true)
                            {
                                apply_surface( 500, 345, item_sub_selection, screen);
                                apply_surface( 505, 350, player3_hi_spirits_text, screen);
                            }
                            if (play3i2 == true)
                            {
                                apply_surface( 500, 385, item_sub_selection, screen);
                                apply_surface( 505, 390, player3_hi_ether_text, screen);
                            }
                            if (play3i3 == true)
                            {
                                apply_surface( 500, 425, item_sub_selection, screen);
                                apply_surface( 505, 430, player3_lazarus_text, screen);
                            }
                        }
                    }
                }
            }

            // show the characters
            // place the characters depending on which one is selected
            if (fight != true)
            {
                if ( (ary == 350 && arx ==  15) || choose1 == 1)
                {
                    char1x = 65;
                    char2x = 15;
                    char3x = 15;
                    if (player2_health == 0)
                    {
                        good2 = false;
                        apply_surface( char2x, char2y, mage_dead, screen);
                    }
                    else
                    {
                        good2 = true;
                        apply_surface( char2x, char2y, mage_stance, screen);
                    }
                    if (player3_health == 0)
                    {
                        good3 = false;
                        apply_surface( char3x, char3y, marine_dead, screen);
                    }
                    else
                    {
                        good3 = true;
                        apply_surface( char3x, char3y, marine_stance, screen);
                    }
                    apply_surface( char1x, char1y, warrior_out, screen);
                }
                else if ( ary == 390 && arx ==  15 || choose1 == 2)
                {
                    char1x = 15;
                    char2x = 65;
                    char3x = 15;
                    if (player1_health == 0)
                    {
                        good1 = false;
                        apply_surface(char1x, char1y, warrior_dead, screen);
                    }
                    else
                    {
                        good1 = true;
                        apply_surface( char1x, char1y, warrior_stance, screen);
                    }
                    if (player3_health == 0)
                    {
                        good3 = false;
                        apply_surface( char3x, char3y, marine_dead, screen);
                    }
                    else
                    {
                        good3 = true;
                        apply_surface( char3x, char3y, marine_stance, screen);
                    }
                    apply_surface( char2x, char2y, mage_out, screen);
                }
                else if ( ary == 430 && arx ==  15 || choose1 == 3)
                {
                    char1x = 15;
                    char2x = 15;
                    char3x = 65;

                    if (player1_health == 0)
                    {
                        good1 = false;
                        apply_surface( char1x, char1y, warrior_dead, screen);
                    }
                    else
                    {
                        good1 = true;
                        apply_surface( char1x, char1y, warrior_stance, screen);
                    }
                    if (player2_health == 0)
                    {
                        good2 = false;
                        apply_surface( char2x, char2y, mage_dead, screen);
                    }
                    else
                    {
                        good2 = true;
                        apply_surface( char2x, char2y, mage_stance, screen);
                    }
                    apply_surface( char3x, char3y, marine_out, screen);

                }
            }



            // show the enemies
            if (bad1 == true)
            {
                apply_surface( ene1x, ene1y, enemy1, screen);
                apply_surface( 420, 160, enemy1_health_text, screen);
            }
            if (bad2 == true)
            {
                apply_surface( ene2x, ene2y, enemy2, screen);
                apply_surface( 420, 240, enemy2_health_text, screen);
            }
            if (bad3 == true)
            {
                apply_surface( ene3x, ene3y, enemy3, screen);
                apply_surface( 420, 300, enemy3_health_text, screen);
            }
            if (bad4 == true)
            {
                apply_surface( ene4x, ene4y, enemy4, screen);
                apply_surface( 530, 160, enemy4_health_text, screen);
            }
            if (bad5 == true)
            {
                apply_surface( ene5x, ene5y, enemy5, screen);
                apply_surface( 530, 240, enemy5_health_text, screen);
            }
            if (bad6 == true)
            {
                apply_surface( ene6x, ene6y, enemy6, screen);
                apply_surface( 530, 300, enemy6_health_text, screen);
            }

// show the arrow
            if ( right == true )
            {
                apply_surface( arx, ary, arrow_right, screen);
            }
            if ( left == true)
            {
                apply_surface(arx, ary, arrow_left, screen);
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

            //the players particular items as a string
            std::stringstream play1item1;
            std::stringstream play1item2;
            std::stringstream play1item3;
            std::stringstream play2item1;
            std::stringstream play2item2;
            std::stringstream play2item3;
            std::stringstream play3item1;
            std::stringstream play3item2;
            std::stringstream play3item3;

            //the enemy health as a string
            std::stringstream enemy1ph;
            std::stringstream enemy2ph;
            std::stringstream enemy3ph;
            std::stringstream enemy4ph;
            std::stringstream enemy5ph;
            std::stringstream enemy6ph;


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

            //convert the enemy health
            enemy1ph << enemy1_health;
            enemy2ph << enemy2_health;
            enemy3ph << enemy3_health;
            enemy4ph << enemy4_health;
            enemy5ph << enemy5_health;
            enemy6ph << enemy6_health;

            //convert to string
            enemy1_health_text = TTF_RenderText_Solid( font_small, enemy1ph.str().c_str(), textColor );
            enemy2_health_text = TTF_RenderText_Solid( font_small, enemy2ph.str().c_str(), textColor );
            enemy3_health_text = TTF_RenderText_Solid( font_small, enemy3ph.str().c_str(), textColor );
            enemy4_health_text = TTF_RenderText_Solid( font_small, enemy4ph.str().c_str(), textColor );
            enemy5_health_text = TTF_RenderText_Solid( font_small, enemy5ph.str().c_str(), textColor );
            enemy6_health_text = TTF_RenderText_Solid( font_small, enemy6ph.str().c_str(), textColor );



            //convert the players items and numbers into a string
            play1item1 << "SPIRIT[" << player1_item1_count << "]";
            play1item2 << "HI-SPIRIT[" << player1_item2_count << "]";
            play1item3 << "LAZARUS[" << player1_item3_count << "]";

            play2item1 << "ETHER[" << player2_item1_count << "]";
            play2item2 << "HI-ETHER[" << player2_item2_count << "]";
            play2item3 << "LAZARUS[" << player2_item3_count << "]";

            play3item1 << "HI-SPIRIT[" << player3_item1_count << "]";
            play3item2 << "HI-ETHER[" << player3_item2_count << "]";
            play3item3 << "LAZARUS[" << player3_item3_count << "]";





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
            character1_name = TTF_RenderText_Solid( font, "Knight", textColor );
            character2_name = TTF_RenderText_Solid( font, "D-Mage", textColor );
            character3_name = TTF_RenderText_Solid( font, "Marine", textColor );
            //character 1 magic text
            rage_text = TTF_RenderText_Solid( font, "RAGE", textColor );
            hitx2_text = TTF_RenderText_Solid( font, "POWER X2", textColor );
            limit_text = TTF_RenderText_Solid( font, "LIMIT", textColor );
            //character2 magic text
            fire_text = TTF_RenderText_Solid( font, "BURN", textColor );
            ice_text = TTF_RenderText_Solid( font, "FREEZE", textColor );

            //the names of items
            player1_spirits_text = TTF_RenderText_Solid( font, play1item1.str().c_str(), textColor );
            player1_hi_spirits_text = TTF_RenderText_Solid( font, play1item2.str().c_str(), textColor );
            player1_lazarus_text = TTF_RenderText_Solid( font, play1item3.str().c_str(), textColor );
            player2_ether_text = TTF_RenderText_Solid( font, play2item1.str().c_str(), textColor );
            player2_hi_ether_text = TTF_RenderText_Solid( font, play2item2.str().c_str(), textColor );
            player2_lazarus_text = TTF_RenderText_Solid( font, play2item3.str().c_str(), textColor );
            player3_hi_spirits_text = TTF_RenderText_Solid( font, play3item1.str().c_str(), textColor );
            player3_hi_ether_text = TTF_RenderText_Solid( font, play3item2.str().c_str(), textColor );
            player3_lazarus_text = TTF_RenderText_Solid( font, play3item3.str().c_str(), textColor );


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
            if ( SDL_Flip( screen ) == -1 )
            {
                return 1;
            }

            //Cap the frame rate
            if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
            {
                SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
            }
        }
        while (boss1_text == true)
        {
            if ( Mix_PlayingMusic() == 0 )
            {
                title_time.start();
                //Play the music
                if ( Mix_PlayMusic( walking, -1 ) == 1 )
                {
                    return 1;
                }
            }

            //Apply the surface to the screen
            apply_surface(bgX, bgY, sky, screen );
            apply_surface( bgX + background->w, bgY, sky, screen );

            apply_surface( 0, 0, background, screen );
            apply_surface( 0, 330, command_background, screen );
            apply_surface( 50, 345, character_background, screen);
            apply_surface( 50, 385, character_background, screen);
            apply_surface( 50, 425, character_background, screen);
            apply_surface( 170, 345, health_counter, screen);
            apply_surface( 220, 345, magic_counter, screen);


            //While there's an event to handle
            while ( SDL_PollEvent( &event ) )
            {
                //If a key was pressed
                if ( event.type == SDL_KEYDOWN )
                {
                    switch ( event.key.keysym.sym )
                    {
                    case SDLK_a:
                    {
                        text_counter = text_counter + 1;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                    }
                }
                //If the user has Xed out the window
                if ( event.type == SDL_QUIT )
                {
                    //Quit the program
                    boss1_text = false;
                }
            }
            if (text_counter == 19)
            {
                char1x = 15;
                char2x = 65;
                char3x = 15;

                apply_surface(ene2x, ene2y, enemy1, screen);
                apply_surface(100, 100, blerb19, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char2x, char2y, mage_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);

            }
            if (text_counter == 20)
            {
                char1x = 15;
                char2x = 65;
                char3x = 15;

                apply_surface(ene2x, ene2y, enemy1, screen);
                apply_surface(200, 100, blerb20, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char2x, char2y, mage_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);

            }
            if (text_counter == 21)
            {
                char1x = 15;
                char2x = 65;
                char3x = 15;

                apply_surface(ene2x, ene2y, enemy1, screen);
                apply_surface(100, 100, blerb21, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(char2x, char2y, mage_stab, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 22)
            {
                char1x = 65;
                char2x = 250;
                char3x = 15;

                apply_surface(ene2x, ene2y, enemy1dead, screen);
                apply_surface(100, 50, blerb22, screen);
                apply_surface(char1x, char1y, warrior_out, screen);
                apply_surface(char2x, char2y, mage_stance, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 23)
            {
                char1x = 15;
                char3x = 65;

                apply_surface(100, 190, blerb23, screen);
                apply_surface(char1x, char1y, warrior_out, screen);
                apply_surface(ene2x, ene2y, mage_left, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 24)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(200, 100, blerb24, screen);
                apply_surface(char1x, char1y, warrior_out, screen);
                apply_surface(ene2x, ene2y, mage_left, screen);
                apply_surface(char3x, char3y, marine_out, screen);
            }
            if (text_counter == 25)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(340, 120, blerb25, screen);
                apply_surface(char1x, char1y, warrior_out, screen);
                apply_surface(ene2x, ene2y, mage_left, screen);
                apply_surface(char3x, char3y, marine_out, screen);
            }
            if (text_counter == 26)
            {
                if ( Mix_PlayingMusic() != 0 )
                {
                    //Pause the music
                    Mix_HaltMusic();
                }
                boss1_text = false;
                boss1 = true;
            }

            //Update the screen
            if ( SDL_Flip( screen ) == -1 )
            {
                return 1;
            }

            //Cap the frame rate
            if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
            {
                SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
            }

        }
        while (boss1 == true)
        {

            if ( Mix_PlayingMusic() == 0 )
            {
                //Play the music
                if ( Mix_PlayMusic( hood_on, -1 ) == 1 )
                {
                    return 1;
                }
            }

            //Start the frame timer
            fps.start();

            //Apply the surface to the screen
            apply_surface(bgX, bgY, sky, screen );
            apply_surface( bgX + background->w, bgY, sky, screen );

            apply_surface( 0, 0, background, screen );
            apply_surface( 0, 330, command_background, screen );
            apply_surface( 50, 345, character_background, screen);
            apply_surface( 50, 385, character_background, screen);
            apply_surface( 50, 425, character_background, screen);
            apply_surface( 170, 345, health_counter, screen);
            apply_surface( 220, 345, magic_counter, screen);




            //While there's an event to handle
            while ( SDL_PollEvent( &event ) )
            {
                //If a key was pressed
                if ( event.type == SDL_KEYDOWN )
                {
                    switch ( event.key.keysym.sym )
                    {
                    case SDLK_UP:
                    {

                        //selecting the characters
                        if (arx == 15)
                        {
                            if (ary == 350)
                            {
                                if (order1 == 3 || good3 == false)
                                {
                                    break;
                                }
                                else
                                {
                                    ary = 430;
                                    break;
                                }
                            }
                            else if (ary == 430)
                            {
                                if (order1 == 1 || good1 == false)
                                {
                                    break;
                                }
                                else
                                {
                                    ary = 350;
                                    break;
                                }
                            }
                        }
                        //this is for selecting primaries and subs
                        else if ( ary >= 350)
                        {
                            if (arx != 15 && ary != 350)
                            {
                                ary = ary - 40;
                                break;
                            }
                            else
                            {
                                ary = 430;
                                break;
                            }
                        }
                        // this is for selecting who will receive the action
                        else if (ary < 350)
                        {
                            if (arx == 140)
                            {
                                if (ary == 110)
                                {
                                    ary = 270;
                                    break;
                                }
                                else if (ary == 270)
                                {
                                    ary = 110;
                                    break;
                                }
                            }
                            else if (arx = 415)
                            {
                                break;
                            }

                        }
                    }
                    case SDLK_DOWN:
                    {

                        if (arx == 15)
                        {
                            if (ary == 350)
                            {
                                if (order1 == 3 || good3 == false)
                                {
                                    break;
                                }
                                else
                                {
                                    ary = 430;
                                    break;
                                }
                            }
                            else if (ary == 430)
                            {
                                if (order1 == 1 || good1 == false)
                                {
                                    break;
                                }
                                else
                                {
                                    ary = 350;
                                    break;
                                }
                            }


                        }
                        else if (ary >= 350)
                        {
                            if (arx != 15 && ary != 430)
                            {
                                ary = ary + 40;
                                break;
                            }
                            else
                            {
                                ary = 350;
                                break;
                            }
                        }
                        //this is for selecting who will receive the action
                        else if (ary < 350)
                        {
                            if (arx == 140)
                            {
                                if (ary == 110)
                                {
                                    ary = 270;
                                    break;
                                }
                                else if (ary == 270)
                                {
                                    ary = 110;
                                    break;
                                }
                            }
                            else if (arx = 415)
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    case SDLK_RIGHT:
                    {
                        //moving from the characters to the boss
                        if (ary < 350 && arx == 140)
                        {
                            arx = 415;
                            ary = 180;
                            right = true;
                            left = false;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    case SDLK_LEFT:
                    {
                        if (arx == 415)
                        {
                            arx = 140;
                            ary = 110;
                            right = false;
                            left = true;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    case SDLK_a:
                    {
                        if (fight == false)
                        {
                            // check first for target selection
                            if ( ary < 350 )
                            {
                                //if the first character is selected
                                if ( arx == 140 && ary == 110)
                                {
                                    choose4 = 1;
                                }
                                //if the last character is selected
                                else if ( arx == 140 && ary == 270)
                                {
                                    choose4 = 3;
                                }
                                //if the boss is selected
                                else if ( arx == 415 && ary == 180)
                                {
                                    choose4 = 5;
                                }
                                if (choose1 == 1)
                                {
                                    player1_array[0] = choose2;
                                    player1_array[1] = choose3;
                                    player1_array[2] = choose4;
                                }
                                else if (choose1 == 3)
                                {
                                    player3_array[0] = choose2;
                                    player3_array[1] = choose3;
                                    player3_array[2] = choose4;
                                }
                                if (order1==0)
                                {
                                    order1 = choose1;
                                    if (order1 == 1 && player2_health != 0)
                                    {
                                        arx = 15;
                                        ary =430;
                                    }
                                    else if (order1 == 1 && player2_health == 0)
                                    {
                                        good2 = false;
                                        fight = true;
                                    }
                                    if (order1 == 2 && player1_health != 0)
                                    {
                                        arx = 15;
                                        ary = 350;
                                    }
                                    else if (order1 == 2 && player1_health == 0)
                                    {
                                        good1 = false;
                                        fight = true;
                                    }
                                    right = true;
                                    left = false;
                                    choose1 = 0;
                                    choose2 = 0;
                                    choose3 = 0;
                                    choose4 = 0;
                                    break;
                                }
                                else if (order2==0)
                                {
                                    order2 = choose1;
                                    fight = true;

                                    right = true;
                                    left = false;
                                    choose1 = 0;
                                    choose2 = 0;
                                    choose3 = 0;
                                    choose4 = 0;
                                }

                            }
                            //check second for sub selection
                            else if (arx == 445)
                            {
                                if (choose2 == 2 && (player1_magic == 0 || player3_magic == 0))
                                {
                                    if (choose1 == 1)
                                    {
                                        if (choose2 == 2 && player1_magic == 0)
                                        {
                                            break;
                                        }

                                    }
                                    else if (choose1 == 3)
                                    {
                                        if (choose2 == 2 && player3_magic == 0)
                                        {
                                            break;
                                        }

                                    }
                                }
                                if ((choose1 == 1 && choose2 == 3) && (player1_item1_count == 0 || player1_item3_count == 0))
                                {
                                    if (ary == 350 && player1_item1_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 390 && player1_item2_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 430 && player1_item3_count == 0)
                                    {
                                        break;
                                    }
                                }
                                else if ((choose1 == 2 && choose2 == 3) && (player2_item1_count == 0 || player3_item3_count == 0))
                                {
                                    if (ary == 350 && player2_item1_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 390 && player2_item2_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 430 && player2_item3_count == 0)
                                    {
                                        break;
                                    }
                                }
                                else if ((choose1 == 3 && choose2 == 3) &&(player3_item1_count == 0 || player3_item3_count == 0))
                                {
                                    if (ary == 350 && player3_item1_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 390 && player3_item2_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 430 && player3_item3_count == 0)
                                    {
                                        break;
                                    }
                                }
                                if ( choose2 == 2 )
                                {
                                    if (ary == 350)
                                    {
                                        choose3 = 1;
                                        arx = 415;
                                        ary = 180;
                                        right = true;
                                        left = false;
                                        break;
                                    }
                                    if (ary == 390)
                                    {
                                        choose3 = 2;
                                        arx = 415;
                                        ary = 180;
                                        right = true;
                                        left = false;
                                        break;
                                    }
                                    if (ary == 430)
                                    {
                                        choose3 = 3;
                                        arx = 415;
                                        ary = 180;
                                        right = true;
                                        left = false;
                                        break;
                                    }
                                }
                                else if (choose2 == 3)
                                {
                                    if (ary == 350)
                                    {
                                        choose3 = 1;
                                        arx = 140;
                                        ary = 110;
                                        right = false;
                                        left = true;
                                        break;
                                    }
                                    else if (ary == 390)
                                    {
                                        choose3 = 2;
                                        arx = 140;
                                        ary = 110;
                                        right = false;
                                        left = true;
                                        break;
                                    }
                                    else if (ary == 430)
                                    {
                                        choose3 = 3;
                                        arx = 140;
                                        ary = 110;
                                        right = false;
                                        left = true;
                                        break;
                                    }
                                }


                            }

                            // check third for primary selection
                            else if (arx == 280)
                            {
                                //this one is the attack one, it is special because it has no sub selection
                                if ( ary == 350 )
                                {
                                    choose2 = 1;
                                    arx = 415;
                                    ary = 180;
                                    right = true;
                                    left = false;
                                    break;
                                }
                                // now back to the other options
                                else if ( ary == 390 )
                                {
                                    choose2 = 2;
                                    arx = 445;
                                    ary = 350;
                                    break;
                                }
                                else if ( ary == 430 )
                                {
                                    if (choose1 == 1)
                                    {
                                        if (play1i == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            choose2 = 3;
                                            arx = 445;
                                            ary = 350;
                                            break;
                                        }
                                    }
                                    else if (choose1 == 2)
                                    {
                                        if (play2i == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            choose2 = 3;
                                            arx = 445;
                                            ary = 350;
                                            break;
                                        }
                                    }
                                    else if (choose1 == 3)
                                    {
                                        if (play3i == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            choose2 = 3;
                                            arx = 445;
                                            ary = 350;
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }

                            // check last for character selection
                            else if (arx == 15)
                            {
                                if ( ary == 350 )
                                {
                                    choose1 = 1;
                                    ary = 350;
                                    arx = 280;
                                    break;
                                }
                                if ( ary == 390 )
                                {
                                    choose1 = 2;
                                    ary = 350;
                                    arx = 280;
                                    break;
                                }
                                if ( ary == 430 )
                                {
                                    choose1 = 3;
                                    ary = 350;
                                    arx = 280;
                                    break;
                                }
                                else
                                {
                                    break;
                                }
                            }

                            else
                            {
                                break;
                            }

                        }
                    }
                    case SDLK_s:
                    {
                        //go back and undo sub selection
                        if (ary < 350 && choose3 == 0)
                        {
                            arx = 280;
                            ary = 350;
                            choose2 = 0;
                            right = true;
                            left = false;
                            break;
                        }
                        if (ary < 350 && choose3 == 1)
                        {
                            arx = 445;
                            ary = 350;
                            choose3 = 0;
                            right = true;
                            left = false;
                            break;
                        }
                        if (ary < 350 && choose3 == 2)
                        {
                            arx = 445;
                            ary = 390;
                            choose3 = 0;
                            right = true;
                            left = false;
                            break;
                        }
                        if (ary < 350 && choose3 == 3)
                        {
                            arx = 445;
                            ary = 430;
                            choose3 = 0;
                            right = true;
                            left = false;
                            break;
                        }
                        //go back and undo primary selection
                        if ( arx == 445 && choose2 == 1)
                        {
                            arx = 280;
                            ary = 350;
                            choose2 = 0;
                            break;
                        }
                        if ( arx == 445 && choose2 == 2)
                        {
                            arx = 280;
                            ary = 390;
                            choose2 = 0;
                            break;
                        }
                        if ( arx == 445 && choose2 == 3)
                        {
                            arx = 280;
                            ary = 430;
                            choose2 = 0;
                            break;
                        }
                        //go back and undo character selection
                        if ( arx == 280 && choose1 == 1)
                        {
                            arx = 15;
                            ary = 350;
                            choose1 = 0;
                            break;
                        }
                        if ( arx == 280 && choose1 == 2)
                        {
                            arx = 15;
                            ary = 390;
                            choose1 = 0;
                            break;
                        }
                        if ( arx == 280 && choose1 == 3)
                        {
                            arx = 15;
                            ary = 430;
                            choose1 = 0;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    case SDLK_d:
                    {
                        break;
                    }
                    case SDLK_f:
                    {
                        bad1 = false;
                        bad2 = false;
                        bad3 = false;
                        bad4 = false;
                        bad5 = false;
                        bad6 = true;

                    }
                    default:
                    {
                        break;
                    }
                    }
                }
            }
            //If the user has Xed out the window
            if ( event.type == SDL_QUIT )
            {
                //Quit the program
                boss1 = false;
            }

            if (fight == true)
            {

                if (boss_health != 0)
                {
                    evil = false;
                }
                else
                {
                    evil = true;
                }

                if (fight_turn == 1 && evil == false)
                {
                    if (order1 == 1)
                    {
                        //if the primary choice is attack then find the target and calculate the results
                        if (player1_array[0] == 1)
                        {
                            if (player1_array[2] == 1)
                            {
                                if (player1_attack_power*50 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 3)
                            {
                                if (player1_attack_power*50 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 5)
                            {
                                if (player1_attack_power*50 >= boss_health)
                                {
                                    boss_health = 0;
                                }
                                else
                                {
                                    boss_health = boss_health - (player1_attack_power*50);
                                }
                            }
                            attack_number = player1_attack_power*50;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player1_array[0] == 2)
                        {
                            //if the magic sub selection is Rage
                            if (player1_array[1] == 1)
                            {
                                player1_magic = player1_magic - rage_magic;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_attack_power*50*rage >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player1_attack_power*50*rage >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (player1_attack_power*50*rage >= boss_health)
                                    {
                                        boss_health = 0;
                                    }
                                    else
                                    {
                                        boss_health = boss_health -(player1_attack_power*50*rage);
                                    }
                                }

                                attack_number = player1_attack_power*50*rage;
                            }
                            //if the magic sub selection is Burn
                            if (player1_array[1] == 2)
                            {
                                player1_magic = player1_magic - burn_magic;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player1_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (player1_magic_power*50 >= boss_health)
                                    {
                                        enemy2_health = 0;
                                    }
                                    else
                                    {
                                        boss_health = boss_health - (player1_magic_power*50);
                                    }
                                }
                                attack_number = player1_magic_power*50;
                            }
                            //if the magic sub selection is LIMIT
                            else if (player1_array[1] == 3)
                            {
                                limit1_power = player1_magic;
                                player1_magic = 0;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (boss_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        boss_health = 0;
                                    }
                                    else
                                    {
                                        boss_health = boss_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                attack_number = limit1_power*player1_attack_power*player1_magic_power;
                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player1_array[0] == 3)
                        {
                            //if the item sub selection is spirit
                            if (player1_array[1] == 1)
                            {
                                player1_item1_count = player1_item1_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player1_health+spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player3_health+spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    boss_health = boss_health + spirit;
                                }
                            }
                            //if the item sub selection is hi-spirit
                            if (player1_array[1] == 2)
                            {
                                player1_item2_count = player1_item2_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player1_health+hi_spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player3_health+hi_spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    boss_health = boss_health + hi_spirit;
                                }
                            }
                            //if the item sub selection is lazarus
                            if (player1_array[1] ==3)
                            {
                                player1_item3_count = player1_item3_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 5)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );


                        char1x = 65;
                        char3x = 15;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stab, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_stance, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        apply_surface( ene2x, ene2y, mage_left, screen);
                        apply_surface( 400, 250, boss_health_text, screen );

                        //apply character 1 text
                        apply_surface( 183, 347, character1_health, screen );
                        apply_surface( 183, 367, character1_total_health, screen );
                        apply_surface( 237, 347, character1_magic, screen );
                        apply_surface( 237, 367, character1_total_magic, screen );
                        apply_surface( 60, 355, character1_name, screen );

                        //apply character 3 text
                        apply_surface( 183, 427, character3_health, screen );
                        apply_surface( 183, 447, character3_total_health, screen );
                        apply_surface( 237, 427, character3_magic, screen );
                        apply_surface( 237, 447, character3_total_magic, screen );
                        apply_surface( 60, 435, character3_name, screen );

                        apply_surface( 150, 140, attack_number_text, screen );


                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char1x = 15;
                    }
                    else if (order1 == 2)
                    {
                        char3x = 65;
                        //the animations will go right here
                        //if the primary choice is attack then find the target and calculate the results
                        if (player3_array[0] == 1)
                        {
                            if (player3_array[2] == 1)
                            {
                                if (player3_attack_power*40 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 2)
                            {
                                if (player3_attack_power*40 >= player2_health)
                                {
                                    player2_health = 0;
                                }
                                else
                                {
                                    player2_health = player2_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 3)
                            {
                                if (player3_attack_power*40 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 4)
                            {
                                if (player3_attack_power*40 >= enemy1_health)
                                {
                                    enemy1_health = 0;
                                    bad1 = false;
                                }
                                else
                                {
                                    enemy1_health = enemy1_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 5)
                            {
                                if (player3_attack_power*40 >= enemy2_health)
                                {
                                    enemy2_health = 0;
                                    bad2 = false;
                                }
                                else
                                {
                                    enemy2_health = enemy2_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 6)
                            {
                                if (player3_attack_power*40 >= enemy3_health)
                                {
                                    enemy3_health = 0;
                                    bad3 = false;
                                }
                                else
                                {
                                    enemy3_health = enemy3_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 7)
                            {
                                if (player3_attack_power*40 >= enemy4_health)
                                {
                                    enemy4_health = 0;
                                    bad4 = false;
                                }
                                else
                                {
                                    enemy4_health = enemy4_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 8)
                            {
                                if (player3_attack_power*40 >= enemy5_health)
                                {
                                    enemy5_health = 0;
                                    bad5 = false;
                                }
                                else
                                    enemy5_health = enemy5_health - (player3_attack_power*40);
                            }
                            else if (player3_array[2] == 9)
                            {
                                if (player3_attack_power*40 >= enemy6_health)
                                {
                                    enemy6_health = 0;
                                    bad6 = false;
                                }
                                else
                                {
                                    enemy6_health = enemy6_health - (player3_attack_power*40);
                                }
                            }
                            attack_number = player3_attack_power*40;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player3_array[0] == 2)
                        {
                            //if the magic sub selection is Freeze
                            if (player3_array[1] == 1)
                            {
                                player3_magic = player3_magic - freeze_magic;

                                if (player3_array[2] == 1)
                                {
                                    if (player3_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player3_magic_power*50 >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    if (player3_magic_power*50 >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 5)
                                {
                                    if (player3_magic_power*50*freeze >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (player3_magic_power*50*freeze);
                                    }
                                    attack_number = player3_magic_power*50*freeze;
                                }
                                else if (player3_array[2] == 6)
                                {
                                    if (player3_magic_power*50 >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 7)
                                {
                                    if (player3_magic_power*50 >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 8)
                                {
                                    if (player3_magic_power*50*freeze >= enemy5_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                        enemy5_health = enemy5_health - (player3_magic_power*50*freeze);
                                    attack_number = player3_magic_power*50*freeze;
                                }
                                else if (player3_array[2] == 9)
                                {
                                    if (player3_magic_power*50 >= enemy6_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (player3_magic_power*50);
                                    }
                                }
                                if (player3_array[2] != 5 && player3_array[2] != 8)
                                {
                                    attack_number = player3_magic_power*50;
                                }
                            }
                            //if the magic sub selection is Power X2
                            else if (player3_array[1] == 2)
                            {
                                player3_magic = player3_magic - power_magic;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player1_attack_power = player1_attack_power*2;
                                    }
                                }
                                else  if (player3_array[2] == 2)
                                {
                                    if (player2_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player2_attack_power = player2_attack_power*2;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player3_attack_power = player3_attack_power*2;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                                attack_number = 0;

                            }
                            //if the magic sub selection is LIMIT
                            else if (player3_array[1] == 3)
                            {
                                limit3_power = player3_magic;
                                player3_magic = 0;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    if (enemy1_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 5)
                                {
                                    if (enemy2_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 6)
                                {
                                    if (enemy3_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 7)
                                {
                                    if (enemy4_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 8)
                                {
                                    if (enemy5_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                    {
                                        enemy5_health = enemy5_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 9)
                                {
                                    if (enemy6_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                attack_number = limit3_power*player3_attack_power*player3_magic_power;
                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player3_array[0] == 3)
                        {
                            //if the item sub selection is hi-spirit
                            if (player3_array[1] == 1)
                            {
                                player3_item1_count = player3_item1_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health+hi_spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health+hi_spirit > player2_total_health)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                    {
                                        player2_health = player2_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health+hi_spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    enemy1_health = enemy1_health + hi_spirit;
                                }
                                else if (player3_array[2] == 5)
                                {
                                    enemy2_health = enemy2_health + hi_spirit;
                                }
                                else if (player3_array[2] == 6)
                                {
                                    enemy3_health = enemy3_health + hi_spirit;
                                }
                                else if (player3_array[2] == 7)
                                {
                                    enemy4_health = enemy4_health + hi_spirit;
                                }
                                else if (player3_array[2] == 8)
                                {
                                    enemy5_health = enemy5_health + hi_spirit;
                                }
                                else if (player3_array[2] == 9)
                                {
                                    enemy6_health = enemy6_health + hi_spirit;
                                }
                            }
                            //use this for the hi-ether
                            if (player3_array[1] == 2)
                            {
                                player3_item2_count = player3_item2_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_magic+hi_ether > player1_total_magic)
                                    {
                                        player1_magic = player1_total_magic;
                                    }
                                    else
                                    {
                                        player1_magic = player1_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_magic+hi_ether > player2_total_magic)
                                    {
                                        player2_magic = player2_total_magic;
                                    }
                                    else
                                    {
                                        player2_magic = player2_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_magic+hi_ether > player3_total_magic)
                                    {
                                        player3_magic = player3_total_magic;
                                    }
                                    else
                                    {
                                        player3_magic = player3_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                            }
                            //if the item sub selection is lazarus
                            if (player3_array[1] ==3)
                            {
                                player3_item3_count = player3_item3_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );


                        char1x = 65;
                        char3x = 15;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stance, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_shoot, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        apply_surface( ene2x, ene2y, mage_left, screen);
                        apply_surface( 400, 250, boss_health_text, screen );

                        //apply character 1 text
                        apply_surface( 183, 347, character1_health, screen );
                        apply_surface( 183, 367, character1_total_health, screen );
                        apply_surface( 237, 347, character1_magic, screen );
                        apply_surface( 237, 367, character1_total_magic, screen );
                        apply_surface( 60, 355, character1_name, screen );

                        //apply character 3 text
                        apply_surface( 183, 427, character3_health, screen );
                        apply_surface( 183, 447, character3_total_health, screen );
                        apply_surface( 237, 427, character3_magic, screen );
                        apply_surface( 237, 447, character3_total_magic, screen );
                        apply_surface( 60, 435, character3_name, screen );

                        apply_surface( 150, 140, attack_number_text, screen );


                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char3x = 15;
                    }
                }
                else if (fight_turn == 2)
                {
                    if (good1 == true && good3 == true)
                    {
                        enemy_random = 1 + rand() % 2;
                    }
                    else if (good1 == false)
                    {
                        enemy_random = 2;
                    }
                    else if (good2 == false)
                    {
                        enemy_random = 1;
                    }
                    attack_number = boss_power*30;
                    if (enemy_random == 1)
                    {
                        if (player1_health < boss_power*30)
                        {
                            player1_health =0;
                        }
                        else
                        {
                            player1_health = player1_health - boss_power*30;
                        }
                    }
                    else if (enemy_random == 2)
                    {
                        if (player3_health < boss_power*30)
                        {
                            player3_health =0;
                        }
                        else
                        {
                            player3_health = player3_health - boss_power*30;
                        }
                    }

                    attack_number = enemy1_attack*30;

                    std::stringstream attack_value;
                    attack_value << attack_number;
                    attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), alertColor );

                    char1x = 15;
                    char3x = 15;
                    apply_surface(bgX, bgY, sky, screen );
                    apply_surface( bgX + background->w, bgY, sky, screen );

                    apply_surface( 0, 0, background, screen );
                    apply_surface( 0, 330, command_background, screen );
                    apply_surface( 50, 345, character_background, screen);
                    apply_surface( 50, 385, character_background, screen);
                    apply_surface( 50, 425, character_background, screen);
                    apply_surface( 170, 345, health_counter, screen);
                    apply_surface( 220, 345, magic_counter, screen);

                    if (player1_health != 0)
                    {
                        apply_surface( char1x, char1y, warrior_stance, screen);
                    }
                    else
                    {
                        apply_surface( char1x, char1y, warrior_dead, screen);
                    }

                    if (player3_health != 0)
                    {
                        apply_surface( char3x, char3y, marine_stance, screen);
                    }
                    else
                    {
                        apply_surface( char3x, char3y, marine_dead, screen);
                    }

                    if (enemy_random == 1)
                    {
                        apply_surface( 150, 140, attack_number_text, screen );
                    }
                    else if (enemy_random == 2)
                    {
                        apply_surface( 150, 290, attack_number_text, screen );
                    }

                    apply_surface(ene2x, ene2y, mage_left_stab, screen);
                    apply_surface(400, 250, boss_health_text, screen);


                    //apply character 1 text
                    apply_surface( 183, 347, character1_health, screen );
                    apply_surface( 183, 367, character1_total_health, screen );
                    apply_surface( 237, 347, character1_magic, screen );
                    apply_surface( 237, 367, character1_total_magic, screen );
                    apply_surface( 60, 355, character1_name, screen );

                    //apply character 3 text
                    apply_surface( 183, 427, character3_health, screen );
                    apply_surface( 183, 447, character3_total_health, screen );
                    apply_surface( 237, 427, character3_magic, screen );
                    apply_surface( 237, 447, character3_total_magic, screen );
                    apply_surface( 60, 435, character3_name, screen );


                    //Update the screen
                    if ( SDL_Flip( screen ) == -1 )
                    {
                        return 1;
                    }

                    //Cap the frame rate
                    if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                    {
                        SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                    }

                    SDL_Delay(1000);
                    attack_number = 0;
                    bossx = 440;
                    bossy = 190;
                }
                else if (fight_turn == 3 && evil == false)
                {
                    if (order2 == 1)
                    {
                        //if the primary choice is attack then find the target and calculate the results
                        if (player1_array[0] == 1)
                        {
                            if (player1_array[2] == 1)
                            {
                                if (player1_attack_power*50 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 3)
                            {
                                if (player1_attack_power*50 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 5)
                            {
                                if (player1_attack_power*50 >= boss_health)
                                {
                                    boss_health = 0;
                                }
                                else
                                {
                                    boss_health = boss_health - (player1_attack_power*50);
                                }
                            }
                            attack_number = player1_attack_power*50;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player1_array[0] == 2)
                        {
                            //if the magic sub selection is Rage
                            if (player1_array[1] == 1)
                            {
                                player1_magic = player1_magic - rage_magic;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_attack_power*50*rage >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player1_attack_power*50*rage >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (player1_attack_power*50*rage >= boss_health)
                                    {
                                        boss_health = 0;
                                    }
                                    else
                                    {
                                        boss_health = boss_health -(player1_attack_power*50*rage);
                                    }
                                }

                                attack_number = player1_attack_power*50*rage;
                            }
                            //if the magic sub selection is Burn
                            if (player1_array[1] == 2)
                            {
                                player1_magic = player1_magic - burn_magic;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player1_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (player1_magic_power*50 >= boss_health)
                                    {
                                        enemy2_health = 0;
                                    }
                                    else
                                    {
                                        boss_health = boss_health - (player1_magic_power*50);
                                    }
                                }
                                attack_number = player1_magic_power*50;
                            }
                            //if the magic sub selection is LIMIT
                            else if (player1_array[1] == 3)
                            {
                                limit1_power = player1_magic;
                                player1_magic = 0;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (boss_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        boss_health = 0;
                                    }
                                    else
                                    {
                                        boss_health = boss_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                attack_number = limit1_power*player1_attack_power*player1_magic_power;
                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player1_array[0] == 3)
                        {
                            //if the item sub selection is spirit
                            if (player1_array[1] == 1)
                            {
                                player1_item1_count = player1_item1_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player1_health+spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player3_health+spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    boss_health = boss_health + spirit;
                                }
                            }
                            //if the item sub selection is hi-spirit
                            if (player1_array[1] == 2)
                            {
                                player1_item2_count = player1_item2_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player1_health+hi_spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player3_health+hi_spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    boss_health = boss_health + hi_spirit;
                                }
                            }
                            //if the item sub selection is lazarus
                            if (player1_array[1] ==3)
                            {
                                player1_item3_count = player1_item3_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 5)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );


                        char1x = 65;
                        char3x = 15;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stab, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_stance, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        apply_surface( ene2x, ene2y, mage_left, screen);
                        apply_surface( 400, 250, boss_health_text, screen );

                        //apply character 1 text
                        apply_surface( 183, 347, character1_health, screen );
                        apply_surface( 183, 367, character1_total_health, screen );
                        apply_surface( 237, 347, character1_magic, screen );
                        apply_surface( 237, 367, character1_total_magic, screen );
                        apply_surface( 60, 355, character1_name, screen );

                        //apply character 3 text
                        apply_surface( 183, 427, character3_health, screen );
                        apply_surface( 183, 447, character3_total_health, screen );
                        apply_surface( 237, 427, character3_magic, screen );
                        apply_surface( 237, 447, character3_total_magic, screen );
                        apply_surface( 60, 435, character3_name, screen );

                        apply_surface( 150, 140, attack_number_text, screen );


                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char1x = 15;
                    }
                    else if (order2 == 2)
                    {
                        char3x = 65;
                        //the animations will go right here
                        //if the primary choice is attack then find the target and calculate the results
                        if (player3_array[0] == 1)
                        {
                            if (player3_array[2] == 1)
                            {
                                if (player3_attack_power*40 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 2)
                            {
                                if (player3_attack_power*40 >= player2_health)
                                {
                                    player2_health = 0;
                                }
                                else
                                {
                                    player2_health = player2_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 3)
                            {
                                if (player3_attack_power*40 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 4)
                            {
                                if (player3_attack_power*40 >= enemy1_health)
                                {
                                    enemy1_health = 0;
                                    bad1 = false;
                                }
                                else
                                {
                                    enemy1_health = enemy1_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 5)
                            {
                                if (player3_attack_power*40 >= enemy2_health)
                                {
                                    enemy2_health = 0;
                                    bad2 = false;
                                }
                                else
                                {
                                    enemy2_health = enemy2_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 6)
                            {
                                if (player3_attack_power*40 >= enemy3_health)
                                {
                                    enemy3_health = 0;
                                    bad3 = false;
                                }
                                else
                                {
                                    enemy3_health = enemy3_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 7)
                            {
                                if (player3_attack_power*40 >= enemy4_health)
                                {
                                    enemy4_health = 0;
                                    bad4 = false;
                                }
                                else
                                {
                                    enemy4_health = enemy4_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 8)
                            {
                                if (player3_attack_power*40 >= enemy5_health)
                                {
                                    enemy5_health = 0;
                                    bad5 = false;
                                }
                                else
                                    enemy5_health = enemy5_health - (player3_attack_power*40);
                            }
                            else if (player3_array[2] == 9)
                            {
                                if (player3_attack_power*40 >= enemy6_health)
                                {
                                    enemy6_health = 0;
                                    bad6 = false;
                                }
                                else
                                {
                                    enemy6_health = enemy6_health - (player3_attack_power*40);
                                }
                            }
                            attack_number = player3_attack_power*40;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player3_array[0] == 2)
                        {
                            //if the magic sub selection is Freeze
                            if (player3_array[1] == 1)
                            {
                                player3_magic = player3_magic - freeze_magic;

                                if (player3_array[2] == 1)
                                {
                                    if (player3_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player3_magic_power*50 >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    if (player3_magic_power*50 >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 5)
                                {
                                    if (player3_magic_power*50*freeze >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (player3_magic_power*50*freeze);
                                    }
                                    attack_number = player3_magic_power*50*freeze;
                                }
                                else if (player3_array[2] == 6)
                                {
                                    if (player3_magic_power*50 >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 7)
                                {
                                    if (player3_magic_power*50 >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 8)
                                {
                                    if (player3_magic_power*50*freeze >= enemy5_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                        enemy5_health = enemy5_health - (player3_magic_power*50*freeze);
                                    attack_number = player3_magic_power*50*freeze;
                                }
                                else if (player3_array[2] == 9)
                                {
                                    if (player3_magic_power*50 >= enemy6_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (player3_magic_power*50);
                                    }
                                }
                                if (player3_array[2] != 5 && player3_array[2] != 8)
                                {
                                    attack_number = player3_magic_power*50;
                                }
                            }
                            //if the magic sub selection is Power X2
                            else if (player3_array[1] == 2)
                            {
                                player3_magic = player3_magic - power_magic;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player1_attack_power = player1_attack_power*2;
                                    }
                                }
                                else  if (player3_array[2] == 2)
                                {
                                    if (player2_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player2_attack_power = player2_attack_power*2;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player3_attack_power = player3_attack_power*2;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                                attack_number = 0;

                            }
                            //if the magic sub selection is LIMIT
                            else if (player3_array[1] == 3)
                            {
                                limit3_power = player3_magic;
                                player3_magic = 0;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    if (enemy1_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 5)
                                {
                                    if (enemy2_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 6)
                                {
                                    if (enemy3_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 7)
                                {
                                    if (enemy4_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 8)
                                {
                                    if (enemy5_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                    {
                                        enemy5_health = enemy5_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 9)
                                {
                                    if (enemy6_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                attack_number = limit3_power*player3_attack_power*player3_magic_power;
                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player3_array[0] == 3)
                        {
                            //if the item sub selection is hi-spirit
                            if (player3_array[1] == 1)
                            {
                                player3_item1_count = player3_item1_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health+hi_spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health+hi_spirit > player2_total_health)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                    {
                                        player2_health = player2_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health+hi_spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    enemy1_health = enemy1_health + hi_spirit;
                                }
                                else if (player3_array[2] == 5)
                                {
                                    enemy2_health = enemy2_health + hi_spirit;
                                }
                                else if (player3_array[2] == 6)
                                {
                                    enemy3_health = enemy3_health + hi_spirit;
                                }
                                else if (player3_array[2] == 7)
                                {
                                    enemy4_health = enemy4_health + hi_spirit;
                                }
                                else if (player3_array[2] == 8)
                                {
                                    enemy5_health = enemy5_health + hi_spirit;
                                }
                                else if (player3_array[2] == 9)
                                {
                                    enemy6_health = enemy6_health + hi_spirit;
                                }
                            }
                            //use this for the hi-ether
                            if (player3_array[1] == 2)
                            {
                                player3_item2_count = player3_item2_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_magic+hi_ether > player1_total_magic)
                                    {
                                        player1_magic = player1_total_magic;
                                    }
                                    else
                                    {
                                        player1_magic = player1_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_magic+hi_ether > player2_total_magic)
                                    {
                                        player2_magic = player2_total_magic;
                                    }
                                    else
                                    {
                                        player2_magic = player2_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_magic+hi_ether > player3_total_magic)
                                    {
                                        player3_magic = player3_total_magic;
                                    }
                                    else
                                    {
                                        player3_magic = player3_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                            }
                            //if the item sub selection is lazarus
                            if (player3_array[1] ==3)
                            {
                                player3_item3_count = player3_item3_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );


                        char1x = 15;
                        char3x = 65;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stance, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_shoot, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        apply_surface( ene2x, ene2y, mage_left, screen);
                        apply_surface( 400, 250, boss_health_text, screen );

                        //apply character 1 text
                        apply_surface( 183, 347, character1_health, screen );
                        apply_surface( 183, 367, character1_total_health, screen );
                        apply_surface( 237, 347, character1_magic, screen );
                        apply_surface( 237, 367, character1_total_magic, screen );
                        apply_surface( 60, 355, character1_name, screen );

                        //apply character 3 text
                        apply_surface( 183, 427, character3_health, screen );
                        apply_surface( 183, 447, character3_total_health, screen );
                        apply_surface( 237, 427, character3_magic, screen );
                        apply_surface( 237, 447, character3_total_magic, screen );
                        apply_surface( 60, 435, character3_name, screen );

                        apply_surface( 150, 140, attack_number_text, screen );


                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char3x = 15;
                    }
                }
                else if (fight_turn == 4)
                {
                    //now reset everything
                    if (player1_health != 0)
                    {
                        arx = 15;
                        ary = 350;
                    }
                    else if (player3_health != 0)
                    {
                        arx = 15;
                        ary = 430;
                    }
                    else
                    {
                        lose = true;
                    }
                    if (player1_health != 0)
                    {
                        good1 = true;
                    }
                    if (player3_health != 0)
                    {
                        good3 = true;
                    }

                    order1 = 0;
                    order2 = 0;
                    order3 = 0;

                    player1_array[0] = 0;
                    player1_array[1] = 0;
                    player1_array[2] = 0;

                    player2_array[0] = 0;
                    player2_array[1] = 0;
                    player2_array[2] = 0;

                    player3_array[0] = 0;
                    player3_array[1] = 0;
                    player3_array[2] = 0;

                    right = true;
                    left = false;
                    choose1 = 0;
                    choose2 = 0;
                    choose3 = 0;
                    choose4 = 0;
                    if (boss_health == 0)
                    {
                        win = true;
                    }

                    fight_turn = 0;
                    fight = false;
                }
                if (player1_health == 0)
                {
                    good1 = false;
                }
                if (player3_health == 0)
                {
                    good3 = false;
                }

                fight_turn = fight_turn + 1;
                music_stop = true;
            }
            if (win == true)
            {
                if (music_stop == true)
                {
                    if ( Mix_PlayMusic(win_music, 1) == 1)
                    {
                        return 1;
                    }
                    music_stop = false;
                }

                SDL_Delay(3100);
                boss1 = false;
                boss2_text = true;
                win = false;
            }
            if (lose == true)
            {
                if (music_stop == true)
                {
                    if ( Mix_PlayMusic(loss_music, 1) == 1)
                    {
                        return 1;
                    }
                    music_stop = false;
                }
                SDL_Delay(5500);
                battle_start = true;
                lose = false;
            }

            //Scroll background
            bgX -= .25;

            //If the background has gone too far
            if ( bgX <= -background->w )
            {
                //Reset the offset
                bgX = 0;
            }


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
                    if ( choose1 == 1 && choose2 == 2)
                    {
                        apply_surface( 505, 350, rage_text, screen );
                        apply_surface( 505, 390, fire_text, screen );
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
                        apply_surface( 505, 350, ice_text, screen );
                        apply_surface( 505, 390, hitx2_text, screen );
                        apply_surface( 505, 430, limit_text, screen );
                    }

                }
                if (choose2 == 3)
                {
                    if (choose1 == 1)
                    {
                        if (play1i == true)
                        {
                            if (play1i1 == true)
                            {
                                apply_surface( 500, 345, item_sub_selection, screen);
                                apply_surface( 505, 350, player1_spirits_text, screen);
                            }
                            if (play1i2 == true)
                            {
                                apply_surface( 500, 385, item_sub_selection, screen);
                                apply_surface( 505, 390, player1_hi_spirits_text, screen);
                            }
                            if (play1i3 == true)
                            {
                                apply_surface( 500, 425, item_sub_selection, screen);
                                apply_surface( 505, 430, player1_lazarus_text, screen);
                            }
                        }
                    }
                    else if (choose1 == 3)
                    {
                        if (choose2 == 3 && play3i == true)
                        {
                            if (play3i1 == true)
                            {
                                apply_surface( 500, 345, item_sub_selection, screen);
                                apply_surface( 505, 350, player3_hi_spirits_text, screen);
                            }
                            if (play3i2 == true)
                            {
                                apply_surface( 500, 385, item_sub_selection, screen);
                                apply_surface( 505, 390, player3_hi_ether_text, screen);
                            }
                            if (play3i3 == true)
                            {
                                apply_surface( 500, 425, item_sub_selection, screen);
                                apply_surface( 505, 430, player3_lazarus_text, screen);
                            }
                        }
                    }
                }
            }

            // show the characters
            // place the characters depending on which one is selected
            if (fight != true)
            {
                if ( (ary == 350 && arx ==  15) || choose1 == 1)
                {
                    char1x = 65;
                    char2x = 15;
                    char3x = 15;
                    if (player3_health == 0)
                    {
                        good3 = false;
                        apply_surface( char3x, char3y, marine_dead, screen);
                    }
                    else
                    {
                        good3 = true;
                        apply_surface( char3x, char3y, marine_stance, screen);
                    }
                    apply_surface( char1x, char1y, warrior_out, screen);
                }
                else if ( ary == 430 && arx ==  15 || choose1 == 3)
                {
                    char1x = 15;
                    char2x = 15;
                    char3x = 65;

                    if (player1_health == 0)
                    {
                        good1 = false;
                        apply_surface( char1x, char1y, warrior_dead, screen);
                    }
                    else
                    {
                        good1 = true;
                        apply_surface( char1x, char1y, warrior_stance, screen);
                    }
                    apply_surface( char3x, char3y, marine_out, screen);

                }
            }

            apply_surface( ene2x, ene2y, mage_left, screen);


// show the arrow
            if ( right == true )
            {
                apply_surface( arx, ary, arrow_right, screen);
            }
            if ( left == true)
            {
                apply_surface(arx, ary, arrow_left, screen);
            }


//----------------------------------------------------------------------------
            //the players health and magic has a string
            std::stringstream play1h;
            std::stringstream play1th;
            std::stringstream play1m;
            std::stringstream play1tm;


            std::stringstream play3h;
            std::stringstream play3th;
            std::stringstream play3m;
            std::stringstream play3tm;

            //the players particular items as a string
            std::stringstream play1item1;
            std::stringstream play1item2;
            std::stringstream play1item3;
            std::stringstream play3item1;
            std::stringstream play3item2;
            std::stringstream play3item3;

            std::stringstream bh;
            bh << boss_health;
            boss_health_text = TTF_RenderText_Solid( font_small, bh.str().c_str(), textColor );
            apply_surface( 400, 250, boss_health_text, screen );




            //convert the player attributes to string
            play1h << player1_health;
            play1th << player1_total_health;
            play1m << player1_magic;
            play1tm << player1_total_magic;

            play3h << player3_health;
            play3th << player3_total_health;
            play3m << player3_magic;
            play3tm << player3_total_magic;



            //convert the players items and numbers into a string
            play1item1 << "SPIRIT[" << player1_item1_count << "]";
            play1item2 << "HI-SPIRIT[" << player1_item2_count << "]";
            play1item3 << "LAZARUS[" << player1_item3_count << "]";


            play3item1 << "HI-SPIRIT[" << player3_item1_count << "]";
            play3item2 << "HI-ETHER[" << player3_item2_count << "]";
            play3item3 << "LAZARUS[" << player3_item3_count << "]";





            //Render the text

            //character1 attributes text
            character1_health = TTF_RenderText_Solid( font_small, play1h.str().c_str(), textColor );
            character1_total_health = TTF_RenderText_Solid( font_small, play1th.str().c_str(), textColor );
            character1_magic = TTF_RenderText_Solid( font_small, play1m.str().c_str(), textColor );
            character1_total_magic = TTF_RenderText_Solid( font_small, play1tm.str().c_str(), textColor );

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
            character1_name = TTF_RenderText_Solid( font, "Knight", textColor );

            character3_name = TTF_RenderText_Solid( font, "Marine", textColor );
            //character 1 magic text
            rage_text = TTF_RenderText_Solid( font, "RAGE", textColor );
            hitx2_text = TTF_RenderText_Solid( font, "POWER X2", textColor );
            limit_text = TTF_RenderText_Solid( font, "LIMIT", textColor );
            //character2 magic text
            fire_text = TTF_RenderText_Solid( font, "BURN", textColor );
            ice_text = TTF_RenderText_Solid( font, "FREEZE", textColor );

            //the names of items
            player1_spirits_text = TTF_RenderText_Solid( font, play1item1.str().c_str(), textColor );
            player1_hi_spirits_text = TTF_RenderText_Solid( font, play1item2.str().c_str(), textColor );
            player1_lazarus_text = TTF_RenderText_Solid( font, play1item3.str().c_str(), textColor );

            player3_hi_spirits_text = TTF_RenderText_Solid( font, play3item1.str().c_str(), textColor );
            player3_hi_ether_text = TTF_RenderText_Solid( font, play3item2.str().c_str(), textColor );
            player3_lazarus_text = TTF_RenderText_Solid( font, play3item3.str().c_str(), textColor );


            //apply character 1 text
            apply_surface( 183, 347, character1_health, screen );
            apply_surface( 183, 367, character1_total_health, screen );
            apply_surface( 237, 347, character1_magic, screen );
            apply_surface( 237, 367, character1_total_magic, screen );
            apply_surface( 60, 355, character1_name, screen );

            //apply character 3 text
            apply_surface( 183, 427, character3_health, screen );
            apply_surface( 183, 447, character3_total_health, screen );
            apply_surface( 237, 427, character3_magic, screen );
            apply_surface( 237, 447, character3_total_magic, screen );
            apply_surface( 60, 435, character3_name, screen );

            //Update the screen
            if ( SDL_Flip( screen ) == -1 )
            {
                return 1;
            }

            //Cap the frame rate
            if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
            {
                SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
            }


        }
        while (boss2_text == true)
        {
            if ( Mix_PlayingMusic() == 0 )
            {
                title_time.start();
                //Play the music
                if ( Mix_PlayMusic( climax, -1 ) == 1 )
                {
                    return 1;
                }
            }

            //Apply the surface to the screen
            apply_surface(bgX, bgY, sky, screen );
            apply_surface( bgX + background->w, bgY, sky, screen );

            apply_surface( 0, 0, background, screen );
            apply_surface( 0, 330, command_background, screen );
            apply_surface( 50, 345, character_background, screen);
            apply_surface( 50, 385, character_background, screen);
            apply_surface( 50, 425, character_background, screen);
            apply_surface( 170, 345, health_counter, screen);
            apply_surface( 220, 345, magic_counter, screen);


            //While there's an event to handle
            while ( SDL_PollEvent( &event ) )
            {
                //If a key was pressed
                if ( event.type == SDL_KEYDOWN )
                {
                    switch ( event.key.keysym.sym )
                    {
                    case SDLK_a:
                    {
                        text_counter = text_counter + 1;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                    }
                }
                //If the user has Xed out the window
                if ( event.type == SDL_QUIT )
                {
                    //Quit the program
                    boss2_text = false;
                }
            }
            if (text_counter == 26)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(100, 30, blerb26, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(ene2x, ene2y, mage_left, screen);
                apply_surface(char3x, char3y, marine_stance, screen);

            }
            if (text_counter == 27)
            {
                char1x = 15;
                char3x = 65;

                apply_surface(90, 170, blerb27, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(ene2x, ene2y, mage_left, screen);
                apply_surface(char3x, char3y, marine_stance, screen);

            }
            if (text_counter == 28)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(190, 100, blerb28, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(ene2x, ene2y, mage_left, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 29)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(190, 100, blerb29, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(ene2x, ene2y, mage_left, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 30)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(190, 100, blerb30, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(ene2x, ene2y, mage_left, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 31)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(380, 120, blerb31, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(ene2x, ene2y, mage_left, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 32)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(340, 120, blerb32, screen);
                apply_surface(char1x, char1y, warrior_out, screen);
                apply_surface(ene2x, ene2y, unicorn, screen);
                apply_surface(char3x, char3y, marine_out, screen);
            }
            if (text_counter == 33)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(90, 170, blerb33, screen);
                apply_surface(char1x, char1y, warrior_out, screen);
                apply_surface(ene2x, ene2y, unicorn, screen);
                apply_surface(char3x, char3y, marine_out, screen);
            }
            if (text_counter == 34)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(90, 50, blerb34, screen);
                apply_surface(char1x, char1y, warrior_out, screen);
                apply_surface(ene2x, ene2y, unicorn, screen);
                apply_surface(char3x, char3y, marine_out, screen);
            }
            if (text_counter == 35)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(90, 50, blerb35, screen);
                apply_surface(char1x, char1y, warrior_out, screen);
                apply_surface(ene2x, ene2y, unicorn, screen);
                apply_surface(char3x, char3y, marine_out, screen);
            }
            if (text_counter == 36)
            {
                if ( Mix_PlayingMusic() != 0 )
                {
                    //Pause the music
                    Mix_HaltMusic();
                }
                boss2_text = false;
                boss3_text = true;
            }

            //Update the screen
            if ( SDL_Flip( screen ) == -1 )
            {
                return 1;
            }

            //Cap the frame rate
            if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
            {
                SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
            }
        }
        while (boss2 == true)
        {
            if ( Mix_PlayingMusic() == 0 )
            {
                //Play the music
                if ( Mix_PlayMusic( hood_off, -1 ) == 1 )
                {
                    return 1;
                }
            }

            if (boos == true)
            {
                boss_health = 2000;
                boos = false;
            }



            //Start the frame timer
            fps.start();

            //Apply the surface to the screen
            apply_surface(bgX, bgY, sky, screen );
            apply_surface( bgX + background->w, bgY, sky, screen );

            apply_surface( 0, 0, background, screen );
            apply_surface( 0, 330, command_background, screen );
            apply_surface( 50, 345, character_background, screen);
            apply_surface( 50, 385, character_background, screen);
            apply_surface( 50, 425, character_background, screen);
            apply_surface( 170, 345, health_counter, screen);
            apply_surface( 220, 345, magic_counter, screen);




            //While there's an event to handle
            while ( SDL_PollEvent( &event ) )
            {
                //If a key was pressed
                if ( event.type == SDL_KEYDOWN )
                {
                    switch ( event.key.keysym.sym )
                    {
                    case SDLK_UP:
                    {

                        //selecting the characters
                        if (arx == 15)
                        {
                            if (ary == 350)
                            {
                                if (order1 == 3 || good3 == false)
                                {
                                    break;
                                }
                                else
                                {
                                    ary = 430;
                                    break;
                                }
                            }
                            else if (ary == 430)
                            {
                                if (order1 == 1 || good1 == false)
                                {
                                    break;
                                }
                                else
                                {
                                    ary = 350;
                                    break;
                                }
                            }
                        }
                        //this is for selecting primaries and subs
                        else if ( ary >= 350)
                        {
                            if (arx != 15 && ary != 350)
                            {
                                ary = ary - 40;
                                break;
                            }
                            else
                            {
                                ary = 430;
                                break;
                            }
                        }
                        // this is for selecting who will receive the action
                        else if (ary < 350)
                        {
                            if (arx == 140)
                            {
                                if (ary == 110)
                                {
                                    ary = 270;
                                    break;
                                }
                                else if (ary == 270)
                                {
                                    ary = 110;
                                    break;
                                }
                            }
                            else if (arx = 415)
                            {
                                break;
                            }

                        }
                    }
                    case SDLK_DOWN:
                    {

                        if (arx == 15)
                        {
                            if (ary == 350)
                            {
                                if (order1 == 3 || good3 == false)
                                {
                                    break;
                                }
                                else
                                {
                                    ary = 430;
                                    break;
                                }
                            }
                            else if (ary == 430)
                            {
                                if (order1 == 1 || good1 == false)
                                {
                                    break;
                                }
                                else
                                {
                                    ary = 350;
                                    break;
                                }
                            }


                        }
                        else if (ary >= 350)
                        {
                            if (arx != 15 && ary != 430)
                            {
                                ary = ary + 40;
                                break;
                            }
                            else
                            {
                                ary = 350;
                                break;
                            }
                        }
                        //this is for selecting who will receive the action
                        else if (ary < 350)
                        {
                            if (arx == 140)
                            {
                                if (ary == 110)
                                {
                                    ary = 270;
                                    break;
                                }
                                else if (ary == 270)
                                {
                                    ary = 110;
                                    break;
                                }
                            }
                            else if (arx = 415)
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    case SDLK_RIGHT:
                    {
                        //moving from the characters to the boss
                        if (ary < 350 && arx == 140)
                        {
                            arx = 415;
                            ary = 180;
                            right = true;
                            left = false;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    case SDLK_LEFT:
                    {
                        if (arx == 415)
                        {
                            arx = 140;
                            ary = 110;
                            right = false;
                            left = true;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    case SDLK_a:
                    {
                        if (fight == false)
                        {
                            // check first for target selection
                            if ( ary < 350 )
                            {
                                //if the first character is selected
                                if ( arx == 140 && ary == 110)
                                {
                                    choose4 = 1;
                                }
                                //if the last character is selected
                                else if ( arx == 140 && ary == 270)
                                {
                                    choose4 = 3;
                                }
                                //if the boss is selected
                                else if ( arx == 415 && ary == 180)
                                {
                                    choose4 = 5;
                                }
                                if (choose1 == 1)
                                {
                                    player1_array[0] = choose2;
                                    player1_array[1] = choose3;
                                    player1_array[2] = choose4;
                                }
                                else if (choose1 == 3)
                                {
                                    player3_array[0] = choose2;
                                    player3_array[1] = choose3;
                                    player3_array[2] = choose4;
                                }
                                if (order1==0)
                                {
                                    order1 = choose1;
                                    if (order1 == 1 && player2_health != 0)
                                    {
                                        arx = 15;
                                        ary =430;
                                    }
                                    else if (order1 == 1 && player2_health == 0)
                                    {
                                        good2 = false;
                                        fight = true;
                                    }
                                    if (order1 == 2 && player1_health != 0)
                                    {
                                        arx = 15;
                                        ary = 350;
                                    }
                                    else if (order1 == 2 && player1_health == 0)
                                    {
                                        good1 = false;
                                        fight = true;
                                    }
                                    right = true;
                                    left = false;
                                    choose1 = 0;
                                    choose2 = 0;
                                    choose3 = 0;
                                    choose4 = 0;
                                    break;
                                }
                                else if (order2==0)
                                {
                                    order2 = choose1;
                                    fight = true;

                                    right = true;
                                    left = false;
                                    choose1 = 0;
                                    choose2 = 0;
                                    choose3 = 0;
                                    choose4 = 0;
                                }

                            }
                            //check second for sub selection
                            else if (arx == 445)
                            {
                                if (choose2 == 2 && (player1_magic == 0 || player3_magic == 0))
                                {
                                    if (choose1 == 1)
                                    {
                                        if (choose2 == 2 && player1_magic == 0)
                                        {
                                            break;
                                        }

                                    }
                                    else if (choose1 == 3)
                                    {
                                        if (choose2 == 2 && player3_magic == 0)
                                        {
                                            break;
                                        }

                                    }
                                }
                                if ((choose1 == 1 && choose2 == 3) && (player1_item1_count == 0 || player1_item3_count == 0))
                                {
                                    if (ary == 350 && player1_item1_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 390 && player1_item2_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 430 && player1_item3_count == 0)
                                    {
                                        break;
                                    }
                                }
                                else if ((choose1 == 2 && choose2 == 3) && (player2_item1_count == 0 || player3_item3_count == 0))
                                {
                                    if (ary == 350 && player2_item1_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 390 && player2_item2_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 430 && player2_item3_count == 0)
                                    {
                                        break;
                                    }
                                }
                                else if ((choose1 == 3 && choose2 == 3) &&(player3_item1_count == 0 || player3_item3_count == 0))
                                {
                                    if (ary == 350 && player3_item1_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 390 && player3_item2_count == 0)
                                    {
                                        break;
                                    }
                                    else if (ary == 430 && player3_item3_count == 0)
                                    {
                                        break;
                                    }
                                }
                                if ( choose2 == 2 )
                                {
                                    if (ary == 350)
                                    {
                                        choose3 = 1;
                                        arx = 415;
                                        ary = 180;
                                        right = true;
                                        left = false;
                                        break;
                                    }
                                    if (ary == 390)
                                    {
                                        choose3 = 2;
                                        arx = 415;
                                        ary = 180;
                                        right = true;
                                        left = false;
                                        break;
                                    }
                                    if (ary == 430)
                                    {
                                        choose3 = 3;
                                        arx = 415;
                                        ary = 180;
                                        right = true;
                                        left = false;
                                        break;
                                    }
                                }
                                else if (choose2 == 3)
                                {
                                    if (ary == 350)
                                    {
                                        choose3 = 1;
                                        arx = 140;
                                        ary = 110;
                                        right = false;
                                        left = true;
                                        break;
                                    }
                                    else if (ary == 390)
                                    {
                                        choose3 = 2;
                                        arx = 140;
                                        ary = 110;
                                        right = false;
                                        left = true;
                                        break;
                                    }
                                    else if (ary == 430)
                                    {
                                        choose3 = 3;
                                        arx = 140;
                                        ary = 110;
                                        right = false;
                                        left = true;
                                        break;
                                    }
                                }


                            }

                            // check third for primary selection
                            else if (arx == 280)
                            {
                                //this one is the attack one, it is special because it has no sub selection
                                if ( ary == 350 )
                                {
                                    choose2 = 1;
                                    arx = 415;
                                    ary = 180;
                                    right = true;
                                    left = false;
                                    break;
                                }
                                // now back to the other options
                                else if ( ary == 390 )
                                {
                                    choose2 = 2;
                                    arx = 445;
                                    ary = 350;
                                    break;
                                }
                                else if ( ary == 430 )
                                {
                                    if (choose1 == 1)
                                    {
                                        if (play1i == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            choose2 = 3;
                                            arx = 445;
                                            ary = 350;
                                            break;
                                        }
                                    }
                                    else if (choose1 == 2)
                                    {
                                        if (play2i == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            choose2 = 3;
                                            arx = 445;
                                            ary = 350;
                                            break;
                                        }
                                    }
                                    else if (choose1 == 3)
                                    {
                                        if (play3i == false)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            choose2 = 3;
                                            arx = 445;
                                            ary = 350;
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }

                            // check last for character selection
                            else if (arx == 15)
                            {
                                if ( ary == 350 )
                                {
                                    choose1 = 1;
                                    ary = 350;
                                    arx = 280;
                                    break;
                                }
                                if ( ary == 390 )
                                {
                                    choose1 = 2;
                                    ary = 350;
                                    arx = 280;
                                    break;
                                }
                                if ( ary == 430 )
                                {
                                    choose1 = 3;
                                    ary = 350;
                                    arx = 280;
                                    break;
                                }
                                else
                                {
                                    break;
                                }
                            }

                            else
                            {
                                break;
                            }

                        }
                    }
                    case SDLK_s:
                    {
                        //go back and undo sub selection
                        if (ary < 350 && choose3 == 0)
                        {
                            arx = 280;
                            ary = 350;
                            choose2 = 0;
                            right = true;
                            left = false;
                            break;
                        }
                        if (ary < 350 && choose3 == 1)
                        {
                            arx = 445;
                            ary = 350;
                            choose3 = 0;
                            right = true;
                            left = false;
                            break;
                        }
                        if (ary < 350 && choose3 == 2)
                        {
                            arx = 445;
                            ary = 390;
                            choose3 = 0;
                            right = true;
                            left = false;
                            break;
                        }
                        if (ary < 350 && choose3 == 3)
                        {
                            arx = 445;
                            ary = 430;
                            choose3 = 0;
                            right = true;
                            left = false;
                            break;
                        }
                        //go back and undo primary selection
                        if ( arx == 445 && choose2 == 1)
                        {
                            arx = 280;
                            ary = 350;
                            choose2 = 0;
                            break;
                        }
                        if ( arx == 445 && choose2 == 2)
                        {
                            arx = 280;
                            ary = 390;
                            choose2 = 0;
                            break;
                        }
                        if ( arx == 445 && choose2 == 3)
                        {
                            arx = 280;
                            ary = 430;
                            choose2 = 0;
                            break;
                        }
                        //go back and undo character selection
                        if ( arx == 280 && choose1 == 1)
                        {
                            arx = 15;
                            ary = 350;
                            choose1 = 0;
                            break;
                        }
                        if ( arx == 280 && choose1 == 2)
                        {
                            arx = 15;
                            ary = 390;
                            choose1 = 0;
                            break;
                        }
                        if ( arx == 280 && choose1 == 3)
                        {
                            arx = 15;
                            ary = 430;
                            choose1 = 0;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    case SDLK_d:
                    {
                        break;
                    }
                    case SDLK_f:
                    {
                        bad1 = false;
                        bad2 = false;
                        bad3 = false;
                        bad4 = false;
                        bad5 = false;
                        bad6 = true;

                    }
                    default:
                    {
                        break;
                    }
                    }
                }
            }
            //If the user has Xed out the window
            if ( event.type == SDL_QUIT )
            {
                //Quit the program
                boss2 = false;
            }

            if (fight == true)
            {

                if (boss_health != 0)
                {
                    evil = false;
                }
                else
                {
                    evil = true;
                }

                if (fight_turn == 1 && evil == false)
                {
                    if (order1 == 1)
                    {
                        //if the primary choice is attack then find the target and calculate the results
                        if (player1_array[0] == 1)
                        {
                            if (player1_array[2] == 1)
                            {
                                if (player1_attack_power*50 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 3)
                            {
                                if (player1_attack_power*50 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 5)
                            {
                                if (player1_attack_power*50 >= boss_health)
                                {
                                    boss_health = 0;
                                }
                                else
                                {
                                    boss_health = boss_health - (player1_attack_power*50);
                                }
                            }
                            attack_number = player1_attack_power*50;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player1_array[0] == 2)
                        {
                            //if the magic sub selection is Rage
                            if (player1_array[1] == 1)
                            {
                                player1_magic = player1_magic - rage_magic;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_attack_power*50*rage >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player1_attack_power*50*rage >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (player1_attack_power*50*rage >= boss_health)
                                    {
                                        boss_health = 0;
                                    }
                                    else
                                    {
                                        boss_health = boss_health -(player1_attack_power*50*rage);
                                    }
                                }

                                attack_number = player1_attack_power*50*rage;
                            }
                            //if the magic sub selection is Burn
                            if (player1_array[1] == 2)
                            {
                                player1_magic = player1_magic - burn_magic;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player1_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (player1_magic_power*50 >= boss_health)
                                    {
                                        enemy2_health = 0;
                                    }
                                    else
                                    {
                                        boss_health = boss_health - (player1_magic_power*50);
                                    }
                                }
                                attack_number = player1_magic_power*50;
                            }
                            //if the magic sub selection is LIMIT
                            else if (player1_array[1] == 3)
                            {
                                limit1_power = player1_magic;
                                player1_magic = 0;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (boss_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        boss_health = 0;
                                    }
                                    else
                                    {
                                        boss_health = boss_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                attack_number = limit1_power*player1_attack_power*player1_magic_power;
                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player1_array[0] == 3)
                        {
                            //if the item sub selection is spirit
                            if (player1_array[1] == 1)
                            {
                                player1_item1_count = player1_item1_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player1_health+spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player3_health+spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    boss_health = boss_health + spirit;
                                }
                            }
                            //if the item sub selection is hi-spirit
                            if (player1_array[1] == 2)
                            {
                                player1_item2_count = player1_item2_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player1_health+hi_spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player3_health+hi_spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    boss_health = boss_health + hi_spirit;
                                }
                            }
                            //if the item sub selection is lazarus
                            if (player1_array[1] ==3)
                            {
                                player1_item3_count = player1_item3_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 5)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );


                        char1x = 65;
                        char3x = 15;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stab, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_stance, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        apply_surface( ene2x, ene2y, unicorn, screen);
                        apply_surface( 400, 250, boss_health_text, screen );

                        //apply character 1 text
                        apply_surface( 183, 347, character1_health, screen );
                        apply_surface( 183, 367, character1_total_health, screen );
                        apply_surface( 237, 347, character1_magic, screen );
                        apply_surface( 237, 367, character1_total_magic, screen );
                        apply_surface( 60, 355, character1_name, screen );

                        //apply character 3 text
                        apply_surface( 183, 427, character3_health, screen );
                        apply_surface( 183, 447, character3_total_health, screen );
                        apply_surface( 237, 427, character3_magic, screen );
                        apply_surface( 237, 447, character3_total_magic, screen );
                        apply_surface( 60, 435, character3_name, screen );

                        apply_surface( 150, 140, attack_number_text, screen );


                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char1x = 15;
                    }
                    else if (order1 == 2)
                    {
                        char3x = 65;
                        //the animations will go right here
                        //if the primary choice is attack then find the target and calculate the results
                        if (player3_array[0] == 1)
                        {
                            if (player3_array[2] == 1)
                            {
                                if (player3_attack_power*40 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 2)
                            {
                                if (player3_attack_power*40 >= player2_health)
                                {
                                    player2_health = 0;
                                }
                                else
                                {
                                    player2_health = player2_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 3)
                            {
                                if (player3_attack_power*40 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 4)
                            {
                                if (player3_attack_power*40 >= enemy1_health)
                                {
                                    enemy1_health = 0;
                                    bad1 = false;
                                }
                                else
                                {
                                    enemy1_health = enemy1_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 5)
                            {
                                if (player3_attack_power*40 >= enemy2_health)
                                {
                                    enemy2_health = 0;
                                    bad2 = false;
                                }
                                else
                                {
                                    enemy2_health = enemy2_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 6)
                            {
                                if (player3_attack_power*40 >= enemy3_health)
                                {
                                    enemy3_health = 0;
                                    bad3 = false;
                                }
                                else
                                {
                                    enemy3_health = enemy3_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 7)
                            {
                                if (player3_attack_power*40 >= enemy4_health)
                                {
                                    enemy4_health = 0;
                                    bad4 = false;
                                }
                                else
                                {
                                    enemy4_health = enemy4_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 8)
                            {
                                if (player3_attack_power*40 >= enemy5_health)
                                {
                                    enemy5_health = 0;
                                    bad5 = false;
                                }
                                else
                                    enemy5_health = enemy5_health - (player3_attack_power*40);
                            }
                            else if (player3_array[2] == 9)
                            {
                                if (player3_attack_power*40 >= enemy6_health)
                                {
                                    enemy6_health = 0;
                                    bad6 = false;
                                }
                                else
                                {
                                    enemy6_health = enemy6_health - (player3_attack_power*40);
                                }
                            }
                            attack_number = player3_attack_power*40;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player3_array[0] == 2)
                        {
                            //if the magic sub selection is Freeze
                            if (player3_array[1] == 1)
                            {
                                player3_magic = player3_magic - freeze_magic;

                                if (player3_array[2] == 1)
                                {
                                    if (player3_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player3_magic_power*50 >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    if (player3_magic_power*50 >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 5)
                                {
                                    if (player3_magic_power*50*freeze >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (player3_magic_power*50*freeze);
                                    }
                                    attack_number = player3_magic_power*50*freeze;
                                }
                                else if (player3_array[2] == 6)
                                {
                                    if (player3_magic_power*50 >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 7)
                                {
                                    if (player3_magic_power*50 >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 8)
                                {
                                    if (player3_magic_power*50*freeze >= enemy5_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                        enemy5_health = enemy5_health - (player3_magic_power*50*freeze);
                                    attack_number = player3_magic_power*50*freeze;
                                }
                                else if (player3_array[2] == 9)
                                {
                                    if (player3_magic_power*50 >= enemy6_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (player3_magic_power*50);
                                    }
                                }
                                if (player3_array[2] != 5 && player3_array[2] != 8)
                                {
                                    attack_number = player3_magic_power*50;
                                }
                            }
                            //if the magic sub selection is Power X2
                            else if (player3_array[1] == 2)
                            {
                                player3_magic = player3_magic - power_magic;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player1_attack_power = player1_attack_power*2;
                                    }
                                }
                                else  if (player3_array[2] == 2)
                                {
                                    if (player2_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player2_attack_power = player2_attack_power*2;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player3_attack_power = player3_attack_power*2;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                                attack_number = 0;

                            }
                            //if the magic sub selection is LIMIT
                            else if (player3_array[1] == 3)
                            {
                                limit3_power = player3_magic;
                                player3_magic = 0;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    if (enemy1_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 5)
                                {
                                    if (enemy2_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 6)
                                {
                                    if (enemy3_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 7)
                                {
                                    if (enemy4_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 8)
                                {
                                    if (enemy5_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                    {
                                        enemy5_health = enemy5_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 9)
                                {
                                    if (enemy6_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                attack_number = limit3_power*player3_attack_power*player3_magic_power;
                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player3_array[0] == 3)
                        {
                            //if the item sub selection is hi-spirit
                            if (player3_array[1] == 1)
                            {
                                player3_item1_count = player3_item1_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health+hi_spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health+hi_spirit > player2_total_health)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                    {
                                        player2_health = player2_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health+hi_spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    enemy1_health = enemy1_health + hi_spirit;
                                }
                                else if (player3_array[2] == 5)
                                {
                                    enemy2_health = enemy2_health + hi_spirit;
                                }
                                else if (player3_array[2] == 6)
                                {
                                    enemy3_health = enemy3_health + hi_spirit;
                                }
                                else if (player3_array[2] == 7)
                                {
                                    enemy4_health = enemy4_health + hi_spirit;
                                }
                                else if (player3_array[2] == 8)
                                {
                                    enemy5_health = enemy5_health + hi_spirit;
                                }
                                else if (player3_array[2] == 9)
                                {
                                    enemy6_health = enemy6_health + hi_spirit;
                                }
                            }
                            //use this for the hi-ether
                            if (player3_array[1] == 2)
                            {
                                player3_item2_count = player3_item2_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_magic+hi_ether > player1_total_magic)
                                    {
                                        player1_magic = player1_total_magic;
                                    }
                                    else
                                    {
                                        player1_magic = player1_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_magic+hi_ether > player2_total_magic)
                                    {
                                        player2_magic = player2_total_magic;
                                    }
                                    else
                                    {
                                        player2_magic = player2_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_magic+hi_ether > player3_total_magic)
                                    {
                                        player3_magic = player3_total_magic;
                                    }
                                    else
                                    {
                                        player3_magic = player3_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                            }
                            //if the item sub selection is lazarus
                            if (player3_array[1] ==3)
                            {
                                player3_item3_count = player3_item3_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );


                        char1x = 65;
                        char3x = 15;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stance, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_shoot, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        apply_surface( ene2x, ene2y, unicorn, screen);
                        apply_surface( 400, 250, boss_health_text, screen );

                        //apply character 1 text
                        apply_surface( 183, 347, character1_health, screen );
                        apply_surface( 183, 367, character1_total_health, screen );
                        apply_surface( 237, 347, character1_magic, screen );
                        apply_surface( 237, 367, character1_total_magic, screen );
                        apply_surface( 60, 355, character1_name, screen );

                        //apply character 3 text
                        apply_surface( 183, 427, character3_health, screen );
                        apply_surface( 183, 447, character3_total_health, screen );
                        apply_surface( 237, 427, character3_magic, screen );
                        apply_surface( 237, 447, character3_total_magic, screen );
                        apply_surface( 60, 435, character3_name, screen );

                        apply_surface( 150, 140, attack_number_text, screen );


                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char3x = 15;
                    }
                }
                else if (fight_turn == 2)
                {
                    if (good1 == true && good3 == true)
                    {
                        enemy_random = 1 + rand() % 2;
                    }
                    else if (good1 == false)
                    {
                        enemy_random = 2;
                    }
                    else if (good2 == false)
                    {
                        enemy_random = 1;
                    }
                    attack_number = boss_power*30;
                    if (enemy_random == 1)
                    {
                        if (player1_health < boss_power*30)
                        {
                            player1_health =0;
                        }
                        else
                        {
                            player1_health = player1_health - boss_power*30;
                        }
                    }
                    else if (enemy_random == 2)
                    {
                        if (player3_health < boss_power*30)
                        {
                            player3_health =0;
                        }
                        else
                        {
                            player3_health = player3_health - boss_power*30;
                        }
                    }

                    attack_number = enemy1_attack*30;

                    std::stringstream attack_value;
                    attack_value << attack_number;
                    attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), alertColor );

                    char1x = 15;
                    char3x = 15;
                    apply_surface(bgX, bgY, sky, screen );
                    apply_surface( bgX + background->w, bgY, sky, screen );

                    apply_surface( 0, 0, background, screen );
                    apply_surface( 0, 330, command_background, screen );
                    apply_surface( 50, 345, character_background, screen);
                    apply_surface( 50, 385, character_background, screen);
                    apply_surface( 50, 425, character_background, screen);
                    apply_surface( 170, 345, health_counter, screen);
                    apply_surface( 220, 345, magic_counter, screen);

                    if (player1_health != 0)
                    {
                        apply_surface( char1x, char1y, warrior_stance, screen);
                    }
                    else
                    {
                        apply_surface( char1x, char1y, warrior_dead, screen);
                    }

                    if (player3_health != 0)
                    {
                        apply_surface( char3x, char3y, marine_stance, screen);
                    }
                    else
                    {
                        apply_surface( char3x, char3y, marine_dead, screen);
                    }

                    if (enemy_random == 1)
                    {
                        apply_surface( 150, 140, attack_number_text, screen );
                    }
                    else if (enemy_random == 2)
                    {
                        apply_surface( 150, 290, attack_number_text, screen );
                    }

                    apply_surface(ene2x, ene2y, unicorn_stab, screen);
                    apply_surface(400, 250, boss_health_text, screen);


                    //apply character 1 text
                    apply_surface( 183, 347, character1_health, screen );
                    apply_surface( 183, 367, character1_total_health, screen );
                    apply_surface( 237, 347, character1_magic, screen );
                    apply_surface( 237, 367, character1_total_magic, screen );
                    apply_surface( 60, 355, character1_name, screen );

                    //apply character 3 text
                    apply_surface( 183, 427, character3_health, screen );
                    apply_surface( 183, 447, character3_total_health, screen );
                    apply_surface( 237, 427, character3_magic, screen );
                    apply_surface( 237, 447, character3_total_magic, screen );
                    apply_surface( 60, 435, character3_name, screen );


                    //Update the screen
                    if ( SDL_Flip( screen ) == -1 )
                    {
                        return 1;
                    }

                    //Cap the frame rate
                    if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                    {
                        SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                    }

                    SDL_Delay(1000);
                    attack_number = 0;
                    bossx = 440;
                    bossy = 190;
                }
                else if (fight_turn == 3 && evil == false)
                {
                    if (order2 == 1)
                    {
                        //if the primary choice is attack then find the target and calculate the results
                        if (player1_array[0] == 1)
                        {
                            if (player1_array[2] == 1)
                            {
                                if (player1_attack_power*50 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 3)
                            {
                                if (player1_attack_power*50 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player1_attack_power*50);
                                }
                            }
                            else if (player1_array[2] == 5)
                            {
                                if (player1_attack_power*50 >= boss_health)
                                {
                                    boss_health = 0;
                                }
                                else
                                {
                                    boss_health = boss_health - (player1_attack_power*50);
                                }
                            }
                            attack_number = player1_attack_power*50;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player1_array[0] == 2)
                        {
                            //if the magic sub selection is Rage
                            if (player1_array[1] == 1)
                            {
                                player1_magic = player1_magic - rage_magic;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_attack_power*50*rage >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player1_attack_power*50*rage >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health -(player1_attack_power*50*rage);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (player1_attack_power*50*rage >= boss_health)
                                    {
                                        boss_health = 0;
                                    }
                                    else
                                    {
                                        boss_health = boss_health -(player1_attack_power*50*rage);
                                    }
                                }

                                attack_number = player1_attack_power*50*rage;
                            }
                            //if the magic sub selection is Burn
                            if (player1_array[1] == 2)
                            {
                                player1_magic = player1_magic - burn_magic;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player1_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player1_magic_power*50);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (player1_magic_power*50 >= boss_health)
                                    {
                                        enemy2_health = 0;
                                    }
                                    else
                                    {
                                        boss_health = boss_health - (player1_magic_power*50);
                                    }
                                }
                                attack_number = player1_magic_power*50;
                            }
                            //if the magic sub selection is LIMIT
                            else if (player1_array[1] == 3)
                            {
                                limit1_power = player1_magic;
                                player1_magic = 0;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    if (boss_health <= limit1_power*player1_attack_power*player1_magic_power)
                                    {
                                        boss_health = 0;
                                    }
                                    else
                                    {
                                        boss_health = boss_health - (limit1_power*player1_attack_power*player1_magic_power);
                                    }
                                }
                                attack_number = limit1_power*player1_attack_power*player1_magic_power;
                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player1_array[0] == 3)
                        {
                            //if the item sub selection is spirit
                            if (player1_array[1] == 1)
                            {
                                player1_item1_count = player1_item1_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player1_health+spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player3_health+spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + spirit;
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    boss_health = boss_health + spirit;
                                }
                            }
                            //if the item sub selection is hi-spirit
                            if (player1_array[1] == 2)
                            {
                                player1_item2_count = player1_item2_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player1_health+hi_spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        break;
                                    }
                                    else if (player3_health+hi_spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + hi_spirit;
                                    }
                                }
                                else if (player1_array[2] == 5)
                                {
                                    boss_health = boss_health + hi_spirit;
                                }
                            }
                            //if the item sub selection is lazarus
                            if (player1_array[1] ==3)
                            {
                                player1_item3_count = player1_item3_count - 1;

                                if (player1_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player1_array[2] == 5)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );


                        char1x = 65;
                        char3x = 15;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stab, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_stance, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        apply_surface( ene2x, ene2y, unicorn, screen);
                        apply_surface( 400, 250, boss_health_text, screen );

                        //apply character 1 text
                        apply_surface( 183, 347, character1_health, screen );
                        apply_surface( 183, 367, character1_total_health, screen );
                        apply_surface( 237, 347, character1_magic, screen );
                        apply_surface( 237, 367, character1_total_magic, screen );
                        apply_surface( 60, 355, character1_name, screen );

                        //apply character 3 text
                        apply_surface( 183, 427, character3_health, screen );
                        apply_surface( 183, 447, character3_total_health, screen );
                        apply_surface( 237, 427, character3_magic, screen );
                        apply_surface( 237, 447, character3_total_magic, screen );
                        apply_surface( 60, 435, character3_name, screen );

                        apply_surface( 150, 140, attack_number_text, screen );


                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char1x = 15;
                    }
                    else if (order2 == 2)
                    {
                        char3x = 65;
                        //the animations will go right here
                        //if the primary choice is attack then find the target and calculate the results
                        if (player3_array[0] == 1)
                        {
                            if (player3_array[2] == 1)
                            {
                                if (player3_attack_power*40 >= player1_health)
                                {
                                    player1_health = 0;
                                }
                                else
                                {
                                    player1_health = player1_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 2)
                            {
                                if (player3_attack_power*40 >= player2_health)
                                {
                                    player2_health = 0;
                                }
                                else
                                {
                                    player2_health = player2_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 3)
                            {
                                if (player3_attack_power*40 >= player3_health)
                                {
                                    player3_health = 0;
                                }
                                else
                                {
                                    player3_health = player3_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 4)
                            {
                                if (player3_attack_power*40 >= enemy1_health)
                                {
                                    enemy1_health = 0;
                                    bad1 = false;
                                }
                                else
                                {
                                    enemy1_health = enemy1_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 5)
                            {
                                if (player3_attack_power*40 >= enemy2_health)
                                {
                                    enemy2_health = 0;
                                    bad2 = false;
                                }
                                else
                                {
                                    enemy2_health = enemy2_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 6)
                            {
                                if (player3_attack_power*40 >= enemy3_health)
                                {
                                    enemy3_health = 0;
                                    bad3 = false;
                                }
                                else
                                {
                                    enemy3_health = enemy3_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 7)
                            {
                                if (player3_attack_power*40 >= enemy4_health)
                                {
                                    enemy4_health = 0;
                                    bad4 = false;
                                }
                                else
                                {
                                    enemy4_health = enemy4_health - (player3_attack_power*40);
                                }
                            }
                            else if (player3_array[2] == 8)
                            {
                                if (player3_attack_power*40 >= enemy5_health)
                                {
                                    enemy5_health = 0;
                                    bad5 = false;
                                }
                                else
                                    enemy5_health = enemy5_health - (player3_attack_power*40);
                            }
                            else if (player3_array[2] == 9)
                            {
                                if (player3_attack_power*40 >= enemy6_health)
                                {
                                    enemy6_health = 0;
                                    bad6 = false;
                                }
                                else
                                {
                                    enemy6_health = enemy6_health - (player3_attack_power*40);
                                }
                            }
                            attack_number = player3_attack_power*40;
                        }
                        //if the primary choice is magic, then find which magic, and then which target then calculate the results
                        else if (player3_array[0] == 2)
                        {
                            //if the magic sub selection is Freeze
                            if (player3_array[1] == 1)
                            {
                                player3_magic = player3_magic - freeze_magic;

                                if (player3_array[2] == 1)
                                {
                                    if (player3_magic_power*50 >= player1_health)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player3_magic_power*50 >= player2_health)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_magic_power*50 >= player3_health)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    if (player3_magic_power*50 >= enemy1_health)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 5)
                                {
                                    if (player3_magic_power*50*freeze >= enemy2_health)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (player3_magic_power*50*freeze);
                                    }
                                    attack_number = player3_magic_power*50*freeze;
                                }
                                else if (player3_array[2] == 6)
                                {
                                    if (player3_magic_power*50 >= enemy3_health)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 7)
                                {
                                    if (player3_magic_power*50 >= enemy4_health)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (player3_magic_power*50);
                                    }
                                }
                                else if (player3_array[2] == 8)
                                {
                                    if (player3_magic_power*50*freeze >= enemy5_health)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                        enemy5_health = enemy5_health - (player3_magic_power*50*freeze);
                                    attack_number = player3_magic_power*50*freeze;
                                }
                                else if (player3_array[2] == 9)
                                {
                                    if (player3_magic_power*50 >= enemy6_health)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (player3_magic_power*50);
                                    }
                                }
                                if (player3_array[2] != 5 && player3_array[2] != 8)
                                {
                                    attack_number = player3_magic_power*50;
                                }
                            }
                            //if the magic sub selection is Power X2
                            else if (player3_array[1] == 2)
                            {
                                player3_magic = player3_magic - power_magic;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player1_attack_power = player1_attack_power*2;
                                    }
                                }
                                else  if (player3_array[2] == 2)
                                {
                                    if (player2_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player2_attack_power = player2_attack_power*2;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_attack_power > 10)
                                        {}
                                    else
                                    {
                                        player3_attack_power = player3_attack_power*2;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                                attack_number = 0;

                            }
                            //if the magic sub selection is LIMIT
                            else if (player3_array[1] == 3)
                            {
                                limit3_power = player3_magic;
                                player3_magic = 0;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player1_health = 0;
                                    }
                                    else
                                    {
                                        player1_health = player1_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player2_health = 0;
                                    }
                                    else
                                    {
                                        player2_health = player2_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        player3_health = 0;
                                    }
                                    else
                                    {
                                        player3_health = player3_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    if (enemy1_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy1_health = 0;
                                        bad1 = false;
                                    }
                                    else
                                    {
                                        enemy1_health = enemy1_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 5)
                                {
                                    if (enemy2_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy2_health = 0;
                                        bad2 = false;
                                    }
                                    else
                                    {
                                        enemy2_health = enemy2_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 6)
                                {
                                    if (enemy3_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy3_health = 0;
                                        bad3 = false;
                                    }
                                    else
                                    {
                                        enemy3_health = enemy3_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 7)
                                {
                                    if (enemy4_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy4_health = 0;
                                        bad4 = false;
                                    }
                                    else
                                    {
                                        enemy4_health = enemy4_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 8)
                                {
                                    if (enemy5_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy5_health = 0;
                                        bad5 = false;
                                    }
                                    else
                                    {
                                        enemy5_health = enemy5_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                else if (player3_array[2] == 9)
                                {
                                    if (enemy6_health <= limit3_power*player3_attack_power*player3_magic_power)
                                    {
                                        enemy6_health = 0;
                                        bad6 = false;
                                    }
                                    else
                                    {
                                        enemy6_health = enemy6_health - (limit3_power*player3_attack_power*player3_magic_power);
                                    }
                                }
                                attack_number = limit3_power*player3_attack_power*player3_magic_power;
                            }
                        }
                        //if the primary selection is items, then find which item, and then which target then calculate the results
                        else if (player3_array[0] == 3)
                        {
                            //if the item sub selection is hi-spirit
                            if (player3_array[1] == 1)
                            {
                                player3_item1_count = player3_item1_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health+hi_spirit > player1_total_health)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                    {
                                        player1_health = player1_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health+hi_spirit > player2_total_health)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                    {
                                        player2_health = player2_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health+hi_spirit > player3_total_health)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                    {
                                        player3_health = player3_health + hi_spirit;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                {
                                    enemy1_health = enemy1_health + hi_spirit;
                                }
                                else if (player3_array[2] == 5)
                                {
                                    enemy2_health = enemy2_health + hi_spirit;
                                }
                                else if (player3_array[2] == 6)
                                {
                                    enemy3_health = enemy3_health + hi_spirit;
                                }
                                else if (player3_array[2] == 7)
                                {
                                    enemy4_health = enemy4_health + hi_spirit;
                                }
                                else if (player3_array[2] == 8)
                                {
                                    enemy5_health = enemy5_health + hi_spirit;
                                }
                                else if (player3_array[2] == 9)
                                {
                                    enemy6_health = enemy6_health + hi_spirit;
                                }
                            }
                            //use this for the hi-ether
                            if (player3_array[1] == 2)
                            {
                                player3_item2_count = player3_item2_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_magic+hi_ether > player1_total_magic)
                                    {
                                        player1_magic = player1_total_magic;
                                    }
                                    else
                                    {
                                        player1_magic = player1_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_magic+hi_ether > player2_total_magic)
                                    {
                                        player2_magic = player2_total_magic;
                                    }
                                    else
                                    {
                                        player2_magic = player2_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_magic+hi_ether > player3_total_magic)
                                    {
                                        player3_magic = player3_total_magic;
                                    }
                                    else
                                    {
                                        player3_magic = player3_magic + hi_ether;
                                    }
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                            }
                            //if the item sub selection is lazarus
                            if (player3_array[1] ==3)
                            {
                                player3_item3_count = player3_item3_count - 1;

                                if (player3_array[2] == 1)
                                {
                                    if (player1_health == 0)
                                    {
                                        player1_health = player1_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 2)
                                {
                                    if (player2_health == 0)
                                    {
                                        player2_health = player2_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 3)
                                {
                                    if (player3_health == 0)
                                    {
                                        player3_health = player3_total_health;
                                    }
                                    else
                                        {}
                                }
                                else if (player3_array[2] == 4)
                                    {}
                                else if (player3_array[2] == 5)
                                    {}
                                else if (player3_array[2] == 6)
                                    {}
                                else if (player3_array[2] == 7)
                                    {}
                                else if (player3_array[2] == 8)
                                    {}
                                else if (player3_array[2] == 9)
                                    {}
                            }
                        }
                        std::stringstream attack_value;
                        attack_value << attack_number;
                        attack_number_text = TTF_RenderText_Solid( font, attack_value.str().c_str(), textColor );


                        char1x = 15;
                        char3x = 65;
                        apply_surface(bgX, bgY, sky, screen );
                        apply_surface( bgX + background->w, bgY, sky, screen );

                        apply_surface( 0, 0, background, screen );
                        apply_surface( 0, 330, command_background, screen );
                        apply_surface( 50, 345, character_background, screen);
                        apply_surface( 50, 385, character_background, screen);
                        apply_surface( 50, 425, character_background, screen);
                        apply_surface( 170, 345, health_counter, screen);
                        apply_surface( 220, 345, magic_counter, screen);

                        if (player1_health != 0)
                        {
                            apply_surface( char1x, char1y, warrior_stance, screen);
                        }
                        else
                        {
                            apply_surface( char1x, char1y, warrior_dead, screen);
                        }

                        if (player3_health != 0)
                        {
                            apply_surface( char3x, char3y, marine_shoot, screen);
                        }
                        else
                        {
                            apply_surface( char3x, char3y, marine_dead, screen);
                        }

                        apply_surface( ene2x, ene2y, unicorn, screen);
                        apply_surface( 400, 250, boss_health_text, screen );

                        //apply character 1 text
                        apply_surface( 183, 347, character1_health, screen );
                        apply_surface( 183, 367, character1_total_health, screen );
                        apply_surface( 237, 347, character1_magic, screen );
                        apply_surface( 237, 367, character1_total_magic, screen );
                        apply_surface( 60, 355, character1_name, screen );

                        //apply character 3 text
                        apply_surface( 183, 427, character3_health, screen );
                        apply_surface( 183, 447, character3_total_health, screen );
                        apply_surface( 237, 427, character3_magic, screen );
                        apply_surface( 237, 447, character3_total_magic, screen );
                        apply_surface( 60, 435, character3_name, screen );

                        apply_surface( 150, 140, attack_number_text, screen );


                        //Update the screen
                        if ( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }

                        //Cap the frame rate
                        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                        {
                            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                        }

                        SDL_Delay(1000);
                        attack_number = 0;
                        char3x = 15;
                    }
                }
                else if (fight_turn == 4)
                {
                    //now reset everything
                    if (player1_health != 0)
                    {
                        arx = 15;
                        ary = 350;
                    }
                    else if (player3_health != 0)
                    {
                        arx = 15;
                        ary = 430;
                    }
                    else
                    {
                        lose = true;
                    }
                    if (player1_health != 0)
                    {
                        good1 = true;
                    }
                    if (player3_health != 0)
                    {
                        good3 = true;
                    }

                    order1 = 0;
                    order2 = 0;
                    order3 = 0;

                    player1_array[0] = 0;
                    player1_array[1] = 0;
                    player1_array[2] = 0;

                    player2_array[0] = 0;
                    player2_array[1] = 0;
                    player2_array[2] = 0;

                    player3_array[0] = 0;
                    player3_array[1] = 0;
                    player3_array[2] = 0;

                    right = true;
                    left = false;
                    choose1 = 0;
                    choose2 = 0;
                    choose3 = 0;
                    choose4 = 0;
                    if (boss_health == 0)
                    {
                        win = true;
                    }

                    fight_turn = 0;
                    fight = false;
                }
                if (player1_health == 0)
                {
                    good1 = false;
                }
                if (player3_health == 0)
                {
                    good3 = false;
                }

                fight_turn = fight_turn + 1;
                music_stop = true;
            }
            if (win == true)
            {
                if (music_stop == true)
                {
                    if ( Mix_PlayMusic(win_music, 1) == 1)
                    {
                        return 1;
                    }
                    music_stop = false;
                }

                SDL_Delay(3100);
                boss1 = false;
                boss2_text = true;
                win = false;
            }
            if (lose == true)
            {
                if (music_stop == true)
                {
                    if ( Mix_PlayMusic(loss_music, 1) == 1)
                    {
                        return 1;
                    }
                    music_stop = false;
                }
                SDL_Delay(5500);
                battle_start = true;
                lose = false;
            }

            //Scroll background
            bgX -= .25;

            //If the background has gone too far
            if ( bgX <= -background->w )
            {
                //Reset the offset
                bgX = 0;
            }


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
                    if ( choose1 == 1 && choose2 == 2)
                    {
                        apply_surface( 505, 350, rage_text, screen );
                        apply_surface( 505, 390, fire_text, screen );
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
                        apply_surface( 505, 350, ice_text, screen );
                        apply_surface( 505, 390, hitx2_text, screen );
                        apply_surface( 505, 430, limit_text, screen );
                    }

                }
                if (choose2 == 3)
                {
                    if (choose1 == 1)
                    {
                        if (play1i == true)
                        {
                            if (play1i1 == true)
                            {
                                apply_surface( 500, 345, item_sub_selection, screen);
                                apply_surface( 505, 350, player1_spirits_text, screen);
                            }
                            if (play1i2 == true)
                            {
                                apply_surface( 500, 385, item_sub_selection, screen);
                                apply_surface( 505, 390, player1_hi_spirits_text, screen);
                            }
                            if (play1i3 == true)
                            {
                                apply_surface( 500, 425, item_sub_selection, screen);
                                apply_surface( 505, 430, player1_lazarus_text, screen);
                            }
                        }
                    }
                    else if (choose1 == 3)
                    {
                        if (choose2 == 3 && play3i == true)
                        {
                            if (play3i1 == true)
                            {
                                apply_surface( 500, 345, item_sub_selection, screen);
                                apply_surface( 505, 350, player3_hi_spirits_text, screen);
                            }
                            if (play3i2 == true)
                            {
                                apply_surface( 500, 385, item_sub_selection, screen);
                                apply_surface( 505, 390, player3_hi_ether_text, screen);
                            }
                            if (play3i3 == true)
                            {
                                apply_surface( 500, 425, item_sub_selection, screen);
                                apply_surface( 505, 430, player3_lazarus_text, screen);
                            }
                        }
                    }
                }
            }

            // show the characters
            // place the characters depending on which one is selected
            if (fight != true)
            {
                if ( (ary == 350 && arx ==  15) || choose1 == 1)
                {
                    char1x = 65;
                    char2x = 15;
                    char3x = 15;
                    if (player3_health == 0)
                    {
                        good3 = false;
                        apply_surface( char3x, char3y, marine_dead, screen);
                    }
                    else
                    {
                        good3 = true;
                        apply_surface( char3x, char3y, marine_stance, screen);
                    }
                    apply_surface( char1x, char1y, warrior_out, screen);
                }
                else if ( ary == 430 && arx ==  15 || choose1 == 3)
                {
                    char1x = 15;
                    char2x = 15;
                    char3x = 65;

                    if (player1_health == 0)
                    {
                        good1 = false;
                        apply_surface( char1x, char1y, warrior_dead, screen);
                    }
                    else
                    {
                        good1 = true;
                        apply_surface( char1x, char1y, warrior_stance, screen);
                    }
                    apply_surface( char3x, char3y, marine_out, screen);

                }
            }

            apply_surface( ene2x, ene2y, unicorn, screen);


// show the arrow
            if ( right == true )
            {
                apply_surface( arx, ary, arrow_right, screen);
            }
            if ( left == true)
            {
                apply_surface(arx, ary, arrow_left, screen);
            }


//----------------------------------------------------------------------------
            //the players health and magic has a string
            std::stringstream play1h;
            std::stringstream play1th;
            std::stringstream play1m;
            std::stringstream play1tm;


            std::stringstream play3h;
            std::stringstream play3th;
            std::stringstream play3m;
            std::stringstream play3tm;

            //the players particular items as a string
            std::stringstream play1item1;
            std::stringstream play1item2;
            std::stringstream play1item3;
            std::stringstream play3item1;
            std::stringstream play3item2;
            std::stringstream play3item3;

            std::stringstream bh;
            bh << boss_health;
            boss_health_text = TTF_RenderText_Solid( font_small, bh.str().c_str(), textColor );
            apply_surface( 400, 250, boss_health_text, screen );




            //convert the player attributes to string
            play1h << player1_health;
            play1th << player1_total_health;
            play1m << player1_magic;
            play1tm << player1_total_magic;

            play3h << player3_health;
            play3th << player3_total_health;
            play3m << player3_magic;
            play3tm << player3_total_magic;



            //convert the players items and numbers into a string
            play1item1 << "SPIRIT[" << player1_item1_count << "]";
            play1item2 << "HI-SPIRIT[" << player1_item2_count << "]";
            play1item3 << "LAZARUS[" << player1_item3_count << "]";


            play3item1 << "HI-SPIRIT[" << player3_item1_count << "]";
            play3item2 << "HI-ETHER[" << player3_item2_count << "]";
            play3item3 << "LAZARUS[" << player3_item3_count << "]";





            //Render the text

            //character1 attributes text
            character1_health = TTF_RenderText_Solid( font_small, play1h.str().c_str(), textColor );
            character1_total_health = TTF_RenderText_Solid( font_small, play1th.str().c_str(), textColor );
            character1_magic = TTF_RenderText_Solid( font_small, play1m.str().c_str(), textColor );
            character1_total_magic = TTF_RenderText_Solid( font_small, play1tm.str().c_str(), textColor );

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
            character1_name = TTF_RenderText_Solid( font, "Knight", textColor );

            character3_name = TTF_RenderText_Solid( font, "Marine", textColor );
            //character 1 magic text
            rage_text = TTF_RenderText_Solid( font, "RAGE", textColor );
            hitx2_text = TTF_RenderText_Solid( font, "POWER X2", textColor );
            limit_text = TTF_RenderText_Solid( font, "LIMIT", textColor );
            //character2 magic text
            fire_text = TTF_RenderText_Solid( font, "BURN", textColor );
            ice_text = TTF_RenderText_Solid( font, "FREEZE", textColor );

            //the names of items
            player1_spirits_text = TTF_RenderText_Solid( font, play1item1.str().c_str(), textColor );
            player1_hi_spirits_text = TTF_RenderText_Solid( font, play1item2.str().c_str(), textColor );
            player1_lazarus_text = TTF_RenderText_Solid( font, play1item3.str().c_str(), textColor );

            player3_hi_spirits_text = TTF_RenderText_Solid( font, play3item1.str().c_str(), textColor );
            player3_hi_ether_text = TTF_RenderText_Solid( font, play3item2.str().c_str(), textColor );
            player3_lazarus_text = TTF_RenderText_Solid( font, play3item3.str().c_str(), textColor );


            //apply character 1 text
            apply_surface( 183, 347, character1_health, screen );
            apply_surface( 183, 367, character1_total_health, screen );
            apply_surface( 237, 347, character1_magic, screen );
            apply_surface( 237, 367, character1_total_magic, screen );
            apply_surface( 60, 355, character1_name, screen );

            //apply character 3 text
            apply_surface( 183, 427, character3_health, screen );
            apply_surface( 183, 447, character3_total_health, screen );
            apply_surface( 237, 427, character3_magic, screen );
            apply_surface( 237, 447, character3_total_magic, screen );
            apply_surface( 60, 435, character3_name, screen );

            //Update the screen
            if ( SDL_Flip( screen ) == -1 )
            {
                return 1;
            }

            //Cap the frame rate
            if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
            {
                SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
            }

        }
        while (boss3_text == true)
        {
            if ( Mix_PlayingMusic() == 0 )
            {
                title_time.start();
                //Play the music
                if ( Mix_PlayMusic( climax, -1 ) == 1 )
                {
                    return 1;
                }
            }

            //Apply the surface to the screen
            apply_surface(bgX, bgY, sky, screen );
            apply_surface( bgX + background->w, bgY, sky, screen );

            apply_surface( 0, 0, background, screen );
            apply_surface( 0, 330, command_background, screen );
            apply_surface( 50, 345, character_background, screen);
            apply_surface( 50, 385, character_background, screen);
            apply_surface( 50, 425, character_background, screen);
            apply_surface( 170, 345, health_counter, screen);
            apply_surface( 220, 345, magic_counter, screen);


            //While there's an event to handle
            while ( SDL_PollEvent( &event ) )
            {
                //If a key was pressed
                if ( event.type == SDL_KEYDOWN )
                {
                    switch ( event.key.keysym.sym )
                    {
                    case SDLK_a:
                    {
                        text_counter = text_counter + 1;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                    }
                }
                //If the user has Xed out the window
                if ( event.type == SDL_QUIT )
                {
                    //Quit the program
                    boss3_text = false;
                }
            }
            if (text_counter == 36)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(100, 30, blerb47, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(ene2x, ene2y, unicorn, screen);
                apply_surface(char3x, char3y, marine_stance, screen);

            }
            if (text_counter == 37)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(200, 130, blerb48, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(ene2x, ene2y, megacorn, screen);
                apply_surface(char3x, char3y, marine_stance, screen);

            }
            if (text_counter == 38)
            {
                if ( Mix_PlayingMusic() != 0 )
                {
                    //Pause the music
                    Mix_HaltMusic();
                }
                boss3_text = false;
                end = true;
                text_counter = 36;
            }
            //Update the screen
            if ( SDL_Flip( screen ) == -1 )
            {
                return 1;
            }

            //Cap the frame rate
            if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
            {
                SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
            }
        }
        while (boss3 == true)
        {
            break;
        }
        while (end == true)
        {
            if ( Mix_PlayingMusic() == 0 )
            {
                title_time.start();
                //Play the music
                if ( Mix_PlayMusic( climax, -1 ) == 1 )
                {
                    return 1;
                }
            }

            //Apply the surface to the screen
            apply_surface(bgX, bgY, sky, screen );
            apply_surface( bgX + background->w, bgY, sky, screen );

            apply_surface( 0, 0, background, screen );
            apply_surface( 0, 330, command_background, screen );
            apply_surface( 50, 345, character_background, screen);
            apply_surface( 50, 385, character_background, screen);
            apply_surface( 50, 425, character_background, screen);
            apply_surface( 170, 345, health_counter, screen);
            apply_surface( 220, 345, magic_counter, screen);


            //While there's an event to handle
            while ( SDL_PollEvent( &event ) )
            {
                //If a key was pressed
                if ( event.type == SDL_KEYDOWN )
                {
                    switch ( event.key.keysym.sym )
                    {
                    case SDLK_a:
                    {
                        text_counter = text_counter + 1;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                    }
                }
                //If the user has Xed out the window
                if ( event.type == SDL_QUIT )
                {
                    //Quit the program
                    end = false;
                }
            }
            if (text_counter == 36)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(100, 50, blerb36, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(ene2x, ene2y, megacorn, screen);
                apply_surface(char3x, char3y, marine_stance, screen);

            }
            if (text_counter == 37)
            {
                char1x = 15;
                char3x = 65;

                apply_surface(100, 180, blerb37, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(ene2x, ene2y, megacorn, screen);
                apply_surface(char3x, char3y, marine_stance, screen);

            }
            if (text_counter == 38)
            {
                char1x = 65;
                char3x = 15;

                apply_surface(100, 50, blerb38, screen);
                apply_surface(char1x, char1y, warrior_stance, screen);
                apply_surface(ene2x, ene2y, megacorn, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 39)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(320, 50, blerb39, screen);
                apply_surface(char1x, char1y, warrior_dead, screen);
                apply_surface(ene1x-176, ene1y, megacorn_stab, screen);
                apply_surface(char3x, char3y, marine_stance, screen);
            }
            if (text_counter == 40)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(320, 190, blerb40, screen);
                apply_surface(char1x, char1y, warrior_dead, screen);
                apply_surface(ene3x-176, ene3y, megacorn_stab, screen);
                apply_surface(char3x, char3y, marine_dead, screen);
            }
            if (text_counter == 41)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(170, 110, blerb41, screen);
                apply_surface(char1x, char1y, warrior_dead, screen);
                apply_surface(ene2x, ene2y, megacorn, screen);
                apply_surface(char3x, char3y, marine_dead, screen);
            }
            if (text_counter == 42)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(170, 110, blerb42, screen);
                apply_surface(char1x, char1y, warrior_dead, screen);
                apply_surface(ene2x, ene2y, megacorn, screen);
                apply_surface(char3x, char3y, marine_dead, screen);
            }
            if (text_counter == 43)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(300, 110, blerb43, screen);
                apply_surface(char1x, char1y, warrior_dead, screen);
                apply_surface(ene2x, ene2y, megacorn, screen);
                apply_surface(char3x, char3y, marine_dead, screen);
            }
            if (text_counter == 44)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(110, 250, blerb44, screen);
                apply_surface(char1x, char1y, warrior_dead, screen);
                apply_surface(ene2x, ene2y, megacorn, screen);
                apply_surface(char3x, char3y, marine_dead, screen);
            }
            if (text_counter == 45)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(90, 230, blerb45, screen);
                apply_surface(char1x, char1y, warrior_dead, screen);
                apply_surface(ene2x, ene2y, megacorn, screen);
                apply_surface(char3x, char3y, marine_dead, screen);
            }
            if (text_counter == 46)
            {
                char1x = 15;
                char3x = 15;

                apply_surface(300, 110, blerb46, screen);
                apply_surface(char1x, char1y, warrior_dead, screen);
                apply_surface(ene2x, ene2y, megacorn, screen);
                apply_surface(char3x, char3y, marine_dead, screen);
            }
            if (text_counter == 47)
            {
                if ( Mix_PlayingMusic() != 0 )
                {
                    //Pause the music
                    Mix_HaltMusic();
                }
                music_stop = true;
                end = false;
                credits = true;
            }

            //Update the screen
            if ( SDL_Flip( screen ) == -1 )
            {
                return 1;
            }

            //Cap the frame rate
            if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
            {
                SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
            }

        }
        while (credits == true)
        {
            intro_text.start();
            bool texting = true;

            while (texting == true)
            {

                title_time.start();
                if (music_stop == true)
                {
                    if ( Mix_PlayMusic(end_music, 1) == 1)
                    {
                        return 1;
                    }
                    music_stop = false;
                }
                if (music_stop == true)
                {
                    if ( Mix_PlayMusic(win_music, 1) == 1)
                    {
                        return 1;
                    }
                    music_stop = false;
                }
                apply_surface(0, 0, text_background, screen);

                apply_surface(50, 40, text1, screen);
                apply_surface(50, 70, text2, screen);
                apply_surface(50, 100, text3, screen);
                apply_surface(50, 130, text4, screen);
                apply_surface(50, 160, text6, screen);
                apply_surface(50, 190, text7, screen);
                apply_surface(50, 220, text8, screen);
                apply_surface(50, 250, text9, screen);
                apply_surface(50, 280, text10, screen);
                apply_surface(50, 310, text11, screen);
                apply_surface(50, 340, text12, screen);
                if (intro_text.get_ticks() > 40000)
                {
                    apply_surface(0, 0, credits_picture, screen);
                }



                while ( SDL_PollEvent( &event ) )
                {
                    //If the user has Xed out the window
                    if ( event.type == SDL_QUIT )
                    {
                        //Quit the program
                        texting = false;
                        break;
                    }
                }



                //Update the screen
                if ( SDL_Flip( screen ) == -1 )
                {
                    return 1;
                }

                //Cap the frame rate
                if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                {
                    SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                }
                if (intro_text.get_ticks() > 1000)
                {
                    text1 = TTF_RenderText_Solid( font, "Upon re-appearing in their own time, ", introColor );
                }
                if (intro_text.get_ticks() > 4000)
                    text2 = TTF_RenderText_Solid( font, "the two warriors were immediately apprehended", introColor );
                if (intro_text.get_ticks() > 4000)
                    text3 = TTF_RenderText_Solid( font, "by the Dark Overlord's forces. ", introColor );
                if (intro_text.get_ticks() > 10000)
                    text4 = TTF_RenderText_Solid( font, "They were brought to his fortress and made to kneel in front of him. ", introColor );
                if (intro_text.get_ticks() > 15000)
                    text6 = TTF_RenderText_Solid( font, "Seeing these warriors brought a smile to the Dark Overlord's face.", introColor );
                if (intro_text.get_ticks() > 20000)
                    text7 = TTF_RenderText_Solid( font, "It has been a long time, hasn't it. Old friends.", introColor );
                if (intro_text.get_ticks() > 23000)
                    text8 = TTF_RenderText_Solid( font, "Looking up from their kneel, ", introColor );
                if (intro_text.get_ticks() > 25000)
                    text9 = TTF_RenderText_Solid( font, "the two warriors gazed upon the face of the Dark Overlord", introColor );
                if (intro_text.get_ticks() > 30000)
                    text10 = TTF_RenderText_Solid( font, "and discovered that the Overlord is THE LAST UNICORN!", introColor );
                if (intro_text.get_ticks() > 35000)
                    text12 = TTF_RenderText_Solid( font, "TO BE CONTINUED. . .", introColor );


            }
            Mix_HaltMusic();
            credits = false;


        }

        break;
    }
//Free the surface and quit SDL
    clean_up();

    return 0;
}
