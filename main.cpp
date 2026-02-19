#include <iostream>
#include "TextGraphics.h"
#include <cstdlib>
#include <ctime>

using namespace std;


int main () {

    TextGraphics tg;

    srand(time());

    vector<int> drops(tg.width());
    vector<int> speed(tg.width());

    for (int i = 0; i < tg.width(); i++) {

        drops[i] = rand() % tg.height();
        speed[i] = 1 + rand() % 3;
    }
while (true) {
    tg.clearScreen();
    for (int j = 0; j < tg.width(); j++) {

        int y = drops[x];

        char headChar = 33 + rand() % 94;
        tg.putCharAt(j, y, headchar, Color::White);
        for (int tail = 1; tail <= 5; tail++) {
            int drawY = y - tail;
            if (drawY >= 0) {
                char tailChar - 33 + rand() % 94;
                tg.putCharAt(j, drawY, tailChar, Color::Green);
            }
        }
        drops[j] += speed[j];
        if (drops[j] >= tg.height()) {
            drops [j] = 0;
        }
    }

    tg.draw();
    tg.sleepMs(50);
}
    
return 0;

}
