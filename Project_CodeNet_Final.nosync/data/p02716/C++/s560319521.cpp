#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 3e5;
const ll inf = 1e18;


int n;
ll a[maxn];
ll dp[maxn][4];


void relax(ll& x, ll y) {
    x = max(x, y);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n;
    assert(n>=2);
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }

    for (int i=0; i<=n+1; i++) {
	for (int j=0; j<4; j++) {
	    dp[i][j] = -inf;
	}
    }

    dp[0][0] = 0;

    int parity = 1+(n%2);

    for (int i=0; i<n; i++) {
	for (int j=0; j<=parity; j++) {
	    relax(dp[i+1][j+1], dp[i][j]);
	    
	    ll cur = ((i+j)%2==0) ? a[i] : 0;
	    relax(dp[i+1][j], dp[i][j] + cur);
	}
    }

    ll ans = dp[n][parity];
    cout<<ans<<endl;
    return 0;
}
