#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int a,b,c,x,y,ans=1e9;
    cin >> a >> b >> c >> x >> y;
    rep(i,max(2*x,2*y)+1){
        int d=0,e=0;
        if(x-i/2>0) d = a*(x-i/2);
        if(y-i/2>0) e = b*(y-i/2);
        ans = min(ans,c*i+d+e);
    }
    cout << ans << endl;
}
