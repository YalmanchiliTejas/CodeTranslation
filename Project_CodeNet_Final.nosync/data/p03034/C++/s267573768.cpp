//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
using namespace std;
const ll MAX_N=1e5;
ll N,s[MAX_N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	REP(i,N){
		cin>>s[i];
	}
	ll ans=0;
	FOR(x,1,N){
		ll sm=0;
		FOR(i,1,(N-1)/x+1){
			if(x>=N-1-i*x||((N-1)%x==0&&i*x>=N-1-i*x)){
				break;
			}
			sm+=s[i*x]+s[N-1-i*x];
			ans=max(ans,sm);
		}
	}
	cout<<ans<<endl;
}