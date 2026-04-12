#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1e9+7LL;
 
int main() {
    ll N, X, M; cin >> N >> X >> M;
    ll f = X;
    ll ans = 0;
    map<ll, ll> m;
    vector<ll> sum(2*M+1);
    sum.at(0) = X;
    m[X] = 0;
    bool flag = false;
 
    rep(i, N){
        if(i==0) continue;
        f = f*f % M;
        sum.at(i) = sum.at(i-1) + f;
 
        if(m.count(f)){
            flag = true;
            ll x = i - m[f];
            ll tmp = sum.at(i) - sum.at(m[f]);

            ll a = 0;
            if(m[f]!=0) a = sum.at(m[f]-1);
            ll b = tmp * ((N-m[f])/x);
            ll c = 0;
            if((N-m[f])%x!=0){
                c = sum.at((N-m[f])%x + m[f]-1);
                if(m[f]!=0) c -= sum.at(m[f]-1);
            }
            ans = a + b + c;
            break;
        }
        else m[f] = i;
    }
    if(!flag) ans = sum.at(N-1);
    cout << ans << endl;
}