#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
template<typename A,typename B> istream& operator>>(istream&,pair<A,B>&);
template<typename A> istream& operator>>(istream&,vector<A>&);
void add(int&,int);
int mul(int,int);
int powz(int,int);
template<typename A> ostream& operator<<(ostream&,vector<A>&);

const int N=500001;

void solve(){
	string k;
	cin>>k;
	int d;
	cin>>d;
	vector<array<int,2>>dp(d,array<int,2>());
	dp[0][0]=1;
	for(int i=0;i<k.length();i++){
		vector<array<int,2>>new_dp(d,array<int,2>());
		for(int j=0;j<d;j++){
			for(int _=0;_<10;_++){
				if(_<(k[i]-'0')){
					add(new_dp[(j+_)%d][1],dp[j][0]);
					add(new_dp[(j+_)%d][1],dp[j][1]);
				}
				else if(_==(k[i]-'0')){
					add(new_dp[(j+_)%d][0],dp[j][0]);
					add(new_dp[(j+_)%d][1],dp[j][1]);
				}
				else{
					add(new_dp[(j+_)%d][1],dp[j][1]);
					
				}
			}
			
		}
		dp=new_dp;
	}
	cout<<(dp[0][0]+dp[0][1]-1+mod)%mod;
		
		

	
}
	
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc=1;
	//~ cin>>tc;
	for(int _=0;_<tc;_++){
		//~ cout<<"Case #"<<_+1<<": ";
		solve();
		if(_!=tc-1)
		cout<<"\n";
	}
}
 
int mul(int a,int b)
{
	return ((a)*1ll*(b))%mod;
}
 
void add(int &a,int b)
{
	a+=b;
	if(a>=mod)a-=mod;
}
 
int powz(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=mul(res,a);
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
