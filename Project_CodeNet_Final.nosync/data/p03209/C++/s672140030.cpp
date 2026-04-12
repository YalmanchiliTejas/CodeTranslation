#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

ll sz[51];
ll p[51];

ll rec(int n, ll x){
    if(n == 0) return max(0LL, x);
    if(sz[n] == x) return p[n];
    ll res = 0;
    res += rec(n - 1, min(sz[n - 1], x - 1));
    if(sz[n - 1] + 1 < x) res += 1;
    if(sz[n - 1] + 2 < x) res += rec(n - 1, min(sz[n - 1], x - (sz[n - 1] + 2)));
    return res;
}

signed main(){
    int n;
    ll x;
    cin >> n >> x;
    sz[0] = 1;
    for(int i = 1; i <= 50; i++){
        sz[i] = sz[i - 1] * 2 + 3;
    }
    p[0] = 1;
    for(int i = 1; i <= 50; i++){
        p[i] = p[i - 1] * 2 + 1;
    }
    cout << rec(n, x) << endl;
    return 0;
}
