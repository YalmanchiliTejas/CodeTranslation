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
	int H,W;
	cin>>H>>W;
	string s[H];
	REP(i,H)cin>>s[i];
	int tmi = INF,tma = 0;
	int ymi = INF,yma = 0;
	REP(i,H)REP(j,W){
		if(s[i][j]=='B'){
			CHMIN(tmi,i+j);
			CHMAX(tma,i+j);
			CHMAX(yma,i+W-j-1);
			CHMIN(ymi,i+W-j-1);
		}
	}
	cout<<max(tma-tmi,yma-ymi)<<endl;
}
