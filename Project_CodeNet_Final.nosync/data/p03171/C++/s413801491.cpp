#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#include<map>
#define MEM(var,val) memset(var,(val),sizeof(var))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define nitro   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define tc ll tes;cin>>tes;while(tes--)
#define inf 10000000000
vll taro[3000];
vll jiro[3000];
vll v;ll n;
ll jirof(ll l ,ll r);
ll tarof(ll l ,ll r);
ll jirof(ll l,ll r)
{
    if(l>=n||r<0)return inf;
    if(l==r)
        return -v[l];
        if(jiro[l][r]!=-1)
            return jiro[l][r];
        jiro[l][r]=MIN(-v[l]+tarof(l+1,r),-v[r]+tarof(l,r-1));
        return jiro[l][r];

}
ll tarof(ll l,ll r)
{
    if(l>=n||r<0)return -inf;
    if(l==r)
        return v[l];
        if(taro[l][r]!=-1)
            return taro[l][r];
        taro[l][r]=MAX(v[l]+jirof(l+1,r),v[r]+jirof(l,r-1));
        return taro[l][r];

}
int main()
{
nitro;
for(int i=0;i<3000;i++)
{
    taro[i].resize(3000,-1);
    jiro[i].resize(3000,-1);
}
cin>>n;
v.resize(n);
for(int i=0;i<n;i++)
    cin>>v[i];
cout<<tarof(0,n-1);





   }


