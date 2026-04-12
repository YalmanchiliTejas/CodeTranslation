#include <bits/stdc++.h>

using namespace std;

#define make_unique(a) (a.erase(unique(a.begin(),a.end()),a.end()))
#define allof(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define exists(s, e) (s.find(e)!=s.end())
#define INF 0x3f3f3f3f
#define endl '\n'
#define mp make_pair
#define readln(x) (getline(cin, x))
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

typedef pair<int, int> pii;
typedef long long ll;

ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

void solve() {
    int x; cin >> x;
    if(x==5 or x==7 or x==3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}

