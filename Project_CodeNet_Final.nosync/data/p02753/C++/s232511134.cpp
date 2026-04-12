#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> myds;

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define F first
#define S second
#define vec(x) vector<x> 
#define pi(x,y) pair<x,y>
#define pqq(x) priority_queue<x> 
#define min_heap(x) priority_queue<x, vector<x>, greater<x> >
#define all(x) x.begin(),x.end()
#define rep(i,x,y) for(int i=x;i<y;i++)
#define repd(i,x,y,k) for(int i=x;i<y;i+=k)
#define rel(i,x,y) for(int i=x-1;i>=y;i--)
#define rev(x) reverse(all(x))
#define uniq(x) x.resize(distance(x.begin(),unique(all(x))))
#define full(x,a) memset(x,a,sizeof(x))
#define lcm(x,y) ((x*y)/__gcd(x,y))
#define mod 1000000007
#define bitcount __builtin_popcountll
#define pb push_back
#define indexof order_of_key
#define valueat find_by_order

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dxx[8]={0,0,1,-1,-1,-1,1,1};
int dyy[8]={1,-1,0,0,-1,1,1,-1};

int gcdextended(int a,int b,int &x,int &y){if(!a){x=0,y=1;return b;}int x1,y1;int ans=gcdextended(b%a,a,x1,y1);x=y1-(b/a)*x1;y=x1;return ans;}
int inv(int a){int x,y;int ans=gcdextended(a,mod,x,y);return(x%mod+mod)%mod;}
int nCr(int n,int k){int res=1;k=(k>n-k)?n-k:k;rep(i,0,k){res*=(n-i);res/=(i+1);}return res;}
int POW(int x,int y){int res=1;x=x%mod;while(y>0){if(y&1)res=(res%mod*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
//void seive(){prime[0]=0;prime[1]=0;rep(i,2,10002)prime[i]=1;for(int i=2;i*i<=10000;i++){if(prime[i]){for(int j=i*i;j<=10000;j+=i)prime[j]=0;}}} 

string s;

void input(){
	cin>>s;
}

void solve(){
	int cnt=0;
	rep(i,0,3)
		if(s[i]=='A')
			cnt++;
	if(cnt==1 || cnt==2)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}

main(){
	fastio;
	int t=1;
	while(t--){
		input();
		solve();
	}
}