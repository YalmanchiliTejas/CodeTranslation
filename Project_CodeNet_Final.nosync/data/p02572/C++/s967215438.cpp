/*
AUTHOR: Naman
*/
#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define vll vector<long long>
#define all(x) x.begin(),x.end()
#define pb push_back
#define Fo(i,k,n) for(ll i=k;i<=n;i+=1)
#define deb(x) cout << #x << "=" << x << endl
#define in(a,n) Fo( i,0,n-1)cin>>a[i]
#define out(a,n) Fo( i,0,n-1)cout<<a[i]<<" ";cout<<endl
#define IOS     ios_base::sync_with_stdio(0); cin.tie(NULL);
const ll N=2*1e6+1;
const ll M=1e9+7;

int main() {
	IOS
    ll t=1;
	//cin>>t;	
	
	Fo(_,1,t)
	{
	   //cout<<"Case #"<<_<<": ";
	   ll n;
	   cin>>n;
	   ll ar[n];
	   in(ar,n);
	   ll suf[n];
	   suf[n-1]=ar[n-1];
	   
	   for(ll i=n-2;i>=0;i--)suf[i]=(suf[i+1]+ar[i]%M)%M;
	   
	   ll ans=0;
	   
	   Fo(i,0,n-2)
	   {
	       ans+=(ar[i]%M*suf[i+1]%M)%M;
	       ans%=M;
	   }
	   cout<<ans;
	   
	   


	   cout<<endl;
	   
	}
	
    
}