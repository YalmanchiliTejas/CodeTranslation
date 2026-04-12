#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<tuple>
#include<bitset>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
int main(){
	ll N,a[50];
	scan(N);
	rep(i,N) scan(a[i]);
	sort(a,a+N);
	ll ans=0;
	while(a[N-1]>N-1){
		ll downtimeall=0;
		int overst=upper_bound(a,a+N,N-1)-a;
		for(int i=overst;i<=N-1;i++){
			ll downtime=(a[i]-(N-1))/N+((a[i]-(N-1))%N!=0);
			a[i]-=downtime*(N+1);
			downtimeall+=downtime;
		}
		ans+=downtimeall;
		rep(i,N){
			a[i]+=downtimeall;
		}
		sort(a,a+N);
	}
	prin(ans);
	return 0;
}
