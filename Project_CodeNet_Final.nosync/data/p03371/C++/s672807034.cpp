#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
typedef long long ll;

int main() {
    int A,B,C,X,Y; 
    cin >> A >> B >> C >> X >> Y;
    int m,l,b;
    if(X > Y){
        m = Y;
        l = X;
        b = A;
    }else{
        m = X;
        l = Y;
        b = B;
    }

    ll ans = 0;

    if(A*m + B*m >= 2*C*m){
        ans += 2*C*m;
    }else{
        ans += A*m + B*m;
    }
    int d = l - m;;
    if(b*d > 2*d*C){
        ans += 2*d*C;
    }else{
        ans += b*d;
    }
    cout << ans << endl;
}