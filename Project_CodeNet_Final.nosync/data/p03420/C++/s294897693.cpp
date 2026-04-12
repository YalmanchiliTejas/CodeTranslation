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
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

int main() {
    ll n, k;
    cin >> n >> k;

    if (k == 0){
        cout << n * n << endl;
        return 0;
    }

    ll ans = (n + 1) * (n + 1);

    FOR(b,0,n){
        if (b <= k){
            ans -= n + 1;
            continue;
        }
        ll a = n + 1, tmp = 0;
        tmp += a / b * k;
        tmp += min(k, a % b);
        ans -= tmp;
    }
    cout << ans << endl;

    return 0;
}
