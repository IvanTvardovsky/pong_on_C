# Pong game on C
Project was made for one of my study projects. It was necessary to make it from the minimum number of tools and libraries, so the code is pretty simple.

![giphy gif](https://github.com/IvanTvardovsky/pong_on_C/blob/main/pictures/readme.gif)

The game ends when one of the players scores 21 points.

**Controls:**

***A/Z*** for left player, ***K/M*** for right player.

It contains two versions:

1. **pong.c**

      It uses only stdio.h and stdlib.h. For one tick programme needs one movement key, then *ENTER*. Space bar is for skipping turn.
      
      So you can decide what the rules are: take turns or the one on whose side the ball goes.
      
      How to compile:
      
      > gcc pong.c -o pong.o
      
      > ./pong.o
      
2. **pong_dynamic.c**
      It additionally ncurses.h. No need to press *ENTER*, so you can move rackets at the same time. 
      
      *Do not hold dows a key, only tapping*.
      
      How to compile:
      
      > gcc pong_dymanic.c -lncurses -o pong_dynamic.o
      
      > ./pong_dynamic.o
      
      You may need to download ncurses packages.
