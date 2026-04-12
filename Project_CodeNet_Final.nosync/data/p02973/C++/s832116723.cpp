#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

signed main(){

	lli n;
	cin>>n;
	vector<lli> a(n);
	REP(i,0,n)cin>>a[i];

	vector<lli> now;
	for(auto x : a){
		auto ub = upper_bound(now.begin(),now.end(),x,greater<lli>());
		if(ub != now.end()){
			*ub = x;
		}
		else{
			now.push_back(x);
		}
	}
	cout<<now.size()<<endl;

	return 0;
}