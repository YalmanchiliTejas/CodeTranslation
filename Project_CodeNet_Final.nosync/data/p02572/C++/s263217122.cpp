#include <bits/stdc++.h>

using namespace std;
int slv(string s,string t){
    int ret=0;
    for(int i=0;i<s.size();i++)
        ret+=(s[i]!=t[i]);

    return ret;
}
int main()
{
    ///{}
    int n;
    long long rm=1e9+7;
    cin>>n;
    vector<long long>v(n),acu(n+1);
    for(int i=0;i<n;i++){
        cin>>v[i];
        acu[i+1]=acu[i]+v[i];
        acu[i+1]%=rm;
    }
    long long ans=0ll;
    for(int i=0;i<n;i++){
        ans+=(v[i]*((((acu[n]-acu[i+1])%rm)+rm)%rm))%rm;
        ans%=rm;
    }
    cout<<ans<<'\n';
    return 0;
}
