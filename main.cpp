#include <iostream>
#include "TextGraphics.h"
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


int main () {

    TextGraphics tg;
    if (tg.width() == 0 || tg.height() == 0) {
        cout << "Terminal size error.\n";
        return 1;
    }
    

    srand(time(nullptr));

    vector<int> drops(tg.width());
    vector<int> speed(tg.width());

    for (int i = 0; i < tg.width(); i++) {

        drops[i] = rand() % tg.height();
        speed[i] = 1 + rand() % 3;
    }
    while (true) {
    tg.clearScreen();
    for (int j = 0; j < 10; j++) {

        if (drops[j] >= tg.height()) {
            drops[j] = 0;
        }

        int y = drops[j];
        if (y < 0) {
            y = 0;
        }
        if (y >= tg.height()) {
            y = tg.height() - 1;
        }

        char headChar = 33 + rand() % 94;
        tg.putCharAt(j, y, headChar, Color::White);

        for (int tail = 1; tail <= 5; tail++) {
            int drawY = y - tail;
            if (drawY >= 0) {
                char tailChar = 33 + rand() % 94;
                tg.putCharAt(j, drawY, tailChar, Color::Green);
            }
        }

        drops[j] += speed[j];
    }

    tg.draw();
    tg.sleepMs(50);
}
    
return 0;


}
