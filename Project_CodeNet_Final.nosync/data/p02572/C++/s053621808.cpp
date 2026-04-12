#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define  pb push_back
#define sort1(v) sort(v.begin(),v.end())
ll a[3002][3002];
void upd(int i,int j,int n)
{
    a[i+1][j+1]++;
    a[j][j+1]--;
    a[i+1][n+1]--;
    a[j][n+1]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    ll mod=1e9+7;
    ll sum1=0,sum2=0;
    for(int i=0;i<n;i++)
    {
        sum1+=a[i];
        sum2+=a[i]*a[i];
        sum1%=mod;
        sum2%=mod;
    }
    sum1=sum1*sum1;
    sum1%=mod;
    ll ans=(sum1-sum2+mod)%mod;
    ans=ans*(mod+1)/2;
    ans=ans%mod;
    cout<<ans<<"\n";

}






