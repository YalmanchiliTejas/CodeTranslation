#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
#include<tuple>
#include<stdio.h>
#include<math.h>
 
using namespace std;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
 
#define shosu setprecision(10)
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> Q;
typedef pair<Q,ll> R;
ll longinf=1ll<<60;
int inf=1<<29;
//mleしなければぜんぶllでかく。


int main(){
	int n;
	cin>>n;
	int h[n];
	rep0(i,n) cin>>h[i];
	int M=-inf;
	int ans=0;
	rep0(i,n){
		if(h[i]>=M){
			ans++;
			M=h[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}