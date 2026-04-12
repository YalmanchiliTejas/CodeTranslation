#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const ll mod =1000000007;

#define rep(i,m,n) for(ll i=m;i<n;i++)
struct UnionFind {
    vector<int> par,si; 

    UnionFind(int N) : par(N), si(N,1) { 
        rep(i,0,N) par[i] = i;
    }

    int root(int x) { 
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        x = root(x); 
        y = root(y); 
        if (x == y) return; 
        si[y]+=si[x];
        par[x] = y; 
    }

    bool same(int x, int y) { 
      return root(x)== root(y);
    }
    int size(int x){
       return si[root(x)];
    }

};


int main(){
   cin.tie(nullptr);
  ios::sync_with_stdio(false);

 ll n;
  cin >> n;
  vector<pll> x(n),y(n);
  rep(i,0,n) {
    cin >> x[i].first >> y[i].first;
    x[i].second=i;
    y[i].second=i;
  }
  
  
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  
  vector<tuple<ll,ll,ll>> t;
  rep(i,0,n-1) t.push_back(make_tuple(x[i+1].first-x[i].first,x[i].second,x[i+1].second));
  rep(i,0,n-1) t.push_back(make_tuple(y[i+1].first-y[i].first,y[i].second,y[i+1].second));
  
  sort(t.begin(),t.end());

  ll res=0;
  UnionFind u(n);
  rep(i,0,t.size()){
    if(!u.same(get<1>(t[i]),get<2>(t[i]))) {
      res+=get<0>(t[i]);
      u.unite(get<1>(t[i]),get<2>(t[i]));
    }
  }
  cout << res << endl;
}