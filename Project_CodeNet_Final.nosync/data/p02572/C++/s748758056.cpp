//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
const ll m=1e9+7;
bool sortbysec(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    return (a.second<b.second);
}

int main()
{
    ios;
    int n;
    cin>>n;
    ll a[n];
    ll sum[n+1]={};
    ll s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=n-1;i>=0;i--)
        sum[i]+=sum[i+1]+a[i];
    ll cnt=0;
    for(int i=0;i<n;i++)
    {
        a[i]%=m;
        sum[i+1]%=m;
        s+=(a[i]*sum[i+1])%m;
        s%=m;
    }
    cout<<s<<endl;


}


