#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>
#include <algorithm>
#include <math.h>

using namespace std;

int A, B, C, X, Y;

int main(){
    cin >> A >> B >> C >> X >> Y;

    int ans = 0;
    if( C * 2 < A + B ){
        int res = min(X, Y);
        ans = C * 2 * res;
        X -= res;
        Y -= res;
    }

    

    if( X != 0 ){
        if( C * 2 < A ) ans += C * 2 * X;
        else            ans += A * X;
    }
    if( Y != 0 ){
        if( C * 2 < B ) ans += C * 2 * Y;
        else            ans += B * Y;
    }

    cout << ans << endl;
}