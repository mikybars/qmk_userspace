# My QMK keymap store ⌨️

<div align="center">
   <img src="https://github.com/user-attachments/assets/67ad7a37-b355-4f4b-8e37-0b26f642f55c" width="300" alt="QMK setup logo">
</div>

## Installation

Flashing the firmware to your keyboard requires the QMK CLI tool. The following instructions are for macOS.

   ```sh
   brew install qmk/qmk/qmk
   ```

Alternatively you can use [QMK Toolbox](https://qmk.fm/toolbox), which is a popular GUI flashing tool.

   ```sh
   brew install qmk-toolbox
   ```

Although not mandatory it is highly recommended to have the GitHub CLI installed to streamline interactions with the CI in case you're going to build via GitHub Actions.

   ```sh
   brew install gh
   ```

## Building and flashing

This repo serves as an [External QMK Userspace](https://docs.qmk.fm/newbs_external_userspace) and as such it can be used to build the QMK firmware in either of two ways.

### GitHub Actions

✅ Easier. No setup required.

❌ Longer feedback loop. Changes need to go through CI.

1. Push your changes to the remote.

   ```sh
   git push origin main
   ```

2. Wait for the CI to pass.

   ```sh
   gh run watch
   ```

3. Grab the firmware from the CI artifacts.

   ```sh
   gh run download
   ```
   > ℹ️ Please note that these artifacts are ephemeral and they may be expired if you try to access them later on. You can always grab the latest firmware from the [Releases](https://github.com/mikybars/qmk_userspace/releases) page.

4. Flash the firmware to your keyboard.

   ```sh
   qmk flash keebio_iris_rev7_mikybars.hex
   ```

### Local

✅ Shorter feedback loop. Errors are caught earlier.

❌ Trickier to set up. Plus you need to download the entire [QMK repo](https://github.com/qmk/qmk_firmware).

1. [Set up QMK](https://docs.qmk.fm/newbs).

   ```sh
   qmk setup
   ```

2. Clone this repo locally.

   ```sh
   git clone https://github.com/mikybars/qmk_userspace
   # or gh repo clone qmk_userspace
   ```

3. Run the following shell command, replacing "`path/to/qmk_userspace`" with the
   relative path to your clone of `qmk_userspace` from the previous step.

   ```sh
   qmk config user.overlay_dir="$(realpath path/to/qmk_userspace)"
   ```

4. (optional) If you only have one keyboard/keymap or you're going to build the same keyboard/keymap frequently, you can set those as default.

   ```sh
   qmk config user.keyboard=keebio/iris/rev7
   qmk config user.keymap=mikybars
   ```

5. Build & flash. 

   ```sh
   qmk flash                         # use defaults
   qmk flash -km mikybars-alt        # build & flash a different keymap
   qmk compile -kb keebio/iris/rev8  # build a newer keyboard (compile only)
   ```
   > ℹ️ Please note that with the previous configuration you don't need to be in any particular directory to run these commands.
   
6. (bonus) Add a new keymap.

   ```sh
   cd path/to/qmk_userspace
   qmk new-keymap -kb kbdfans/kbd75/rev2 -km mikybars
   ```

## Acknowledgments ❤️

Thanks to Pascal Getreuer for his contributions to the QMK community, especially for his interesting [posts](https://getreuer.info/posts/keyboards/index.html) which served me as inspiration to adopt some amazing features such as [Caps Word](https://getreuer.info/posts/keyboards/caps-word/index.html) and [Layer Lock key](https://getreuer.info/posts/keyboards/layer-lock/index.html).