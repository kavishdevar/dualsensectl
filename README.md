# DualSense control app for linux

Control your dualsense controller using this app on linux.

# Direct Run
## Download and Extract
1) Go to [Releases](/releases)
2) Download the zip file named ```dualsensectl-[ver].zip```
3) Extract it
4) cd to the directory where its extracted 
5) Now Run
```bash
./DualSenseCtl
```

# Build
## Open a terminal 
Press <kbd>Ctrl</kbd> + <kbd>Alt</kbd> + <kbd>t</kbd>
or 
Open it via gui depending upon your distro

## After that enter these commands.

```bash
git clone https://github.com/kavishdev/dualsensectl.git #Clone Repo
cd dualsensectl
mkdir build
cd build
cmake .. #run CMake
make #Build files
```

You will have a executable known as DualSenseCtl in the build forder

## Now run
```bash
./DualSenseCtl
```

This will open up a window.

## Enjoy controlling your controller

# Build and Install

## Repeat the steps for building if not already done.

## Run Make Install

Run this command and this will install exec file to ```/usr/local/bin```

```bash
make install
```
---
# Just for Me :-)

### TODO

#### Make deb file 

```## Download and Extract
1) Go to [Releases](/releases)
2) Download the zip file named ```dualsensectl-[ver].deb```
5) Now Run
DualSenseCtl from any where in your terminal 
```