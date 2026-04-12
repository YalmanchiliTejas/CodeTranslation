#include<iostream>
using namespace std;

int A, B, C, X, Y;

int main() {
    cin >> A >> B >> C >> X >> Y;
    int ans = 0;
    int a;
    if( A + B < 2 * C) a = A + B; 
    else a = 2 * C;

    ans = X > Y ? a * Y + (X - Y) * A : a * X + (Y - X) * B;
    ans = X > Y ? min(ans, a * X) : min(ans, a * Y);
    
    cout << ans << endl;

    return 0;
}