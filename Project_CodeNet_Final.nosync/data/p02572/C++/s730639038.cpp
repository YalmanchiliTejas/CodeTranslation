#include <bits/stdc++.h>
using namespace std;
typedef long double LD; 
typedef long long ll;
#define int ll
#define ff(i,a,b) for (int i = a; i < b; i++) 
#define bf(i,a,b) for (int i = a; i >= b; i--) 
#define aint(v) v.begin(),v.end() 
#define show(a) for(auto xyz:a)cout<<xyz<<" ";cout<<endl;
#define F first 
#define S second
#define pb push_back
#define mp make_pair
#define lb lower_bound   
#define ub upper_bound
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define one cout<<"-1"<<endl
#define pi 3.141592653589793238
#define intmx INT_MAX 
#define intmi INT_MIN
void solve(){
    int n;
    cin>>n;
    int mod=1000000007;
    int a[n];
    ff(i,0,n)
    cin>>a[i];
    int ans=0;
    int sum[n];
    bf(i,n-1,1){
        if(i==n-1)
        sum[i]=a[i];
        else
        sum[i]=(sum[i+1]%mod+a[i]%mod)%mod;
    }
    ff(i,0,n-1){
        ans=(ans+((a[i]%mod)*(sum[i+1]%mod))%mod)%mod;
    }
    ans=(ans%mod+mod)%mod;
    cout<<ans<<endl;
}
signed main() {
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
