#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    string a[n];
    for(ll i=0;i<n;i++)
      cin>>a[i];
    vector <ll> r;
    vector <ll> c;
    for(ll i=0;i<n;i++)
    {
      for(ll j=0;j<m;j++)
      {
        if(a[i][j] == '#')
        {
          r.push_back(i);
          break;}
      }
    }
    for(ll i=0;i<m;i++)
    {
      for(ll j=0;j<n;j++)
      {
        if(a[j][i] == '#')
        {
          c.push_back(i);
          break;}
      }
    }
    for(ll i=0;i<r.size();i++)
    {
      for(ll j=0;j<c.size();j++)
      {
        cout<<a[r[i]][c[j]];
      }
      cout<<endl;
    }
   
}