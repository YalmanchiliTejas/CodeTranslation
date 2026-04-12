#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define REP(i, n) for(i=0; i<n; i++)
#define REPR(i, n) for(i=n; i>=0; i--)
#define FOR(i, m, n) for(i=m; i<n; i++)
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define INF 10000000000
#define MOD 1000000007LL
#define MAX 100005
#define NIL -1
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<double, double> doup;

ll zeroer(ll x) {
    if(x<=0) return 0;
    else return x;
}

int main(void) {
    ll n, k;
    cin >> n >> k;
    ll i, j;
    ll ans=0;
    
    for(j=k+1; j<=n; j++) {
        if(k!=0)
            ans+=n/j*(j-k)+zeroer(n%j-k+1);
        else
            ans+=n;
    }
    
    
    cout << ans << endl;
}
