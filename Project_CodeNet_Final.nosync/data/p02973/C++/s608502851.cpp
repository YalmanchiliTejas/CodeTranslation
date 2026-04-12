#include<bits/stdc++.h>

#define debug(n) cerr << #n << ':' << n << endl;

using namespace std;

using  ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using  vi = vector<int>;
using  vl = vector<ll>;
using  vd = vector<double>;
template<class T,class U>
using umap = unordered_map<T,U>;
template<class T>
using uset = unordered_set<T>;

template<class T>
inline bool change_max(T&a, const T&b){
  if(b > a){
    a = b;
    return true;
  }
  return false;
}

template<class T>
inline bool change_min(T&a, const T&b){
  if(a > b){
    a = b;
    return true;
  }
  return false;
}

template<class T>
inline void putv(const vector<T>&v,char c = '\n'){
  for(auto&&e:v){
    cout << e << c;
  }
}

bool comp(int a, int b){
  return a>b;
}

int main(){
  int n;cin >> n;
  vi v;
  int ans = 0;
  for(int i = 0; i < n; ++i){
    int x; cin >> x;
    auto it = upper_bound(v.begin(), v.end(), x, comp);
    if(it == v.end()){
      ans++;
      v.push_back(x);
    }else{
      *it = x;
    }
  }
  cout << ans << endl;
  return 0;
}
