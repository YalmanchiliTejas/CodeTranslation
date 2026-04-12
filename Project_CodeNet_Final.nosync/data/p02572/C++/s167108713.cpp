#include <iostream>
#include <set> 
#include <iterator>
#include <bitset> 
#include <bits/stdc++.h> 
using namespace std;
typedef  long long int ll;
ll mod=1000000007;


int main() {
    int T=1;
    //cin>>t;
    while(T--)
    {   int n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        ll suf[n+1]={0};
        ll sum=0;
        for(int i=n-1;i>=0;i--)
        {   sum=(sum%mod+a[i]%mod)%mod;
            suf[i]=sum;
        }
        ll ans=0;
        for(int i=0;i<=n-2;i++)
        {   ans=((a[i] %mod * suf[i+1] %mod)%mod+ans %mod)%mod;
        }
        cout<<ans;
            
            
    }
	return 0;
}
