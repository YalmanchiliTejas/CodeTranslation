#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define MOD 1000000007
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define FOR(a,n) for(int i=a;i<n;++i)
#define arrin(n) for(int i=0; i < n; ++i) cin>>arr[i];
#define arrout(n) for(int i=0; i < n; ++i) cout<<arr[i]<<" ";cout<<nl;
#define nl "\n"
#define mp make_pair
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;


int main(){    	
	fastio();
	int n;
	cin>>n;
	int a[n];
	for(int j=0;j<n;j++) cin>>a[j];
   	vector <int> v;
   	int i=n-1;
   	if(!(n&1)) i--;
   	for(;i>=0;i-=2) v.pb(a[i]);
   	for(i=1;i<n;i+=2) v.pb(a[i]);
   	if(n&1) for(i=0;i<n;i++) cout<<v[i]<<" ";
   	else 	 for(i=n-1;i>=0;i--) cout<<v[i]<<" ";
   	

   	return 0;
}	



