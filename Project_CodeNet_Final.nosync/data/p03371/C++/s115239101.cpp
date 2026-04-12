#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)

signed main(){

	lli a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;

	lli ans = INF;
	//abピザを何枚買うか決める。
	REP(i,0,200100){
		lli X = max(0LL,x-i/2);
		lli Y = max(0LL,y-i/2);

		lli cost = X*a+Y*b+i*c;
		ans = min(ans,cost);
	}
	cout<<ans<<endl;

	return 0;
}