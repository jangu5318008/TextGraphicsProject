#include <iostream>
#include "TextGraphics.h"
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

////////MODIFIED HEADER FILE WIDTH AND HEIGHT 
int main () {


    //Creates TextGraphics object, linked from .header file
    TextGraphics tg;
    int width = WIDTH;
    int height = HEIGHT;
    //Check terminal size
    if (width == 0 || height == 0) {
        cout << "Terminal size error.\n";
        return 1;
    }
     
    //nullptr will generate new seed upon every execution
    srand(time(nullptr));


    //y coordinate of each rain column
    vector<int> drops(width);
    //fall speed
    vector<int> speed(width);
    /*1 + rand() % x ensures the speed will never be 0
    resulting in frozen program*/
    for (int i = 0; i < width; i++) {

        drops[i] = rand() % height;
        speed[i] = 2 + rand() % 7;
        if (rand() % 20 == 0) {
            speed[i] = 8;
        }
    }
    //Loop forever
    while (true) {
    tg.clearScreen();
    for (int j = 0; j < width; j++) {
        //tg.clearScreen();
        if (drops[j] >= height) {
            drops[j] = 0;
        }

        int y = drops[j];
        if (y < 0) {
            y = 0;
        }
        if (y >= height) {
            y = height - 1;
        }

        char headChar = 33 + rand() % 94;
        //Jason entered y and j in reverse order and the rain was flowing horizontally
        tg.putCharAt(y, j, headChar, Color::White);

        for (int tail = 1; tail <= 5; tail++) {
            int drawY = y - tail;
            if (drawY >= 0) {
                char tailChar = 33 + rand() % 94;
                //drawY and j was also incorrectly ordered here as well
                tg.putCharAt(drawY, j, tailChar, Color::Green);
            }
        }

        drops[j] += speed[j];
    }

    tg.draw();
    tg.sleepMs(50);
}
    
return 0;


}
