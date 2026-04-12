#include <bits/stdc++.h>
using namespace std;
long long m=1e9+7;
int main(){
    int n;
    cin>>n;
    long long a[n]; long long hash[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        hash[i]=0;
    }
    hash[0]=a[0];
    for(int i=1;i<n;i++){
        hash[i]=(a[i]+hash[i-1])%m;
    }
    long long ans=0;
    for(int i=1;i<n;i++){
        ans=(ans+(a[i]*hash[i-1])%m)%m;
    }
    cout<<ans;

}