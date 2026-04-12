#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pi=pair<int,int>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 
int a,b;
bool ok=false;

void f(pi p,int cnt,vector<vector<char>> &vec){
	if(p==pi(a-1,b-1)){
		if(cnt==0) ok=true;
	}
	int n,m; tie(n,m) = p;
	if(n+1<a){
		if(vec[n+1][m]=='#'){
			f(make_pair(n+1,m),cnt-1,vec);
		}
	}
	if(m+1<b){
		if(vec[n][m+1]=='#'){
			f(make_pair(n,m+1),cnt-1,vec);
		}
	}
}
	
	
signed main(){
	cin>>a>>b;
	vector<vector<char>> vec(a,vector<char>(b));
	int cnt=0;
	rep(i,0,a){
		rep(j,0,b){
			cin>>vec[i][j];
			if(vec[i][j]=='#') ++cnt;
		}
	}
	--cnt;
	//cout<<"cnt:"<<cnt;
	f(pi(0,0),cnt,vec);
	if(ok) cout<<"Possible";
	else cout<<"Impossible";
	
	return 0;
}