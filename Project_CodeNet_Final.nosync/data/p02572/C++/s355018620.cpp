
#include<bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin>>n;
    long long int a[n],ans=0,i;
    int mod=1000000007;
    long long int sum=0;

    for( i = 0 ; i < n ; i++ ){
            cin>>a[i];
        sum = sum + a[i];
    }
    for( i = 0 ; i < n ; i++ ){
        sum = sum - a[i];

        ans+=(sum%mod * a[i]%mod)%mod;
    }
    cout<<ans%mod;

    return 0;
}
