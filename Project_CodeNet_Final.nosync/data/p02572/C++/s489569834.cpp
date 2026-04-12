/*
*ID: juryc
*LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll mod=1e9+7; 
int main(){
ll n; cin>>n;
vector<ll> v(n); 
for(ll& i: v) cin>>i;
ll s=v[n-1]; 
ll ans=0; 
for(int i=n-2;i>=0;i--){ ans=(ans+(v[i]*s)%mod)%mod; s=(s+v[i])%mod; }  
cout<<ans<<endl;
return 0;
}
