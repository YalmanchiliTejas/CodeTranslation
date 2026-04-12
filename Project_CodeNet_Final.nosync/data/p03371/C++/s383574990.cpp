#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    int X,Y;
    cin >> X >> Y;
    int ans = 0;
    if ((A + B) <= C * 2){
        ans += (A + B) * min(X,Y);
    }
    else{
        ans += C * 2 * min(X,Y);
    }
    int Z = min(X,Y);
    X -= Z;
    Y -= Z;
    if (X > 0){
        if (A > C * 2){
            ans += C * 2 * X;
        }
        else{
            ans += A * X;
        }
    }
    else if (Y > 0){
        if (B > C * 2){
            ans += C * 2 * Y;
        }
        else{
            ans += B * Y;
        }
    }
    cout << ans << endl;
}
