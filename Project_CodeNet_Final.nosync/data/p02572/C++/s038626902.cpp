#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mk make_pair
#define pb push_back
#define mod 1000000007

/*int main(){
   int d,t,s;
   cin>>d>>t>>s;
   int time=d/s;
   int ed=d%s;
   if(t<time)cout<<"No"<<endl;
   else if(t>time)cout<<"Yes"<<endl;
   else if(t==time && ed==0)cout<<"Yes"<<endl;
   else if(t==time && ed!=0)cout<<"No"<<endl;
    return 0;
}*/
int main(){
    ll n;cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    ll pre[n];
    pre[0]=a[0]%mod;
    for(int i=1;i<n;i++)pre[i]=(pre[i-1]%mod+a[i]%mod)%mod;
    ll ans=0;
    for(int i=1;i<n;i++){
    ans=(ans%mod+((pre[i-1]%mod)*(a[i]%mod))%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}