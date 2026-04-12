#include <iostream>

using namespace std;

int main() {
    int r,g,b;
    cin >> r;
    cin >> g;
    cin >> b;
    if ((r>0 && r<10) && (g>0 && g<10) && (b>0 && b<10)) {
        int answer = 100*r + 10*g + b;
        if (answer % 4 ==0) {
            cout << "YES";
        }
        else
            cout << "NO";
    }
}