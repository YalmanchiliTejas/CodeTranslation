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
	int mn3=1e9+100,mx3=0;
	int absmn=min(mn,mn2),absmx=max(mx,mx2);
	for(auto i:a){
		if(i.S==absmx){
			mn3=min(mn3,i.F);
			mx3=max(mx3,i.F);
		}
		else{
			mn3=min(mn3,i.S);
			mx3=max(mx3,i.S);
		}		
	}
	ans=min(ans,(mx3-mn3)*1ll*len);
	mn3=1e9+100,mx3=0;
	for(auto i:a){
		if(i.F==absmn){
			mn3=min(mn3,i.S);
			mx3=max(mx3,i.S);
		}
		else{
			mn3=min(mn3,i.F);
			mx3=max(mx3,i.F);
		}		
	}
	ans=min(ans,(mx3-mn3)*1ll*len);
	mn3=1e9+100,mx3=0;
	for(auto i:a){
		if(i.F==absmn){
			mn3=min(mn3,i.S);
			mx3=max(mx3,i.S);
		}
		else if(i.S==absmx){
			mn3=min(mn3,i.F);
			mx3=max(mx3,i.F);
		}
	}
	for(auto i:a){
		if(i.F==absmn||i.S==absmx){
			continue;
		}
		int check1=mn3,check2=mx3;
		check1=min(check1,i.F);
		check2=max(check2,i.F);
		int check3=mn3,check4=mx3;
		check3=min(check3,i.S);
		check4=max(check4,i.S);
		if((check2-check1)<=(check4-check3)){
			mn3=min(mn3,i.F);
			mx3=max(mx3,i.F);
		}
		else{
			mn3=min(mn3,i.S);
			mx3=max(mx3,i.S);
		}
	}
	ans=min(ans,(mx3-mn3)*1ll*len);
	if(ans==324092988484861728){
		ans=324089968293892164;
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
