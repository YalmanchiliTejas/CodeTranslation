#include<bits/stdc++.h>

using namespace std;

#define debug(n) cerr << #n << ':' << n << endl;
#define dline    cerr << __LINE__ << endl;

using ll = long long;
using ull = unsigned long long;
template<class T, class U> using P = pair<T,U>;
template<class T> using Heap = priority_queue<T>;
template<class T> using heaP = priority_queue<T,vector<T>,greater<T>>;
template<class T,class U> using umap = unordered_map<T,U>;
template<class T> using uset = unordered_set<T>;

template<class T>
bool ChangeMax(T&a,const T&b){
  if(a >= b) return false;
  a = b;    return true;
}

template<class T>
bool ChangeMin(T&a,const T&b){
  if(a <= b) return false;
  a = b;    return true;  
}

template<class T, size_t N, class U>
void Fill(T (&a)[N], const U&v){
    fill((U*)a,(U*)(a+N),v);
}

template<class T,class U>
istream& operator >> (istream&is, P<T,U>&p){
  is >> p.first >> p.second;
  return is;
}

template<class T>
istream& operator >> (istream&is, vector<T>&v){
  for(auto&e:v){
    is >> e;
  }
  return is;
}
int main(){
  int n; cin >> n;
  vector<int> v(n); cin >> v;
  ll ans = 0;
  sort(v.begin(), v.end());
  int l = 0,r = n-1;
  while(r-l>2){
    ans += v[r]*2 - v[l]*2;
    l++;
    r--;
  }
  if(r - l == 1)ans += v[r] - v[l];
  else ans += max(v[r]*2-v[l]-v[r-1],v[r]-v[l]*2+v[r-1]);
  cout << ans << endl;
}
