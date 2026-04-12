#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;


int main() {
    int n;
    ll x;
    cin >> n >> x;
    ll b = 1, t = 8 * pow(2,n-1) - 3;
   // cout<<t<<endl;
    int lev = n;
    ll ans = 0;
    while (lev >= 1) {
        if(lev==1){
             ll tmp = x - b;
             ans+=min(tmp,(ll)3);
             break;
        }
        if(b==x)break;
        if(t==x){
            ans+=(4*(pow(2,lev-1))-1);
            break;
        }
        lev--;
        ll now = (b + t) / 2;
        if (x >= now) {
            ans += (4 * pow(2,lev-1) - 1);
            ans++;
            b = now+1;
            t--;
        }
        else {
            t = now-1;
            b++;
        }
        if (x == now)break;
    }
    
    cout << ans << endl;
    return 0;
}