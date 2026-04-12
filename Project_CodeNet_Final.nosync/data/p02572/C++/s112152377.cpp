#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n;
    cin>>n;
    vector<long long> v1(n);
    vector<long long> v2(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];

    }
    v2[0]=v1[0];
    for(int i=1;i<n;i++){
        v2[i]=v2[i-1]+v1[i];
        v2[i]%=mod;
    }
    long long ans=0;
    for(int i=1;i<n;i++){
        ans+=v2[i-1]*v1[i];
        ans%=mod;
    }
    cout<<ans<<"\n";
}
