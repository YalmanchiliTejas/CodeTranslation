#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
#define all(a) a.begin(),a.end()
#define ll long long int
#define ld long double
ll power(ll a,ll b,ll m){ if(b==0) return 1; if(b==1) return a%m; ll t=power(a,b/2,m)%m; t=(t*t)%m; if(b&1) t=((t%m)*(a%m))%m; return t;}
ll modInverse(ll a, ll m) { return power(a, m-2, m); }
#define ipr pair<ll,ll>
#define ps push_back
#define fs first
#define sc second
#define endl "\n"
#define mod 1000000007
int main(){
	
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll i,j,k,l,n;
	cin>>n;
	char ar[n+1];
	cin>>ar;
	cin>>k;
	k--;
	char c=ar[k];
	for(i=0;i<n;i++){
		if(ar[i]!=c){
			ar[i]='*';
		}
	}
	ar[n]='\0';
	cout<<ar;
	return 0;
}
