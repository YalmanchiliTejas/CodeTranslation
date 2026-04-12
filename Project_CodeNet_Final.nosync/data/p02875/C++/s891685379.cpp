#include<bits/stdc++.h>
 
#define ll long long int
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define INF 0x3f3f3f3f
#define show(x) cerr<<#x<<" : "<<x<<'\n';
#define yogeshk972() cerr<<"\nTime Taken : "<<(float)(clock()-time_p)/CLOCKS_PER_SEC<<"\n";
clock_t time_p=clock();
 
using namespace std;
const int N=1e7+1, mod= 998244353;
ll fact[N],ifact[N];

ll power(int a,int n){
	if(n==0) return 1;
	ll x=power(a,n/2);
	x=(x*x)%mod;
	if(n&1) return (x*a)%mod;
	return x;
}

ll comb(int n,int r){
	return  ( fact[n]*( ( ifact[r]*ifact[n-r] )%mod)  )%mod;
}

int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0);
	
	int n;
	cin>>n;
		
	fact[0]=1;
	for(int i=1;i<=n;i++)fact[i]=(fact[i-1]*i)%mod;
	ifact[n]=power(fact[n],mod-2);
	for(int i=n-1;i>=0;i--){
		ifact[i]=(ifact[i+1]*(i+1))%mod;
	}
	
	ll r1=0;
	for(int i=n/2+1;i<=n;i++){
		r1+=( comb(n,i)*power(2,n-i) )%mod;
		if(r1>=mod)r1-=mod;
	}
	
	
	cout<<( power(3,n) -r1*2 + mod*2 )%mod;
	
    yogeshk972();
}
