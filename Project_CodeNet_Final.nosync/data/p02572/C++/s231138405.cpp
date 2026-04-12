#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
ll n;
cin>>n;
ll a[n],sum=0,cusum=0;
// pre[0] = 0;
for(ll i=0;i<n;i++){
cin>>a[i];
sum += a[i];
}
ll final=0,mod = 1000000007;
for(ll i=n-1;i>=0;i--){
final = ((final%mod) + ((a[i]*cusum)%mod))%mod;
cusum = (cusum%mod + a[i]%mod)%mod;
}
cout<<final<<endl;
}