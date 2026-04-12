#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll n;
    cin >> n;

    vector<ll> a(n);
    rep(i, n)cin >> a[i];

    vector<ll> ctop(1, -1);
    for(ll ai : a){
        if(ai <= ctop.front()){
            ctop.insert(ctop.begin(), ai);
        }
        else {
            ll pos = lower_bound(ALL(ctop), ai) - ctop.begin() - 1;

            ctop[pos] = ai;
        }
    }

    cout << ctop.size() << endl;   
}