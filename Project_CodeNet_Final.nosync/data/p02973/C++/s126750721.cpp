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
template<typename A,typename B> istream& operator>>(istream&,pair<A,B>&);
template<typename A> istream& operator>>(istream&,vector<A>&);
void add(int&,int);
int mul(int,int);
int powz(int,int);
int sub(int,int);
template<typename A> ostream& operator<<(ostream&,vector<A>&);
 
const int N=1000001;
int st[4*N];

void update(int v,int tl,int tr,int ind){
	if(tl==tr){
		st[v]++;
		return;
	}
	int mid=(tl+tr)/2;
	if(ind<=mid){
		update(2*v,tl,mid,ind);
	}
	else{
		update(2*v+1,mid+1,tr,ind);
	}
	st[v]=st[2*v]+st[2*v+1];
}

void solve(){
	int n;
	cin>>n;
	vi a(n);
	cin>>a;
	multiset<int>en;
	for(int i=0;i<n;i++){
		if(en.empty()){
			en.insert(a[i]);
		}
		else{
			auto it=en.lower_bound(a[i]);
			    if(it==en.begin()&&(*it>=a[i])){
					en.insert(a[i]);
				}
				else if(it==en.begin()){
					en.erase(it);
				en.insert(a[i]);
				}
				else{
				it--;
				en.erase(it);
				en.insert(a[i]);
			}
			
			
		}
	}
	cout<<en.size();
	
	
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc=1;
	//~ cin>>tc;
	for(int _=0;_<tc;_++){
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
