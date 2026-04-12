#include <bits/stdc++.h>

#include <math.h>
#include <stdlib.h>


#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true; } return false; }

//INT_MAX	2,147,483,647 = 2*1.0e9

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    if(X > Y){
        swap(A,B);
        swap(X,Y);
    }

    int min2 = min(A+B, 2 *C);
    int ans = 0;
    ans += X * min2;

    int rest = Y - X;
    int min3 = min(B, 2 * C);
    ans += min3 * rest;

    cout << ans << endl;

    return 0;
}
