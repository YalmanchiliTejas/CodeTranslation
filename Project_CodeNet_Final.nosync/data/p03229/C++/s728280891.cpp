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
	sort(a.begin(),a.end());
	vector<ll> b(n),c(n);
	if(n % 2 == 0){
		int k = 2;
		b.at(0) = -1;
		for(int i = 1; i < n - 1; i++){
			b.at(i) = k;
			k *= -1;
		}
		b.at(n - 1) = 1;
		k = -2;
		c.at(0) = 1;
		for(int i = 1; i < n - 1; i++){
			c.at(i) = k;
			k *= -1;
		}
		c.at(n - 1) = -1;
	}
	else{
		int k = 2;
		b.at(0) = -1;
		for(int i = 1; i < n - 1; i++){
			b.at(i) = k;
			k *= -1;
		}
		b.at(n - 1) = -1;
		k = -2;
		c.at(0) = 1;
		for(int i = 1; i < n - 1; i++){
			c.at(i) = k;
			k *= -1;
		}
		c.at(n - 1) = 1;
	}
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	ll ans1 = 0, ans2 = 0;
	rep(i,n){
		ans1 += a.at(i) * b.at(i);
		ans2 += a.at(i) * c.at(i);
	}
	cout << max(ans1, ans2) << endl;
}
