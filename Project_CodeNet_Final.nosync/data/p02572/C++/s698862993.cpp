#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll INF = 1e9 + 7;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	ll ans = 0;
	ll wa = 0;
	rep(i,n){
		wa += a[i]%INF;
		ans += wa%INF*a[i+1]%INF;
	}
	cout << ans%INF << endl;
}