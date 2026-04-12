#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

ll cnt[51];
map<PL, ll> memo;

ll calc(ll n, ll k){
    k = min(k, cnt[n]);
    if (memo.count(PL(n, k))) return memo[PL(n, k)];
    if (n == 0){
        return k > 0;
    }
    ll ret = 0;
    if (k >= 1){
        ret += calc(n - 1, k - 1);
    }
    if (k >= cnt[n - 1] + 2) ret++;
    if (k > cnt[n - 1] + 2){
        ret += calc(n - 1, k - cnt[n - 1] - 2);
    }
    return memo[PL(n, k)] = ret;
}

int main() {
    ll n, k;
    cin >> n >> k;
    cnt[0] = 1;
    REP(i,n) cnt[i+1] = 2 * cnt[i] + 3;

    cout << calc(n, k) << endl;

    return 0;
}
