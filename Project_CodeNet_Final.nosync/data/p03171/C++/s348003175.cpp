#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
ll a[3001];
ll memo[3001][3001];
ll findans(ll i,ll j)
{
    if(i==j)
    {
        return a[i];
    }
    if(i+1==j)
    {
        return max(a[i],a[j]);
    }
    if(i>j)
    {
        return 0;
    }
    if(memo[i][j]!=-1)
    {
        return memo[i][j];
    }
    ll choice1=a[i]+min(findans(i+1,j-1),findans(i+2,j));
    ll choice2=a[j]+min(findans(i,j-2),findans(i+1,j-1));
    return memo[i][j]=max(choice1,choice2);
}
int main(){
    // Your code here!
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll i=0;i<=3000;i++)
    {
        for(ll j=0;j<=3000;j++)
        {
            memo[i][j]=-1;
        }
    }
    ll x=findans(0,n-1);
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        sum+=a[i];
    }
    ll y=sum-x;
    cout<<x-y;
}
