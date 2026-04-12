#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>
 
using namespace std;
// https://qiita.com/Clpsplug/items/81fe12400d4093a8fb5a
 
int main() {
    long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int payment = 0;

    while (X >= 0 || Y >= 0)
    {
        if (X > 0 && Y > 0) {
            if (2*C < A+B) {
                payment += 2*C;
                X--;
                Y--;
            } else {
                payment += A+B;
                X--;
                Y--;
            }
        } else if (X == 0 && Y > 0) {
            if (2*C < B) {
                payment = payment + 2*C*Y;
                cout << payment << endl;
                return 0;
            } else {
                payment = payment + B*Y;
                cout << payment << endl;
                return 0;
            }
        } else if (X > 0 && Y == 0) {
            if (2*C < A) {
                payment = payment + 2*C*X;
                cout << payment << endl;
                return 0;
            } else {
                payment = payment + A*X;
                cout << payment << endl;
                return 0;
            }
        } else {
            cout << payment << endl;
            return 0;
        }
    }
    
}