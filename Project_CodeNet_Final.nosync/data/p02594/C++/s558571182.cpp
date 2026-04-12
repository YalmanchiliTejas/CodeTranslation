#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstdio>
#include<sstream>
#include<utility>
#include<string>
#include<cstdlib>
#include<valarray>
#include<algorithm>
#include<vector>
#include<iterator>
#include<list>
#include<set>
#include<numeric>
#include<bits/stdc++.h>
#define ll long long
ll prime[1000002];
using namespace std;
int Prime(int a)
{
    for(int i=2;i<=a/2;++i)
    {
        if(a%i==0)
        {
            return 0;
        }
    }
    return 1;
}
void sieve()
{   for(int i=0;i<=1000001;i++)
    prime[i]=0;
    int maxn=1000001;
    for(int i=2;i<=maxn;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i;j<=maxn;j+=i)
            {
                prime[j]++;
            }
        }
    }
}
void fibo(ll a[],ll n)
{
    ll x=0;
    ll y=1;
    a[0]=0;
    a[1]=1;
    for(ll i=2;i<n;++i)
    {
        a[i]=(x+y)%10;
        x=y;
        y=a[i];
    }
}
ll f(ll w[],ll a[][2],ll i,ll y)
{
    for(ll j=0;j<y;++j)
    {
        if(a[i][2]<=w[j])
        {
            cout<<a[i][2];
            return w[j];
        }
    }
    return w[y-1];
}
ll s(ll v[],ll a[][2],ll i,ll x)
{
    for(ll j=0;j<x;++j)
    {
        if(a[i][1]>=v[j])
        {
            cout<<" "<<a[i][1]<<" ";
            return v[j];
        }
    }
    return v[0];
}
bool binarySearch(vector <ll> arr, int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return 1; 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
        return binarySearch(arr, mid + 1, r, x); 
    } 
    return 0; 
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll t,n,i;
    cin>>n;
    if(n>=30)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}
