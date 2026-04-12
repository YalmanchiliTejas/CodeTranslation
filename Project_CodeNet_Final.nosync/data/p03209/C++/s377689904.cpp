#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

vl a,b;

ll dfs(ll n,ll k){
	if(!k) return 0;
	if(!n) return 1;
	if(k<=a[n-1]+1) return dfs(n-1,k-1);
	return b[n-1]+1+dfs(n-1,min(a[n-1],k-a[n-1]-2));
}

ll n,k;

int main(){
	cin>>n>>k;
	a=b=vl(n+1);
	a[0]=b[0]=1;
	for(int i=1;i<=n;i++){
		a[i]=2*a[i-1]+3;
		b[i]=2*b[i-1]+1;
	}
	cout<<dfs(n,k)<<endl;
}