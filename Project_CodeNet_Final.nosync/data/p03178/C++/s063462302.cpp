#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int d;
    cin >> d;
    int full = 0;
    vector<ll> last(d);
    int n = s.size();
    rep(i,0,n) {
        vector<ll> next(d);
        int digit = s[i]-'0';
        rep(x,0,digit) ++next[(full+x)%d];
        full = (full+digit)%MOD;
        rep(j,0,d) {
            rep(k,0,10) {
                next[(j+k)%d] = (next[(j+k)%d]+last[j])%MOD;
            }
        }
        swap(next,last);
    }
    ll ans = last[0];
    if(full%d==0) ++ans;
    --ans;
    ans = (ans+MOD)%MOD;
    cout << ans << "\n";
} 
