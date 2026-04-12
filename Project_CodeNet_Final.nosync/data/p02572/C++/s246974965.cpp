#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    unsigned long long int n;
    cin>>n;
    unsigned long long int a[n];
    unsigned long long int mod=pow(10, 9)+7;
    rep(i, n) {
        cin>>a[i];
        if(a[i]>=mod){
            a[i]%=mod;
        }
    }
    // rep(i,n){
    //     cout<<a[i]<<endl;
    // }
    unsigned long long int ans=0;
    unsigned long long int sum = 0;
    
    for(unsigned long long int i=0;i<n-1;i++){
        sum+=a[i];
        sum %= mod;
        ans += sum*a[i+1];
        ans %= mod;
    }
    cout<<ans<<endl;
}