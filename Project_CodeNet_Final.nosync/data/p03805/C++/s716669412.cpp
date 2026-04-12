#include <bits/stdc++.h>
#define FOR(i,a,b) for(ut i=(a);i<(ut)(b);i++)
#define REP(i,b) FOR(i,0,b)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define cat //cout << __LINE__ << endl;
using namespace std;
typedef long long LL;
typedef double ld;
typedef LL ut;
typedef vector<ut> VI;
typedef pair<ut,ut> pr;
const int SIZE=5+3*1e3;
const int INF=10+1e9;
bool exist[10][10];

int N,M;
int solve(int now,bool ended[10],int times){
	if(times==N) return 1;
	int ans=0;
	FOR(i,1,N+1)
		if(exist[now][i] && !ended[i]) {
			ended[i]=true;
			ans+=solve(i,ended,times+1);
			ended[i]=false;
		}
	return ans;
}
int main(){
	int a,b;
	cin >> N >> M;
	REP(i,M){
		cin >> a>> b;
		exist[a][b]=exist[b][a]=true;
	}
	bool ended[10]={0,1};
	cout << solve(1,ended,1) << endl;

	return 0;
}