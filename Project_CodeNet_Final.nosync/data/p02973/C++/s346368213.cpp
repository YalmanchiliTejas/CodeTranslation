#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<ld> vd;
typedef bool bl;
typedef vector<bl> vb;
typedef vector<vl> mt;
typedef unordered_map<ll,unordered_map<ll,ll>> graph;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<string> vs;
typedef vector<vs> table;


const ll e5 = 1 << 20;
const ll mod = 1000000007;
const ll e3 = 1 << 13;
const ll INF = 1ll << 50;

ll n;
vl a;
multiset<ll> s;

void show_s(){
  for(ll x : s){
    cerr << x << " ";
  }
  cerr << endl;
}

int main(){
  cin >> n;
  a = vl(n);
  for(ll i = 0;i < n;i++) cin >> a.at(i);
  for(ll i = 0;i < n;i++){
    auto x_iter = s.upper_bound(-a.at(i));
    if(x_iter == s.end()){
      s.insert(-a.at(i));
    }else{
      s.erase(x_iter);
      s.insert(-a.at(i));
    }
    // show_s();

  }
  cout << s.size() << endl;


}
