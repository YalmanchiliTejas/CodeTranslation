#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	for(int b = 1; b <= n; b++){
		ans += (n/b) * max(0, b-k);
		ans += max(0, n%b - k + 1);
	}
	if(k == 0) ans -= n;
	cout << ans << endl;
    return 0;
}