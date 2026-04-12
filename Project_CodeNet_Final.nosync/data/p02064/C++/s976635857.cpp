#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define RFOR(i, s, n) for (int i = (n) - 1; i >= (s); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
#define IN(a, x, b) (a <= x && x < b)
const long long MOD = 1e9+7, INF = 1e18;
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a=b;return true;}return false;}



signed main(){
	int N,S,T;
	cin>>N>>S>>T;
	cout<<'?'<<" "<<S<<" "<<T<<endl;
	cout.flush();
	int dist;
	cin>>dist;
	vector<pair<int,int>>v;
	FOR(i,1,N+1){
		if(i==S||i==T)continue;
		int s,t;
		cout<<'?'<<" "<<S<<" "<<i<<endl;
		cout.flush();
		cin>>s;
		cout<<'?'<<" "<<i<<" "<<T<<endl;
		cout.flush();
		cin>>t;
		if(s+t==dist)v.push_back({s,i});
	}
	sort(ALL(v));
	cout<<'!'<<" "<<S;
	REP(i,v.size()){
		cout<<" "<<v[i].second;
	}
	cout<<" "<<T<<endl;
}
