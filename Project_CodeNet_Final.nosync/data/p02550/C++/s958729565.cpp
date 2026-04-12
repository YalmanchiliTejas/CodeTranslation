/*Author : Yuvraj Singh
 * Patience is Power
 * 
 * */
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
#define ar array
ll power(ll x,ll y) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y%2 == 0) 
        return ((temp%mod)*(temp%mod))%mod; 
    else
        return ((x%mod)*(temp%mod)*(temp%mod))%mod; 
}

int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}


bool cmp(pair<int,int>a,pair<int,int>b){
	return a.second<b.second;
}



#define mm 998244353
void solve(){
	ll n,x,m;
	cin>>n>>x>>m;
	ll res=0;
	ll i=0;
	vector<ll>v;
	ll tmp=x;
	vector<ll>::iterator it;
	while(i<n){
		it = find(v.begin(),v.end(),tmp);
		if(it!=v.end()) break;
		res+=tmp;
		v.push_back(tmp);
		tmp = tmp*tmp%m;
		i++;
		

	}
	if(i==n){
		cout<<res; return;
	} 
	else{
		ll sum=0;
		ll diff = v.end()-it;
		for(auto tt=it;tt!=v.end();tt++)
			sum+=*tt;
		ll d=(n-i)/diff;
		res+=d*sum;
		ll rim=(n-i)%diff;
		auto tt=it;
		for(ll j=0;j<rim;j++){
			res+=*tt;
			++tt;
		}
		cout<<res; return;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	//int t; cin>>t;
	//while(t--)
		solve();
    return 0;
}