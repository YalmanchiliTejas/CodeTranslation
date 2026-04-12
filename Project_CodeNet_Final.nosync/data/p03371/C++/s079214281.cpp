#include <bits/stdc++.h>
#define rep(i,n) for (ll i=1; i<=(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int A,B,C,X,Y; cin >> A >> B >> C >> X >> Y;
    int ans=1e9;
    for (int i=0; i<=1e5; i++){
        ans=min(ans,C*i*2+A*max(X-i,0)+B*max(Y-i,0));
        if(X-i==0 && Y-i==0) break;
    }
    cout << ans;
}