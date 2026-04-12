#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

ll a[55];
ll p[55];


ll f(int n, ll x){
    if (n == 0){
        if (x <= 0) return 0;
        else return 1;
    }
    else if (x <= a[n - 1] + 1) return f(n - 1, x - 1);
    else return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
}

int main(){
    int n;
    ll x;
    cin >> n >> x;
    a[0] = 1;
    p[0] = 1;
    a[1] = 5;
    p[1] = 3;

    for(int i = 1; i <= n; i++){
        a[i+1] = 2 * a[i] + 3;
        p[i+1] = 2 * p[i] + 1;
    }

    cout << f(n, x) << endl;
    return 0;
}