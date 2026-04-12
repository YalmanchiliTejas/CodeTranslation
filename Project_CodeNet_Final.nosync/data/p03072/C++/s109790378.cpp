#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define MOD 10000000070
#define DEBUG 0
#define REP(i,n) for(int i=0;i<n;i++)


 int main(){

 	lli n;
 	cin>>n;
 	vector<lli> h(n);
 	REP(i,n)cin>>h[i];

 	lli tmp=0;
 	lli ans=0;
 	REP(i,n){
 		if(tmp <= h[i]){
 			ans++;
 			tmp = h[i];
 		}
 	}
 	cout<<ans<<endl;
 
	return 0;
 
}