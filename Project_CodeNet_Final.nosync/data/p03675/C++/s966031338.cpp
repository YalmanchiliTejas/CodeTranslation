#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define mll map<ll,ll>
#define sll set<ll>
#define fo(i,n) for(i=0;i<n;i++)
#define MOD 1000000007
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    

    ll n,i,j,k,t,a[200001];

    cin>>n;

    vll v(2*n+1,0);
    ll l=n,r=n+1,flag=0;

    fo(i,n)
    {
        cin>>a[i];
        if(flag==0)
        {
            v[l]=a[i];
            l--;
            flag=1;
        }
        else
        {
            v[r]=a[i];
            r++;
            flag=0;
        }
    }

    if(flag==1)
    {
        for(i=l+1;i<r;i++)
            cout<<v[i]<<" ";
        return 0;
    }

    for(i=r-1;i>l;i--)
        cout<<v[i]<<" ";

    return 0;
}
