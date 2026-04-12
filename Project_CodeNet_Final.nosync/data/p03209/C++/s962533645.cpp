#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;
ll n,x;
ll all[55] = {};
ll Pa[55]={};

ll dfs(int l, ll k) {
    ll ret = 0;
    if (k >= all[l]) return Pa[l];
    --k;
    if (k>0) {
        ret += dfs(l-1, k);
        k -= all[l-1];
    }
    if (k>0) {
        ++ret;
        --k;
    }
    if (k>0) {
        ret+=dfs(l-1,k);
        k-=all[l-1];
    }

    return ret;
}

int main(int argc, char const *argv[]) {
    cin >> n >> x;
    all[0] = Pa[0] = 1;
    REP(i,51) {
        all[i+1] = all[i]*2+3;
        Pa[i+1] = Pa[i]*2+1;
    }
    
    cout << dfs(n,x) << endl;
    
    return 0;
}