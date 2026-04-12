#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >>n;
    ll a[n],i,sum=0,sum_ind[n];
    for(i=0;i<n;i++){
        cin >>a[i];
        sum=(sum+a[i])%mod;
        if(i==0) sum_ind[i]=a[i];
        else sum_ind[i]=(a[i]+sum_ind[i-1])%mod;
    }
    ll ans=0;
    for(i=0;i<n;i++){
        ans=(ans+(((sum-sum_ind[i]+mod)%mod)*(a[i]))%mod)%mod;
    }
    cout <<ans<<endl;
}   