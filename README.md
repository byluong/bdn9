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
- Traditionally, you use [QMK Configurator](https://config.qmk.fm/#/keebio/bdn9/rev2/LAYOUT) to generate a `.hex`/`.bin` file that is flashed onto the keyboard.
- VIA Configurator can be used as a no-flash alternative, but does NOT support rotary encoders.


QMK it is. We'll be referencing the [bdn9 entry in the qmk repo](https://github.com/qmk/qmk_firmware/tree/master/keyboards/keebio/bdn9).

Moving to QMK's [docs](https://docs.qmk.fm/#/newbs_getting_started):
- Download [QMK Toolbox](https://github.com/qmk/qmk_toolbox)
- Install QMK and run `qmk setup`
- Test your environment by running `qmk compile -kb keebio/bdn9/rev2 -km default`. Ensure you see `make --jobs=1 keebio/bdn9/rev2:default` in the output because we have the rev. 2 PCB.
- Set up build environment (optional)
- Create a custom keymap (in the auto-created git dir with your github name)
- Compile with `qmk compile -kb keebio/bdn9/rev2 -km byluong` or `qmk compile` if you've set up your qmk config already.

# Flashing
https://docs.keeb.io/flashing-firmware#stm32-chip 
- The BDN9 rev. 2 uses a STM32F072 microcontroller which uses a STM32 DFU Bootloader.
- Load up the .bin file compiled from QMK and press the reset button while your board is plugged in and QMK Toolbox is open. The board should be flashed!

