#include <bits/stdc++.h>
#define FOR(i,a,b) for(ut i=(a);i<(ut)(b);i++)
#define REP(i,b) FOR(i,0,b)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define cat //cout << __LINE__ << endl;
using namespace std;
typedef long long LL;
typedef double ld;
typedef int ut;
typedef complex<int> cli;
typedef vector<ut> VI;
typedef pair<ut,ut> pr;
typedef pair<ut,pr> ppr;
typedef vector<pr> Vpr;
typedef vector<ppr> Vppr;
typedef priority_queue<pr,Vpr> PQ;
const int SIZE=5+2*1e5;
const LL INF=1<<30;
int maps[10][10];
bool solve(){

	int H,W;
	int co=0;
	cin >> H >> W;
	REP(i,H){
		string s;
		cin >> s;
		REP(j,W){
			maps[i][j]=s[j]=='#';
			co+=maps[i][j];
		}

	}
	maps[0][0]=2;
	REP(i,H) REP(j,W){
		if(maps[i][j]==2){
			if(maps[i+1][j]==1) maps[i+1][j]=2;
			else if(maps[i][j+1]==1) maps[i][j+1]=2;
			co--;
		}
		else if(maps[i][j]==1){
			return false;
		}
	}
	return co==0;
}
int main(){
	cout << (solve()?"Possible":"Impossible") << endl;
	
	return 0;
}