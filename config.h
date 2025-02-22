/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 0;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=14:antialias=true:autohint=true" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font:size=14:antialias=true:autohint=true";
static const char col_base03[]      = "#002b36";
static const char col_base02[]      = "#073642";
static const char col_base01[]      = "#586e75";
static const char col_base00[]      = "#657b83";
static const char col_base0[]       = "#839496";
static const char col_base1[]       = "#93a1a1";
static const char col_base2[]       = "#eee8d5";
static const char col_base3[]       = "#fdf6e3";
static const char col_yellow[]      = "#b58900";
static const char col_orange[]      = "#cb4b16";
static const char col_red[]         = "#dc322f";
static const char col_magenta[]     = "#d33682";
static const char col_violet[]      = "#6c71c4";
static const char col_blue[]        = "#268bd2";
static const char col_cyan[]        = "#2aa198";
static const char col_green[]       = "#859900";
static const char *colors[][3]      = {
    /*               fg         bg         border   */
    [SchemeNorm] = { col_base0, col_base03, col_base02 },
    [SchemeSel]  = { col_base03, col_cyan,   col_blue  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6" };

static const Rule rules[] = {
	/* class	instance	title	tags mask	isfloating	monitor */
    { NULL,     NULL,       NULL,   0,          0,          -1 }, 	// Dummy rule
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "∞",      tile },    /* first entry is default */
	{ "␀",      NULL },    /* no layout function means floating behavior */
	{ "◯",      monocle }, /* monocle */
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_base03, "-nf", col_base0, "-sb", col_cyan, "-sf", col_base3, NULL };
static const char *termcmd[]  = { "alacritty", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      		spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, 		spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      		togglebar,      {0} },
	{ MODKEY,                       XK_j,      		focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      		focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      		incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      		incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      		setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      		setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, 		zoom,           {0} },
	{ MODKEY,                       XK_Tab,    		view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,     	    killclient,     {0} },
	{ MODKEY,                       XK_t,     		setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      		setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      		setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_s,	  		setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  		togglefloating, {0} },
	{ MODKEY,                       XK_0,      		view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      		tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  		focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, 		focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  		tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, 		tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },

/* new keybindings - phase 1 = COMPLETE */
    { MODKEY,                       XK_Escape,      		quit,	{1} },
    { MODKEY,                       XK_F3,          		spawn,  SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5%") },
    { MODKEY,                       XK_F4,          		spawn,  SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5%") },
    { MODKEY,                       XK_F5,          		spawn,  SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle") },
    { MODKEY,                       XK_F6,          		spawn,  SHCMD("playerctl previous") },
    { MODKEY,                       XK_F7,          		spawn,  SHCMD("playerctl play-pause") },
    { MODKEY,                       XK_F8,          		spawn,  SHCMD("playerctl next") },
    { MODKEY,                       XK_F9,          		spawn,  SHCMD("gnome-screenshot") },
    { MODKEY,                       XK_F10,         		spawn,  SHCMD("nmcli radio wifi on  && alacritty -e echo 'Wi-Fi has been turned ON.'") },
	{ MODKEY|ShiftMask,             XK_F10,         		spawn,  SHCMD("nmcli radio wifi off && alacritty -e echo 'Wi-Fi has been turned OFF.'") },
	{ MODKEY|ControlMask,           XK_F10,         		spawn,  SHCMD("nmcli radio wifi off && slock") },
	{ MODKEY|ShiftMask,             XK_v,           		spawn,  SHCMD("alacritty -e pulsemixer") },

/* new keybindings - phase 2 = TESTING */
	{ MODKEY|ControlMask, 			XK_Delete, 				spawn, 	SHCMD("alacritty -e sudo reboot") },
	{ MODKEY, 						XK_Menu, 				spawn, 	SHCMD("geany /home/u/d/etc/t.txt") },
	{ MODKEY, 						XK_Home, 				spawn, 	SHCMD("pcmanfm /home/u/") },
	{ MODKEY, 						XK_Page_Down, 			spawn, 	SHCMD("feh --bg-fill --randomize ~/i/wp/*") },	
	{ MODKEY, 						XK_equal, 				spawn, 	SHCMD("galculator") },
	{ MODKEY, 						XK_slash, 				spawn, 	SHCMD("chromium --new-window") },
	{ MODKEY, 						XK_Super_L, 			spawn, 	SHCMD("alacritty -e mpv --no-audio-display --shuffle --loop-playlist=inf /home/u/m/") },
	{ MODKEY|ShiftMask, 			XK_Super_L, 			spawn, 	SHCMD("alacritty -e mpv --no-audio-display --shuffle --loop-playlist=inf /home/u/m/z") },
};

static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
