/*This source code copyrighted by Lazy Foo' Productions (2004-2012)
and may not be redestributed without written permission.*/

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The frames per second
const int FRAMES_PER_SECOND = 13;

//The dimensions of the stick figure
const int FOO_WIDTH = 171;
const int FOO_HEIGHT = 100;



//The surfaces
SDL_Surface *foo = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

//The areas of the sprite sheet
SDL_Rect clips_warrior[ 8 ];

//The stick figure
class Warrior
{
    private:
    //The offset
    int offSet;

    //Its rate of movement
    int velocity;

    //Its current frame
    int frame;

    //Its animation status
    int status;

    public:
    //Initializes the variables
    Warrior();

    //Handles input
    void handle_events();

    //Shows the stick figure
    void show();
};

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
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 255, 0, 255 ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}

void apply_surface_anime( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

void set_clips()
{
    //Clip the sprites
    clips_warrior[ 0 ].x = 233;
    clips_warrior[ 0 ].y = 0;
    clips_warrior[ 0 ].w = 120;
    clips_warrior[ 0 ].h = FOO_HEIGHT;

    clips_warrior[ 1 ].x = 233;
    clips_warrior[ 1 ].y = 0;
    clips_warrior[ 1 ].w = 120;
    clips_warrior[ 1 ].h = FOO_HEIGHT;

    clips_warrior[ 2 ].x = 383;
    clips_warrior[ 2 ].y = 0;
    clips_warrior[ 2 ].w = FOO_WIDTH;
    clips_warrior[ 2 ].h = FOO_HEIGHT;

    clips_warrior[ 3 ].x = 533;
    clips_warrior[ 3 ].y = 0;
    clips_warrior[ 3 ].w = FOO_WIDTH;
    clips_warrior[ 3 ].h = FOO_HEIGHT;

    clips_warrior[ 4 ].x = 683;
    clips_warrior[ 4 ].y = 0;
    clips_warrior[ 4 ].w = FOO_WIDTH;
    clips_warrior[ 4 ].h = FOO_HEIGHT;

    clips_warrior[ 5 ].x = 833;
    clips_warrior[ 5 ].y = 0;
    clips_warrior[ 5 ].w = FOO_WIDTH;
    clips_warrior[ 5 ].h = FOO_HEIGHT;

    clips_warrior[ 6 ].x = 983;
    clips_warrior[ 6 ].y = 0;
    clips_warrior[ 6 ].w = FOO_WIDTH;
    clips_warrior[ 6 ].h = FOO_HEIGHT;

    clips_warrior[ 7 ].x = 1167;
    clips_warrior[ 7 ].y = 0;
    clips_warrior[ 7 ].w = FOO_WIDTH;
    clips_warrior[ 7 ].h = FOO_HEIGHT;
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

    //Set the window caption
    SDL_WM_SetCaption( "Animation Test", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{
    //Load the sprite sheet
    foo = load_image( "warrior_sheet.png" );

    //If there was a problem in loading the sprite
    if( foo == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the surface
    SDL_FreeSurface( foo );

    //Quit SDL
    SDL_Quit();
}

Warrior::Warrior()
{
    //Initialize movement variables
    offSet = 200;

    //Initialize animation variables
    frame = 0;
    status = 0;
}

void Warrior::handle_events()
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Set the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: status = 1; break;
        }
    }

}

void Warrior::show()
{
    //If the animation is on
    if( status == 1 )
    {
        //Move to the next frame in the animation
        frame++;
    }

    //If Foo standing
    else
    {
        //Restart the animation
        frame = 1;
    }

    //Loop the animation
    if( frame >= 7 )
    {
        status = 0;
        velocity = 0;
        frame = 0;
    }


        apply_surface_anime( offSet, SCREEN_HEIGHT - FOO_HEIGHT, foo, screen, &clips_warrior[ frame ] );


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
    if( ( started == true ) && ( paused == false ) )
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
    if( paused == true )
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
    if( started == true )
    {
        //If the timer is paused
        if( paused == true )
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
    //Quit flag
    bool quit = false;

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

    //Clip the sprite sheet
    set_clips();

    //The frame rate regulator
    Timer fps;

    //The stick figure
    Warrior walk;

    //While the user hasn't quit
    while( quit == false )
    {
        //Start the frame timer
        fps.start();

        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //Handle events for the stick figure
            walk.handle_events();

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }



        //Fill the screen white
        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

        //Show the stick figure on the screen
        walk.show();

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }

    //Clean up
    clean_up();

    return 0;
}
