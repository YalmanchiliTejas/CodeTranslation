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
typedef vector<pr> Vpr;
typedef pair<ut,ut> prs;
const int SIZE=2*1e5;
const LL p=7+1e9;
LL N;
VI edges[SIZE];
inline void IN(ut &x){cin >> x;}
inline void INA(ut n,ut x[]){REP(i,n) cin >> x[i];}
inline void INE(ut m,VI edges[]){
	ut a,b;
	REP(i,m){
		cin >> a >> b;
		edges[a].PB(b);
		edges[b].PB(a);
	}
}
inline void INEC(ut m,Vpr edges[]){
	ut a,b,c;
	REP(i,m){
		cin >> a >> b >> c;
		edges[a].PB(pr(c,b));
		edges[b].PB(pr(c,a));
	}
}
int reached[SIZE];
LL counted[SIZE];
bool solve(){
	cin >> N;
	INE(N-1,edges);
	queue<int> qu;
	FOR(i,1,N+1){
		if(edges[i].size()<=1){
			qu.push(i);
		}
	}
	bool last=false;
	while(!qu.empty()){
		int now=qu.front();
		qu.pop();
		if(counted[now]>=2){
			return true;
		}
		last=counted[now]==0;
		REP(i,edges[now].size()){
			int next=edges[now][i];
			reached[next]++;
			if(counted[now]==0) counted[next]++;
			if(reached[next]==edges[next].size()-1){
				qu.push(next);	
			}
		}
	}
	return last;
}
int main(){
	if(solve()) cout << "First" << endl;
	else cout << "Second" << endl;

	return 0;
}