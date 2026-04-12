/*
{By GWj
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
LL sum[100000+20];
LL app[100000+20];
LL rest=0;
int main(){
	fastio;
	LL n,x,m;
	cin>>n>>x>>m;
	if(n<=200000){
		rb(i,1,n){
			rest+=x;
			x*=x;
			x%=m;
		}
		cout<<rest<<endl;
		return 0;
	}
	sum[1]=x;
	app[x]=1;
	int nn=1;
	while(1){
		x=x*x%m;
		if(app[x]){
			int len=nn-app[x]+1;
			rest=sum[app[x]-1];
			rest+=(n-(app[x]-1))/len*(sum[nn]-sum[app[x]-1]);
			int remi=(n-app[x]+1)%len;
			rest+=sum[app[x]+remi-1]-sum[app[x]-1];
			cout<<rest<<endl;
			break;
		}
		nn++;
		app[x]=nn;
		sum[nn]=sum[nn-1]+x;
	}
	return 0;
}
