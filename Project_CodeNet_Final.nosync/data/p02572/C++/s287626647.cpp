//"BISMILLAHIR RAHMANIR RAHIM"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const long long M = 1e9+7 ;
int main()
{
    ll n,i,j,ans=0,s=0;
    cin>>n;
    ll ara[n];
    for(i=0;i<n;i++){
        cin>>ara[i];
    }
    ll pre[n]={0};
    pre[0]=ara[0];
    for(i=1;i<n;i++){
        pre[i]=(pre[i-1]+ara[i]);
    }
    for(i=0;i<n;i++){
        s= (ara[i]%M* ((pre[n-1]-pre[i])%M) )%M;
        ans= ( ans+s)%M;
    }
    ans= (ans+M)%M;
    cout<<ans<<endl;
    return 0;
}

