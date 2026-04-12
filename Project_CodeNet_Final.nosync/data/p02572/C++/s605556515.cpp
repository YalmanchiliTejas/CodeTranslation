#include <bits/stdc++.h>
using namespace std;

int main(){
    long long mod=1000000007;
    long long n,sum=0,ans=0;
    cin>>n;
	long long a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
        sum+=a[i];
    }
    for(int i=0;i<n;i++){
    	sum-=a[i];
        ans=(ans+(sum%mod)*a[i])%mod;
    }
    cout<<ans;
}