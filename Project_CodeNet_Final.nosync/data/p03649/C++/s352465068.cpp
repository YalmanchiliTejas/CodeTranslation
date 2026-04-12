#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){
	if(y<h && y>=0 && x<w && x>=0) return true;
	return false;
}





int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a.at(i);
	ll ans = 0, cnt = 0;
	vector<ll> cnt1(n);
	while(true){
		bool flg = false;
		rep(i,n){
			a.at(i) += cnt - cnt1.at(i);
			ll k = a.at(i) / n;
			ans += k;
			cnt += k;
			cnt1.at(i) = cnt;
			a.at(i) %= n;
			if(k > 0) flg = true;
		}
		if(!flg) break;
	}
	cout << ans << endl;
}