#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 3030;
const ll inf = 1e18;

int n;
ll a[maxn];
ll dp[maxn][maxn];



ll solve(int l, int r) {
    assert(l<=r);
    if (l==r) return a[r];
    if (~dp[l][r]) return dp[l][r];

    return dp[l][r]=max(a[l]-solve(l+1,r), a[r]-solve(l,r-1));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n;
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }

    memset(dp,-1,sizeof(dp));

    cout<<solve(0,n-1)<<endl;
  

    return 0;
}
