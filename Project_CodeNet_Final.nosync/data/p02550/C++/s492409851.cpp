// $%U%$
// $%D%$/$%M%$/$%Y%$
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef long long int  ll;
const int INF = 1e9 + 7;
const ll mod = 998244353;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int nxt() {int x;scanf("%d", &x);return x;}

int main(){
    ll n, x, m;
    cin >> n >> x >> m;
    VI a;
    set<int> s;
    a.push_back(x);
    while(a.size() < n){
        ll last = a[a.size()-1];
        ll next = (last*last) % m;
        if(s.count(next)){
            vector<ll> prefix(a.size(), 0);
            int marker = -1;
            REP(i, a.size()){
                prefix[i] = a[i];
                if(i) prefix[i] += prefix[i-1];
                if(a[i] == next) marker = i;
            }
            assert(marker != -1);
            ll no = 0;
            if(marker) no = prefix[marker - 1];
            ll repeat = prefix[prefix.size()-1] - prefix[marker-1];
            ll cycle = prefix.size() - marker;
            n -= marker;
            repeat *= (n/cycle);
            /* printf("%lld\n", no); */
            /* printf("%lld\n", repeat); */
            for(int i = 0; i < n%cycle; i++){
                repeat += a[marker+i];
            }
            printf("%lld\n", repeat + no);
            return 0;
        }
        else{
            s.insert(next);
            a.push_back(next);
        }
    }
    ll ans = 0;
    REP(i, n) ans += a[i];
    printf("%lld\n", ans);
}


