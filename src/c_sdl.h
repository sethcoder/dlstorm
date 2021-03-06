/***************************************************************
 **   DLSTORM   Deadline's Code Storm Library
 **          /\
 **   ---- D/L \----
 **       \/
 **   License:      BSD
 **   Copyright:    2020
 **   File:         c_sdl.cpp
 **   Description:  SDL Wrapper Class Header File
 **   Author:       Seth Parson aka Deadline
 **   Twitter:      @Sethcoder
 **   Website:      www.sethcoder.com
 **   Email:        defectiveseth@gmail.com
 ***************************************************************/

#ifndef _DLCS_SDL_WRAPPER_CLASS
#define _DLCS_SDL_WRAPPER_CLASS

#ifdef TEST_VGA16
#define NUM_COLORS 16
#else
#define NUM_COLORS 256
#endif

#include "SDL.h"
// ubuntu linux: - Simple DirectMedia Layer
// apt install libsdl2-2.0-0 libsdl2-dev
// path to sdl2 includes: /usr/include/SDL2
#include "SDL_image.h"
// ubuntu linux: - SDL Image
// apt install libsdl2-image-2.0-0 libsdl2-image-dev
// path to sdl2-image includes: /usr/include/SDL2

// TODO:
// sdl2-mixer
// sdl2-net
// sdl2-ttf

#include "c_gaf.h"
#include "c_log.h"

#pragma comment(lib, "SDLmain.lib")
#pragma comment(lib, "SDL.lib")
#pragma comment(lib, "SDL_image.lib")

class CSprite;
class CMouse;
class C2DFont;

//#define SDL_RGB(r,g,b) SDL_MapRGB(GFX->screen->format,r,g,b)
//#define _RGB(r,g,b) SDL_MapRGB(GFX->screen->format,r,g,b)
//#define __RGB(r,g,b) SDL_MapRGB(screen->format,r,g,b)
// extern "C" SDL_Surface *LoadGAFSurface(CGAF* gaf,char *fn);

class CSDL_Wrap {
   public:
    CSDL_Wrap();
    CSDL_Wrap(const char *appname);
    CSDL_Wrap(const char *appname, Uint32 nw, Uint32 nh, Uint32 nb);
    CSDL_Wrap(const char *appname, Uint32 nw, Uint32 nh, Uint32 nb, SDL_Surface *icon);
    CSDL_Wrap(const char *appname, Uint32 nw, Uint32 nh, Uint32 nb, const char *icon);
    CSDL_Wrap(const char *appname, Uint32 nw, Uint32 nh, Uint32 nb, const char *icon, bool fullscreen, CLog *inlog, CGAF *ingaf);
    ~CSDL_Wrap();

    bool          InitSuccess;
    int           w;
    int           h;
    int           b;
    int           videoflags;
    bool          bFullScreen;
    char          APP_NAME[_MAX_PATH];
    CMouse *      pMouse;
    CGAF *        pGAF;
    CLog *        pLog;
    C2DFont *     Font;
    SDL_Window *  window;
    SDL_Renderer *renderer;
    SDL_Surface * screen;
    SDL_Surface * Icon;
    CSprite *     pFirstSprite;
    void          ZeroVars(void);
    bool          Begin(const char *an, Uint32 width, Uint32 height, Uint32 bpp, SDL_Surface *icon);
    bool          Begin(const char *an, Uint32 width, Uint32 height, Uint32 bpp, const char *icon);
    bool          Init2D(int width, int height, int bpp);
    bool          Init2D(int width, int height, int bpp, SDL_Surface *icon);
    bool          ToggleFullScreen(void);
    Uint32        GetPixel(int x, int y);
    void          PutPixel(int x, int y, Uint32 pixel);
    void          DrawRect(int x, int y, int w, int h, Uint32 color);
    void          ClearScreen(Uint32 color);
    void          Flip(void);
    void          LoadFont(const char *fn);
    SDL_Surface * LoadMemSurface(SDL_RWops *rw);
    SDL_Surface * LoadGAFSurface(const char *fn);
    void          DrawMap(void);
    void          RebuildGAF(void);
    void          Write(int x, int y, const char *string, int bank);
    void          SpritesDraw(void);
    void          SpriteAdd(const char *name, const char *file);
    void          SpriteDel(const char *name);
    void          SpritesClear(void);
    void          SpriteChangeRect(const char *name, int which, int x, int y, int w, int h);
    CSprite *     SpriteFind(const char *name);
    CSprite *     SpriteFindLast(void);
    void          SpriteShow(const char *name);
    void          SpriteHide(const char *name);
    void          SpriteSetAnimated(const char *name, bool animated);
    void          SpriteSetAnimFrame(const char *name, int frame);
    void          SpriteSetAnimFrames(const char *name, int frames);
    void          SpriteSetAnimSpeed(const char *name, long speed);
    void          SpriteSetAnimLoop(const char *name, bool loop);
};

