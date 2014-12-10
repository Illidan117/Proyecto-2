#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <SDL_mixer.h>
#include <cstdlib>
//CREDITS
//http://opengameart.org
//teckpow laser_shooting_sfx.wav
//Erick Leveron Background Music using Guitar Pro 6 with RSE(Real Sound Effects), Tab made by pasting different styles and rift into a single song.
//Erick Leveron Programming
//Usando el ejemplo en clase como base
//All Images under Public Domain

Mix_Chunk *scratch = NULL; Mix_Chunk *high = NULL; Mix_Chunk *med = NULL; Mix_Chunk *low = NULL;
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*instrucciones,*menu, *paper,*scissor,*rock,*space,*space2,*paper1,*scissor1,*rock1;
SDL_Rect rect_background,rect_instrucciones,rect_menu,rect_paper,rect_scissor,rect_rock, rect_space, rect_space2,rect_pc,rect_paper1,rect_scissor1,rect_rock1;
int ai = 0;
using namespace std;
	int seleccion(int x){
		x = rand()%1+3;
		x = x;
		return x;
	}
int main(int argc, char *args[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
	Mix_Init(0);
	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) 
	{ 
		return false; 
	}
	Mix_Chunk *shotsfired = NULL;
	Mix_Chunk *play = NULL;
	Mix_Chunk *Welcome = NULL;
	Mix_Chunk *instructions = NULL;
	Mix_Chunk *goodbye = NULL;
	Mix_Music *music = 0; 
	music = Mix_LoadMUS( "backtrack.wav" );
	shotsfired = Mix_LoadWAV( "laser_shooting_sfx.wav" );
	play = Mix_LoadWAV( "Play.wav" );
	goodbye = Mix_LoadWAV( "Goodbye.wav" );
	instructions = Mix_LoadWAV("Instructions.wav");
	if(music == NULL) {
	cout << Mix_GetError() << std::endl;;
	}
	 if (Mix_PlayMusic(music, -1) < 0) {
      cout << "Unexpected error";
   }
    if((window = SDL_CreateWindow("Rock, Paper & Scissors", 100, 100, 500, 328, SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        cout << SDL_GetError() <<endl;
        return 30;
    }
    int w=0,h=0;
	instrucciones = IMG_LoadTexture(renderer,"instrucciones.png");
    SDL_QueryTexture(instrucciones, NULL, NULL, &w, &h);
    rect_instrucciones.x = 0; rect_instrucciones.y = 0; rect_instrucciones.w = w; rect_instrucciones.h = h;

	menu = IMG_LoadTexture(renderer,"start.png");
    SDL_QueryTexture(menu, NULL, NULL, &w, &h);
    rect_menu.x = 0; rect_menu.y = 0; rect_menu.w = w; rect_menu.h = h;

    background = IMG_LoadTexture(renderer,"background.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;

	space = IMG_LoadTexture(renderer,"placehold.png");
    SDL_QueryTexture(space, NULL, NULL, &w, &h);
    rect_space.x = 130; rect_space.y = 125; rect_space.w = 100; rect_space.h = 100;
	
	space2 = IMG_LoadTexture(renderer,"placehold.png");
    SDL_QueryTexture(space2, NULL, NULL, &w, &h);
    rect_space2.x = 280; rect_space2.y = 125; rect_space2.w = 100; rect_space2.h = 100;
	ai = rand() % 1 + 3;
    while(true)
    {
		seleccion(ai);
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
			if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_SPACE)
					SDL_DestroyTexture(scissor);
					SDL_DestroyTexture(rock);
					SDL_DestroyTexture(paper);
					SDL_DestroyTexture(scissor1);
					SDL_DestroyTexture(rock1);
					SDL_DestroyTexture(paper1);
                if(Event.key.keysym.sym == SDLK_s){
				if( Mix_PlayChannel( -1, goodbye, 0 ) == -1 ) 
			    { 
				return 0;
				}	
			}
			if(Event.key.keysym.sym == SDLK_p){
				SDL_DestroyTexture(menu);
				SDL_DestroyTexture(instrucciones);
			if( Mix_PlayChannel( -1, play, 0 ) == -1 ) 
			{ 	
				}
			}
			if(Event.key.keysym.sym == SDLK_z){
			SDL_DestroyTexture(instrucciones);
			if( Mix_PlayChannel( -1, play, 0 ) == -1 ) 
			{ 		
				}
			}
			if(Event.key.keysym.sym == SDLK_h){
			SDL_DestroyTexture(menu);
			if( Mix_PlayChannel( -1, instructions, 0 ) == -1 ) 
			{ 		
				}
			}
			if(Event.key.keysym.sym == SDLK_1){
			paper = IMG_LoadTexture(renderer,"Paper.png");
			SDL_QueryTexture(paper, NULL, NULL, &w, &h);
			rect_paper.x = 130; rect_paper.y = 125; rect_paper.w = 100; rect_paper.h = 100;
			if( Mix_PlayChannel( -1, shotsfired, 0 ) == -1 ) 
			{ 	
				}
			}
			if(Event.key.keysym.sym == SDLK_2){
			rock = IMG_LoadTexture(renderer,"Rock.png");
			SDL_QueryTexture(rock, NULL, NULL, &w, &h);
			rect_rock.x = 130; rect_rock.y = 125; rect_rock.w = 100; rect_rock.h = 100;
			if( Mix_PlayChannel( -1, shotsfired, 0 ) == -1 ) 
			{ 
				}
			}
			if(Event.key.keysym.sym == SDLK_3){
			scissor = IMG_LoadTexture(renderer,"Scissor.png");
			SDL_QueryTexture(scissor, NULL, NULL, &w, &h);
			rect_scissor.x = 130; rect_scissor.y = 125; rect_scissor.w = 100; rect_scissor.h = 100;
			if( Mix_PlayChannel( -1, shotsfired, 0 ) == -1 ) 
			{ 
				
				}
			}
			if(Event.key.keysym.sym == SDLK_KP_3){
			paper1 = IMG_LoadTexture(renderer,"Paper2.png");
			SDL_QueryTexture(paper1, NULL, NULL, &w, &h);
			rect_paper1.x = 130; rect_paper1.y = 125; rect_paper1.w = 100; rect_paper1.h = 100;
			if( Mix_PlayChannel( -1, shotsfired, 0 ) == -1 ) 
			{ 

				}
			}
			if(Event.key.keysym.sym == SDLK_KP_1){
			rock1 = IMG_LoadTexture(renderer,"Rock2.png");
			SDL_QueryTexture(rock1, NULL, NULL, &w, &h);
			rect_rock1.x = 280; rect_rock1.y = 125; rect_rock1.w = 100; rect_rock1.h = 100;
			if( Mix_PlayChannel( -1, shotsfired, 0 ) == -1 ) 
			{ 

				}
			}
			if(Event.key.keysym.sym == SDLK_KP_2){
			scissor1 = IMG_LoadTexture(renderer,"Scissor2.png");
			SDL_QueryTexture(scissor1, NULL, NULL, &w, &h);
			rect_scissor1.x = 280; rect_scissor1.y = 125; rect_scissor1.w = 100; rect_scissor1.h = 100;
			if( Mix_PlayChannel( -1, shotsfired, 0 ) == -1 ) 
			{  
				}
			}
		}
		SDL_RenderCopy(renderer, menu, NULL, &rect_menu);
        SDL_RenderCopy(renderer, background, NULL, &rect_background);
		SDL_RenderCopy(renderer, space, NULL, &rect_space);
		SDL_RenderCopy(renderer, space2, NULL, &rect_space2);
		SDL_RenderCopy(renderer, paper, NULL, &rect_paper);
		SDL_RenderCopy(renderer, rock, NULL, &rect_rock);
		SDL_RenderCopy(renderer, scissor, NULL, &rect_scissor);
		SDL_RenderCopy(renderer, paper1, NULL, &rect_paper1);
		SDL_RenderCopy(renderer, rock1, NULL, &rect_rock1);
		SDL_RenderCopy(renderer, scissor1, NULL, &rect_scissor1);
		SDL_RenderCopy(renderer, instrucciones, NULL, &rect_instrucciones);
		SDL_RenderCopy(renderer, menu, NULL, &rect_menu);

        SDL_RenderPresent(renderer);
    }
	}
    return 0;
}