#include <iostream>
using namespace std;
int main() {
    int a,b,c;
    b = 0;
    c = 0;
    cin >> a;
    if (a < 15){
       cout << a * 800 << endl;
    } else if (a >= 15){
        for (int i = 15; i <= a; ++i) {
            if (i % 15 == 0) {
                b++;
            }
        }
        c = b * 200;
        cout << (a*800) - (c) << endl;
    }
    return 0;
}