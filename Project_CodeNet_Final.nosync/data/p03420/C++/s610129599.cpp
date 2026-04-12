#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
ll N,K;
int main(){
	cin>>N>>K;
	ll ans=0;
	FOR(b,K+1,N+1){
		ans+=(b-K)*(N/b)+max(N%b-K+1,0ll);
		if (K==0){
			ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}