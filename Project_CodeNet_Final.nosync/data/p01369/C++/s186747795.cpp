#include <iostream>
using namespace std;

bool doUseLeft(char ch) {
    return (('a' <= ch && ch <= 'g') || ('q' <= ch && ch <= 't') || ('v' <= ch && ch <= 'x') || ch == 'z');
}

int main() {
    while (true) {
        char word[33];
        cin >> word;
        if (word[0] == '#') {
            break;
        }
        int count = 0;
        bool isLeft = doUseLeft(word[0]);
        for (int i = 1; word[i] != '\0'; i++) {
            if ((isLeft && doUseLeft(word[i]) == false) || (isLeft == false && doUseLeft(word[i]))) {
                isLeft = !isLeft;
                count++;
            }
        }
        cout << count << endl;
    }
}