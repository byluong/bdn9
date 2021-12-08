# What is the BDN9?
A 3x3 macropad PCB. See: https://keeb.io/products/bdn9-rev-2-3x3-9-key-macropad-rotary-encoder-and-rgb.

# Parts List:
- BDN9 Rev. 2
- EC11 rotary encoders with knobs (x3)
- Kailh Speed Copper Switches (x6)
- DSA Granite Keycaps
- FR4 Plate Kit
- USB-C Cable
- Adhesive Rubber Feet (highly recommended)

<img src="https://user-images.githubusercontent.com/6886452/145150769-2c59d088-8d65-4ae9-b6e4-ee7af939015f.jpg" width=50% height=50%><img src="https://user-images.githubusercontent.com/6886452/145150755-7f397ae0-de82-4377-a74d-8e9ceb59bab0.jpg" width=50% height=50%>

# Rebinding with QMK
The default keymaps are listed [here](https://docs.keeb.io/default-keymaps), but we'll be changing these with QMK.

Let's start with Keebio's own [documentation](https://docs.keeb.io/via):
- Traditionally, you use QMK Configurator to generate a `.hex`/`.bin` file that is flashed onto the keyboard.
- VIA Configurator can be used as a no-flash alternative, but does NOT support rotary encoders.


QMK it is.

Moving to QMK's [docs](https://docs.qmk.fm/#/newbs_getting_started):
- Download [QMK Toolbox](https://github.com/qmk/qmk_toolbox)
- Install QMK and run `qmk setup`
