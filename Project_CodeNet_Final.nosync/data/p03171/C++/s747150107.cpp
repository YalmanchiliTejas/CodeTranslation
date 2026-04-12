#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

typedef long long ll;

const ll mod=1e9+7;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define rc(x)  return cout<<x<<"\n",0
#define sz(s)  (int) s.size()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;

const int nax=3005;
ll dp[nax][nax];

ll t,n;

int main() {
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	int a[n+5];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int l=n-1; l>=0; l--) {
		for (int r=l; r<=n-1; r++) {
			if (l==r) {
				dp[l][r]=a[l];
			}
			else {
				dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
			}
		}
	}
	cout << dp[0][n-1];	
}
