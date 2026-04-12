#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	int n; cin>>n;
	map<char,int> mp;
	string f; cin>>f;
	rep(i,0,f.size()){
		mp[f[i]]++;
	}
	rep(i,0,n-1){
		string s; cin>>s;
		int m=s.size();
		map<char,int> cnt;
		rep(j,0,m){
			cnt[s[j]]++;
			//cout<<cnt[s[i]]<<" ";
		}
		//cout<<endl;
		for(auto &c:mp){
			c.second=min(c.second,cnt[c.first]);
		}
	}
	string ans;
	for(auto c:mp){
		//cout<<c.first<<" "<<c.second<<endl;
		rep(i,0,c.second){
			ans.push_back(c.first);
		}
	}
	sort(all(ans));
	cout<<ans;
	
	return 0;
}