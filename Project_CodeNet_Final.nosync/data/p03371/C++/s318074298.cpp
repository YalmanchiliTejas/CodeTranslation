#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

#define P pair<lli,lli>

signed main(){

	lli a,b,c,x,y;

	cin>>a>>b>>c>>x>>y;

	lli ans = INF;

	for(lli ab=0;ab<=2*max(x,y);ab++){
		lli abCost = c*ab;
		lli leftA = x-ab/2;
		lli leftB = y-ab/2;

		lli aCost = max(leftA*a,0LL);
		lli bCost = max(leftB*b,0LL);
		//if(DEBUG)cout<<"ab="<<ab<<"A="<<leftA<<"B="<<leftB<<"aCost="<<aCost<<" bCost="<<bCost<<endl;

		ans = min(abCost+aCost+bCost,ans);
	}
	cout<<ans<<endl;

	return 0;
}