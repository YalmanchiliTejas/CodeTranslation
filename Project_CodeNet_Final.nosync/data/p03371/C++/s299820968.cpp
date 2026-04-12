#include <iostream>
#include <cmath>
#include <set>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    if ((A + B) / 2 < C) {
        cout << X * A + Y * B << endl;
    } else {
        int countPrice = std::min(X, Y) * 2 * C;

        int pizzaP = 0;
        if (X > Y) {
            pizzaP = A;
        } else {
            pizzaP = B;
        }
        if (pizzaP > C * 2) {
            countPrice += C*2*std::abs(X-Y);
        } else {
            countPrice += pizzaP*std::abs(X-Y);
        }

        cout << countPrice << endl;
    }
}