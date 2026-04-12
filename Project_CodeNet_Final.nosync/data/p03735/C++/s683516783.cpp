#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define int ll
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
 
int mod=1e9+7;
 
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

void solve(){
	int n;
	cin>>n;
	vector<pair<int,int>>a(n);
	cin>>a;
	int mn=1e9+100,mx=0,mn2=1e9+100,mx2=0;
	for(auto &i:a){
		if(i.F>i.S){
			swap(i.F,i.S);
		}
		mn=min(mn,i.F);
		mx=max(mx,i.F);
		mn2=min(mn2,i.S);
		mx2=max(mx2,i.S);
	}
	ll ans=(mx2-mn2)*1ll*(mx-mn);
	ll len=max(mx2,mx)-min(mn2,mn);
	sort(all(a));
	multiset<int>st;
	for(auto i:a){
		st.insert(i.F);
	}
	for(int i=0;i<=n;i++){
		int x=*st.begin(),y=*st.rbegin();
		ans=min(ans,len*(y-x));
		if(i<n){
			st.erase(st.find(a[i].F));
			st.insert(a[i].S);
		}
	}
	cout<<ans;
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
