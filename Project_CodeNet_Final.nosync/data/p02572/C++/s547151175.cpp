#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007
int main(){
    long long int n,g,ans=0;
    cin>>n;
    vector<long long int> v, s(n,0);
    
    for(long long int i=0;i<n;i++)
    {
        cin>>g;
        v.push_back(g);
    }
    s[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--)
    {
        s[i]=(v[i]+s[i+1])%mod;
    }
    for(int i=0;i<n-1;i++)
    {
        ans=(ans+(v[i]*s[i+1])%mod)%mod;
    }
    cout<<ans;
    return 0;
}