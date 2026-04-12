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
	int n,m; cin>>n>>m;
	vector<vector<char>> vec(n,vector<char>(m));
	rep(i,0,n){
		rep(j,0,m){
			cin>>vec[i][j];
		}
	}
	//vector<bool> ok(n,vector<bool>(m));
	set<int> s;
	set<int> s2;
	rep(i,0,n){
		bool a=true;
		rep(j,0,m){
			if(vec[i][j]=='#') a=false;
		}
		if(a) s.insert(i);
	}
	rep(i,0,m){
		bool a=true;
		rep(j,0,n){
			if(vec[j][i]=='#') a=false;
		}
		if(a) s2.insert(i);
	}
	vector<vector<char>> ans(n,vector<char>(0));
	rep(i,0,n){
		rep(j,0,m){
			if(s.count(i)) continue;
			if(s2.count(j)) continue;
			ans[i].push_back(vec[i][j]);
		}
	}
	rep(i,0,n){
		if(ans[i].size()==0) continue;
		rep(j,0,ans[i].size()){
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}