class CMouse {
   public:
    CMouse();
    ~CMouse();
    bool bLeftDown, bMiddleDown, bRightDown;
    bool bLeftRelease, bMiddleRelease, bRightRelease;
    bool bLeftDblClick, bMiddleDblClick, bRightDblClick;
    bool bWheelUp, bWheelDown;
    long dwLeftDblClickTimer, dwMiddleDblClickTimer, dwRightDblClickTimer;
    int  ix, iy;
    void Init(void);
    void ShutDown(void);
    void RefreshMouse(void);
    void UpdateWheel(SDL_Event e);
    bool GetMouseRelease(int iWhich);
    void SetMouseRelease(int iWhich, bool set);
    bool GetMouseDown(int iWhich);
    void SetMouseDown(int iWhich, bool set);
    bool GetMouseDblClick(int iWhich);
    void SetMouseDblClick(int iWhich, bool set);
    int  GetMouseX(void);
    void SetMouseX(int x);
    int  GetMouseY(void);
    void SetMouseY(int y);
    int  GetMouseWheelUp(void);
    void SetMouseWheelUp(bool m);
    int  GetMouseWheelDown(void);
    void SetMouseWheelDown(bool m);
    bool MouseInX(int x1, int x2);
    bool MouseInY(int y1, int y2);
    bool MouseIn(int x1, int y1, int x2, int y2);
    // bool MouseInXPct(float fx1,float fx2);
    // bool MouseInYPct(float fy1,float fy2);
    // bool MouseInPct( float fx1,float fy1, float fx2,float fy2);
};

class C2DFont {
   public:
    C2DFont(CSDL_Wrap *inSDL);
    C2DFont(CSDL_Wrap *inSDL, const char *file);
    ~C2DFont();
    CSDL_Wrap *  SDL;
    void         Write(int x, int y, const char *string, int bank);
    void         Load(const char *file);
    SDL_Surface *FontSurface;
};

class CSprite {
   public:
    CSprite();
    CSprite(CSDL_Wrap *inSDL);
    CSprite(CSDL_Wrap *inSDL, SDL_Surface *source_surface);
    CSprite(CSDL_Wrap *inSDL, SDL_Surface *source_surface, SDL_Surface *target_surface);
    ~CSprite();
    char         szName[_NAME_SIZE];
    CSprite *    pNext;
    CSDL_Wrap *  SDL;
    int          x;
    int          y;
    SDL_Surface *source_surface;
    SDL_Surface *target_surface;
    SDL_Rect     rect[256];
    bool         visible;
    int          animation_frame;
    int          animation_lastframe;
    long         animation_speed;
    bool         animation_loop;
    bool         animated;
    long         animtimer;
    void         Init(void);
    void         LoadSurface(const char *filename);
    void         LoadMemSurface(unsigned char *fb);
    void         SetColorKey(int r, int g, int b);
    void         Draw(float x, float y);
    void         Draw();
    void         SetRect(int which, int x, int y, int w, int h);
    float        xdir;
    float        ydir;
    float        xspeed;
    float        yspeed;
};

#endif  // _DLCS_SDL_WRAPPER_CLASS
