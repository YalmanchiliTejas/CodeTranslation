#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define mp make_pair
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
 
const int mod=1e9+7;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int mul(int a,int b)
{
	return ((a)*1ll*(b))%mod;
}
 
void add(int &a,int b)
{
	a+=b;
	if(a>=mod)a-=mod;
}
 
int sub(int a,int b){
	a-=b;
	if(a<0){
		a+=mod;
	}
	return a;
}
 
int powz(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1){
			res=mul(res,a);
		}
		b/=2;
		a=mul(a,a);
	}
	return res;
}
 
template <typename A, typename B>
istream& operator>>(istream& input,pair<A,B>& x) {
	input>>x.F>>x.S;
	return input;
}
 
template <typename A>
istream& operator>>(istream& input,vector<A>& x) {
	for(auto& i:x)
		input>>i;
	return input;
}
 
template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {
	for(auto& i:x)
		output<<i<<' ';
	return output;
}
 
const int N=1000002;

int dp[2][1005],fc[1005],in[1005];

int C(int n,int r){
	if(n<r){
		return 0;
	}
	return mul(mul(fc[n],in[r]),in[n-r]);
}

int calc(int count,int size){
	return mul(mul(fc[count*size],in[count]),powz(in[size],count));
}

void solve(){
	int n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	dp[0][n]=1;
	for(int i=a;i<=b;i++){
		for(int set=c;set<=d;set++){
			if(set*i>n){
				break;
			}
			int cnst=calc(set,i);
			for(int last=n;last>=set*i;last--){
				add(dp[1][last-set*i],mul(mul(cnst,C(last,set*i)),dp[0][last]));
			}
		}
		for(int j=0;j<=n;j++){
			add(dp[0][j],dp[1][j]);
			dp[1][j]=0;
		}
	}
	cout<<dp[0][0];
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc=1;
	fc[0]=1;
	for(int i=1;i<=1000;i++){
		fc[i]=mul(fc[i-1],i);
	}
	in[1000]=powz(fc[1000],mod-2);
	for(int i=999;i>=0;i--){
		in[i]=mul(in[i+1],i+1);
	}
	//~ cin>>tc;
	for(int _=0;_<tc;_++){
		//~ cout<<"Case #"<<_+1<<": ";
		solve();
		if(_!=tc-1)
		cout<<"\n";
	}
}
