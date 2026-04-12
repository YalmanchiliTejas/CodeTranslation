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
typedef complex<int> cli;
typedef vector<ut> VI;
typedef pair<ut,ut> pr;
typedef pair<ut,pr> ppr;
typedef vector<pr> Vpr;
typedef vector<ppr> Vppr;
typedef priority_queue<ut,VI> PQ;
const int SIZE=1000005;
const LL INF=1<<30;
const LL p=7+1e9;
const LL NN=50;
LL N,alls;
LL A[NN];
int main(){
	LL K=0;
	cin >> N;
	PQ qu;
	REP(i,N){ 
		cin >> A[i];
		alls+=A[i]/(N+1);
		A[i]%=N+1;
		qu.push(A[i]);		
	}
	K+=alls;
	K+=max<LL>(0,alls-(N-1))*N;
	alls=min(alls,N-1);
	while(qu.top()+alls>=N){
		qu.push(qu.top()-(N+1));
		qu.pop();
		alls++;
		K++;
	}
	cout << K << endl;
	return 0;
}