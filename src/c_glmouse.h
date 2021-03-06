/***************************************************************
 **   DLSTORM   Deadline's Code Storm Library
 **          /\
 **   ---- D/L \----
 **       \/
 **   License:      BSD
 **   Copyright:    2013
 **   File:         c_glmouse.h
 **   Class:        C_Mouse
 **                 C_MouseCursor
 **   Description:  Mouse SDL/OpenGL wrapper
 **   Author:       Seth Parson
 **   Twitter:      @Sethcoder
 **   Website:      www.sethcoder.com
 **   Email:        defectiveseth@gmail.com
 **
 ***************************************************************/
#ifndef _DLCS_C_MOUSE
#define _DLCS_C_MOUSE

#include <gl.h>
#include <glu.h>

#include "SDL.h"
#include "c_gaf.h"
#include "c_gfx.h"
#include "c_gltexture.h"
#include "c_log.h"
#include "dlcs.h"

#define C_GLM_DOWNTICK_TIME    60
#define C_GLM_DOUBLECLICK_TIME 300
/////////////////////////////////// C_MouseCursor class
class C_MouseCursor {
   public:
    C_MouseCursor();
    C_MouseCursor(C_GFX *pGFX, CGAF *pInGAF, CLog *pInLog);
    ~C_MouseCursor();
    C_GFX *        pGFX;
    CGLTexture *   pTexture;
    C_MouseCursor *pNext;
    CGAF *         pGAF;
    bool           bCreatedLog;
    CLog *         pLog;
    char           szFilename[_FILENAME_SIZE];  // file name of the cursor
    unsigned char  r, g, b;
    int            x, y;
    char           x_offset, y_offset;
    char           x_hotspot, y_hotspot;
    void           Init(void);
    GLvoid         reload();
    GLvoid         kill();
    GLvoid         load(const char *szInFilename);
    GLvoid         loadGAF(const char *szInFilename);
    GLvoid         draw(void);

    // OLD Constructors that are not necessary
    //  C_MouseCursor();
    //  C_MouseCursor(CLog *pInLog);
    //  C_MouseCursor(CGAF *pInGAF, CLog *pInLog);
    //  C_MouseCursor(string f);
};
/////////////////////////////////// C_Mouse class
class C_Mouse {
   public:
    C_Mouse();
    C_Mouse(C_GFX *pInGFX, CGAF *pInGAF, CLog *pInLog);
    ~C_Mouse();

    C_GFX *        pGFX;
    CLog *         pLog;
    CGAF *         pGAF;
    C_MouseCursor *pFirstMouseCursor;
    C_MouseCursor *pCursor;
    bool           bDraw;
    bool           bLeftDown;
    bool           bMiddleDown;
    bool           bRightDown;
    bool           bLeftRelease;
    bool           bMiddleRelease;
    bool           bRightRelease;
    bool           bLeftDblClick;
    bool           bMiddleDblClick;
    bool           bRightDblClick;
    bool           bWheelUp;
    bool           bWheelDown;
    bool           bLeftDownTick;
    bool           bMiddleDownTick;
    bool           bRightDownTick;
    long           lLeftDblClickTimer;
    long           lMiddleDblClickTimer;
    long           lRightDblClickTimer;
    long           lLeftDownTick;
    long           lMiddleDownTick;
    long           lRightDownTick;
    int            ix;
    int            iy;

    void Init(void);
    // void           InitializeInput(void);
    void Refresh(void);
    void ClearClicks(void);
    bool LeftClick();
    bool MiddleClick();
    bool RightClick();
    bool Click(int iWhich);
    void SetClick(int iWhich, bool set);
    bool DoubleClick(int iWhich);
    void SetDoubleClick(int iWhich, bool set);
    bool ButtonDownTick(int iWhich);
    void SetDownTick(int iWhich, bool set);
    bool ButtonDown(int iWhich);
    void SetButtonDown(int iWhich, bool set);
    int  X(void);
    void SetX(int x);
    int  Y(void);
    void SetY(int y);
    int  WheelUp(void);
    void SetWheelUp(bool m);
    int  WheelDown(void);
    void SetWheelDown(bool m);
    bool InX(int x1, int x2);
    bool InY(int y1, int y2);
    bool In(int x1, int y1, int x2, int y2);
    bool InRect(RECT rc);
    bool InXPct(float fx1, float fx2);
    bool InYPct(float fy1, float fy2);
    bool InPct(float fx1, float fy1, float fx2, float fy2);
    void draw(void);

    // OLD Constructors that are not necessary
    //  C_Mouse();
    //  C_Mouse(CLog *pInLog);
    //  C_Mouse(CGAF *pInGAF, CLog *pInLog);
};

#endif  //_DLCS_C_MOUSE
