#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long mod = 1e9 + 7;

int main(){
    long long n , ans = 0;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long sum[n];
    memset(sum , 0 , sizeof(sum));
    sum[n - 1] = 0;
    for(int j=n-2;j>=0;j--){
        sum[j] = sum[j+1] + a[j+1];
    }
    for(int i = 0; i < n; i++){
        ans = (ans%mod + ((a[i]%mod) * (sum[i]%mod)))%mod;
    }
    cout<<ans<<endl;
}