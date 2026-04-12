#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define max1 100005
#define sz1 100001
#define mod 1000000007
#define moda 421412341324321ll
#define inf 1e18
#define ll long long int
#define debug(x) cout<<#x<<" "<<x<<endl
typedef pair<ll,ll> pr;
#define rte cout<<"Correct";exit(0);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  /*#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif*/
    ll x,y;
  cin>>x>>y;
  if(y<x)
  {
    cout<<"No\n";
  }
  else
  {
    cout<<"Yes\n";
  }
} 
