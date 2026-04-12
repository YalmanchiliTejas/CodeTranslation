#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1e9+7;
int32_t main() {
    int n;
    cin>>n;
    int a[n];
    int p[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i!=0)p[i]=p[i-1]+a[i];
        else p[i]=a[i];
    }
    int sum=0;
    for(int i=0;i<n-1;i++){
        
        sum=(sum+(a[i]*((p[n-1]-p[i])%MOD)))%MOD;
    }
    cout<<sum%MOD<<"\n";
    return 0;
}