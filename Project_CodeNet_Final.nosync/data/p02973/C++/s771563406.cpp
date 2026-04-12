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
vector<int> dx={0,-1,0,1},dy={1,0,-1,0};
bool inside(int y,int x,int h,int w){
	if(y<h && y>=0 && x<w && x>=0) return true;
	return false;
}





int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a.at(i);
	int ans=0;
	map<int,int> m;
	m[a.at(0)]++;
	ans++;
	for(int i=1;i<n;i++){
		auto next = m.lower_bound(a.at(i));
		if(next==m.begin()){
			ans++;
			m[a.at(i)]++;
		}
		else{
			next--;
			next->second--;
			if(next->second==0) m.erase(next->first);
			m[a.at(i)]++;
		}
	}
	cout << ans << endl;
}
