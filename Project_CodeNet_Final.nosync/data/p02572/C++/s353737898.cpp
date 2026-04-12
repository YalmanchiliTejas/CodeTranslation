#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
	int n;
	cin>>n;
	ll sum=0,mod=1e9+7,a[n],ans=0,x;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    } 
    for(int i=0;i<n;i++)
    {
        x=(sum-=a[i])%mod;
        x=(x*a[i])%mod;
        ans=(ans+x)%mod;
    }
    cout<<ans;
}