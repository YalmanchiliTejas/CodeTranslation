#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)

using namespace std;
ll K,A,B;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>K>>A>>B;
	ll ans;
	if(A>=K){
		ans=1;
	}else if(A-B<=0){
		ans=-1;
	}else{
		ans=(K-A+A-B-1)/(A-B)*2+1;
	}
	cout<<ans<<endl;
}