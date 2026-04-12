#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int A,B,C,X,Y;cin>>A>>B>>C>>X>>Y;

    int total = A * X + B * Y;
    int infimum = (X >= Y) ? C * 2 * Y + A * (X - Y) : C * 2 * X + B * (Y - X);
    int muximum = 2 * C * max(X, Y);
    cout << min(min(total, infimum), muximum) << endl;
    return 0;
}