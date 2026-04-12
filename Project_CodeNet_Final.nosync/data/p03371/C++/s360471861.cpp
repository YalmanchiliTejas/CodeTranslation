#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i > 0; i++)
const int MOD =1e9+7;
using ll = long long;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if(X>Y){
        cout << min({A*X+B*Y, X*2*C, Y*2*C + (X-Y)*A}) << endl;
    }else {
        cout << min({A*X+B*Y, Y*2*C, X*2*C + (Y-X)*B}) << endl;
    }
}
