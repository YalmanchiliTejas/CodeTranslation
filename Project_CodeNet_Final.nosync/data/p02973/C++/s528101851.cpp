#include <bits/stdc++.h>

using namespace std;
 
#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

typedef int64_t ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = 1e9+7; typedef vector<ll> VL;
void dbg(){ cerr << "\n"; }  template <typename T,typename ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
const int INF = MD;

int main(){
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	VI a(n);
	rep(i, n) cin >>a[i];
	auto b= a;
	reverse(all(b));
	vector<int> hk(n, INF);
	for(auto x: b) *upper_bound(all(hk), x) = x;
	int ans = lower_bound(all(hk), INF) - hk.begin();
	
	cout <<ans <<"\n";
	return 0;
}
