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

	lli n,k;
	cin>>n>>k;

	if(k==0){
		cout<<n*n<<endl;
		return 0;
	}

	lli cnt=0;
	REP(b,k,n+1){
		lli tmp=0;
		if(n%b<k){
			tmp=(b-k)*(n/b);
		}
		else{
			tmp=(b-k)*(n/b)+(n%b-k+1);
		}
		cnt+=tmp;
	}
	cout<<cnt<<endl;


	return 0;
}