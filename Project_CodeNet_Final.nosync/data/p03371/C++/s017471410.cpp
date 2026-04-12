#include <bits/stdc++.h>


using namespace std;


int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    int p1, p2, p3;
    
    p1 = max(X, Y) * 2 * C;
    
    p2 = X * A + Y * B;
    
    if(X >= Y){
        p3 = Y * 2 * C + (X - Y) * A;
    } else {
        p3 = X * 2 * C + (Y - X) * B;
    }
    
    cout << min(p1, min(p2, p3)) << endl;
}