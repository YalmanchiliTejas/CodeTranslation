#include <bits/stdc++.h>
#define FOR(i,a,b) for(ut i=(a);i<(int)(b);i++)
#define REP(i,b) FOR(i,0,b)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define cat //cout << __LINE__ << endl;
using namespace std;
typedef long long LL;
typedef long double ld;
typedef int ut;
typedef vector<ut> VI;
typedef pair<ut,ut> pr;
typedef pair<ut,pr> ppr;
typedef vector<pr> Vpr;
typedef vector<ppr> Vppr;
typedef priority_queue<pr,Vpr,greater<pr> > PQ;
const int SIZE=2*1e5;
const int INF=1LL<<30;
const LL p=7+1e9;
int fi=0,se=-1;
string T,P;
int last[30];
int main(){
	cin >> T >> P;
	REP(i,30) last[i]=-1;
	REP(i,T.size()){
		if(T[i]==P[fi]){
			fi++;
			last[T[i]-'a']=fi;
		}else if(last[T[i]-'a']!=-1){
			se=max(se,last[T[i]-'a']);
		}
		if((fi==se)){
			cout << "no" << endl;
			return 0;
		}
	}
	if(fi==P.size())
		cout << "yes" << endl;
	else 
		cout << "no" << endl;
	return 0;
}