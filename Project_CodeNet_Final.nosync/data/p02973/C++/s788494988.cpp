#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repn(i,n) for(ll i=0;i<=(ll)(n);i++)
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
//cin.tie(0);
//ios::sync_with_stdio(false);



signed main(){
  ll n;cin>>n;
  vector<ll> v(n);//index
  vector<bool> flag(n,false);//見たならtrue

  for(int i=0;i < n;i++)
  {
    cin>>v[i];
  }

  vector<ll> table(0);
  table.pb(v[0]);

  for(int i=1;i < n;i++)
  {
    int itr=lower_bound(all(table),v[i])-table.begin();

    if(itr==0)table.insert(table.begin(),v[i]);

    else table[itr-1]=v[i];

  }
  cout<<siz(table)<<endl;
}

