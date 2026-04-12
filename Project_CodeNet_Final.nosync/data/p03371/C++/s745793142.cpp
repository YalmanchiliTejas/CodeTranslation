#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int A,B,C,X,Y;cin>>A>>B>>C>>X>>Y;
    int sonomama = A * X + B * Y;
    int oome, sukuname;
    if (X >= Y) {
        oome = C * 2 * X;
        sukuname = C * 2 * Y + A * (X - Y);
    } else {
        oome = C * 2 * Y;
        sukuname = C * 2 * X + B * (Y - X);
    }
    cout << min(sonomama, min(oome,sukuname)) << endl;
    return 0;
}