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

signed main(){

	lli n,k;
	cin>>n>>k;

	lli sum=0;

	if(k==0){
		cout<<n*n<<endl;
		return 0;
	}

	REP(i,1,n+1){
		if(i<=k)continue;
		lli tmp = (n+1)/i * (i-k) + max(0LL,(n+1)%i-k);
		if(DEBUG)cout<<"i="<<i<<" tmp="<<tmp<<endl;
		sum += tmp;
	}

	cout<<sum<<endl;

	return 0;
}