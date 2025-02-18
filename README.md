# dwm Custom Configuration

This is a custom configuration for dwm (dynamic window manager), designed for a lean, efficient, and highly functional environment. This README will guide you through the setup and key features of the configuration.

## Features

- **Appearance**: Minimalistic design with JetBrainsMono Nerd Font and a color scheme based on the Solarized palette.
- **Layout**: A dynamic set of layouts to handle tiling, floating windows, and monocle mode.
- **Keybindings**: Efficient and intuitive keybindings for managing windows, launching applications, and controlling system functions.
- **Volume and Media Controls**: Bindings to control system volume and media playback via `pactl` and `playerctl`.
- **Networking Controls**: Toggle Wi-Fi with `nmcli`.

## Requirements

- **dwm** (dynamic window manager)
- **alacritty** (terminal emulator)
- **dmenu** (application launcher)
- **pactl** (PulseAudio control tool)
- **playerctl** (media player control tool)
- **nmcli** (NetworkManager command-line interface)

## Installation

1. Clone this repository:

   ```bash
   git clone https://github.com/yourusername/dwm-config.git
   cd dwm-config
   ```

2. Copy the `config.h` file to your dwm source directory:

   ```bash
   cp config.h /path/to/dwm/
   ```

3. Recompile dwm:

   ```bash
   cd /path/to/dwm
   sudo make clean install
   ```

4. Restart dwm.

## Configuration

### Appearance

The configuration uses **JetBrainsMono Nerd Font** with a size of `14` for clarity and legibility. The bar is displayed at the top (`topbar = 1`) with customized colors based on the Solarized palette.

- **Fonts**: JetBrainsMono Nerd Font
- **Color Scheme**: Solarized colors for a calm and efficient coding environment.

### Layouts

- **Tile**: The default tiling layout.
- **Floating**: Allows floating windows without tiling.
- **Monocle**: Displays one window maximized.

The layout can be toggled with the following keybindings:

- `Mod+t` – Tiling layout
- `Mod+f` – Floating layout
- `Mod+m` – Monocle layout

### Keybindings

- **Mod + p**: Launch dmenu
- **Mod + Return**: Open terminal (Alacritty)
- **Mod + j/k**: Focus next/previous window
- **Mod + h/l**: Resize master area
- **Mod + 1-9**: Switch between tags (workspaces)
- **Mod + Shift + q**: Quit dwm

#### Volume and Media Control

- **Mod + F3**: Decrease volume (`pactl`)
- **Mod + F4**: Increase volume (`pactl`)
- **Mod + F5**: Toggle mute (`pactl`)
- **Mod + F6**: Previous media track (`playerctl`)
- **Mod + F7**: Play/Pause media (`playerctl`)
- **Mod + F8**: Next media track (`playerctl`)
- **Mod + F9**: Take screenshot (`gnome-screenshot`)
- **Mod + F10**: Turn Wi-Fi on
- **Mod + Shift + F10**: Turn Wi-Fi off

### Networking Controls

- **Mod + F10**: Turn Wi-Fi on with `nmcli`.
- **Mod + Shift + F10**: Turn Wi-Fi off with `nmcli`.

### Tagging

Tags represent virtual workspaces that can be switched with `Mod + 1-9` keys.

## Customization

You can adjust the configuration by editing `config.h` to fit your preferences:

- Change the font: Modify the `fonts[]` array.
- Change the colors: Modify the color constants.
- Adjust the layouts: Modify the `layouts[]` array.
- Modify keybindings: Add or adjust keybindings in the `keys[]` array.

## License

This dwm configuration is released under the MIT License.

See LICENSE file for details.
