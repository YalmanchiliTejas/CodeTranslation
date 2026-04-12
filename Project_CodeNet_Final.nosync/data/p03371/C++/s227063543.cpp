/**
 *      ABC 95 C
 *      author  : kyomukyomupurin
 *      created : 2018/08/26
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    if (X == Y){
        cout << min(A * X + B * Y, C * 2 * X) << endl;
    }
    else if (X > Y){
        cout << min(A * X + B * Y, min(2 * C * Y + (X - Y) * A, 2 * C * X)) << endl;
    }
    else {
        cout << min(A * X + B * Y, min(2 * C * X + (Y - X) * B, 2 * C * Y)) << endl;
    }

    return 0;
    
}