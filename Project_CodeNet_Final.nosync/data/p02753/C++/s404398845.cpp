#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define RREP(i,s,n) for(lli i=s;i>=n;i--)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)

signed main(){

	set<char> d;
	REP(i,0,3){
		char tmp;
		cin>>tmp;
		d.insert(tmp);
	}

	if(d.size()!=1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;


	return 0;
}