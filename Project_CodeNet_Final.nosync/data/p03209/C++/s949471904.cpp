#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
ll x;
ll num[55][2];
ll ret(int n,ll x){
	assert(num[n][0]+num[n][1] >= x);
	if(num[n][0]+num[n][1] == x) return num[n][1];
	ll rett = 0;
	ll zan = x-1;
	zan = min(zan,num[n-1][0]+num[n-1][1]);
	if(zan > 0) rett += ret(n-1,zan);
	zan = x-1-num[n-1][0]-num[n-1][1];
	if(zan > 0) rett++;
	zan--;
	zan = min(zan,num[n-1][0]+num[n-1][1]);
	if(zan > 0) rett += ret(n-1,zan);
	return rett;
}
int main(){
	num[0][0] = 0; num[0][1] = 1;
	for(int i=1;i<55;i++){
		num[i][0] = 2LL+2LL*num[i-1][0];
		num[i][1] = 1LL+2LL*num[i-1][1];
	}
	cin>>n>>x;
	cout<<ret(n,x)<<endl;
}