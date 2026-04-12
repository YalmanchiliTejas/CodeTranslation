#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<utility>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<math.h>
#include <map>
using namespace std;
typedef long long int ll;
#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define all(u) u.begin(),u.end()
#define pl pair<ll,ll>
#define fi first
#define se second
#define inf 1000000007

ll A,B,C,X,Y;


int main() {
    cin >> A >> B >> C >> X >> Y;
    ll ans = 0;
    if (C*2 <= A+B){
        ll t = min(X,Y);
        X -= t;
        Y -= t;
        ans += C*2*t;
        if (X > 0){
            if (C*2 <= A){
                ans += C*2*X;
            }
            else{
                ans += A*X;
            }
        }
        else{
            if (C*2 <= B){
                ans += C*2*Y;
            }
            else{
                ans += B*Y;
            }
        }
    }
    else{
        ll t = min(X,Y);
        X -= t;
        Y -= t;
        ans += (A+B)*t;
        if(X > 0) ans += A*X;
        else ans += B*Y;
    }
    cout << ans << endl;
    
    return 0;
}
