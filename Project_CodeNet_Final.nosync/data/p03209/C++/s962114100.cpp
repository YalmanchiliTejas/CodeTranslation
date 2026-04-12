#include "bits/stdc++.h"
using namespace std;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define ALL(s) s.begin(),s.end()
#define P pair<int,int>
#define print(n) cout<<n<<endl
const int M=100010;
const int MOD=1000000007;
const int INF=1000000007;
using ll=long long;

ll n,x,ans=0;
ll a[50]={},p[50]={};

ll dfs(ll n,ll x){
	if(n==0){
		if(x<=0)return 0;
		else return 1;
	}
	if(x<=a[n-1]+1)return dfs(n-1,x-1);
	else return p[n-1]+1+dfs(n-1,x-a[n-1]-2);
}

int main(){
	cin>>n>>x;
		a[0]=p[0]=1;
	rep(i,1,n+1){
		a[i]=a[i-1]*2+3;
		p[i]=p[i-1]*2+1;
	}
	print(dfs(n,x));
}