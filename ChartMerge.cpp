#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
    SDL_SetAppMetadata("Example Renderer Clear", "1.0", "com.example.renderer-clear");
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("无法初始化 SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    if (!SDL_CreateWindowAndRenderer(
        "examples/renderer/clear",
         640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_Log("无法创建窗口/渲染器: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    SDL_SetRenderLogicalPresentation(renderer, 640, 480, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    return SDL_APP_CONTINUE;
}
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}
SDL_AppResult SDL_AppIterate(void *appstate) {

    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;
}
void SDL_AppQuit(void *appstate, SDL_AppResult result) {
}