#include<bits/stdc++.h>

using namespace std;

#define debug(n) cerr << #n << ':' << n << endl;
#define dline    cerr << __LINE__ << endl;

using ll = long long;
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

template<class T>
istream& operator >> (istream&is, vector<T>&v){
  for(auto&e:v)is >> e;
  return is;
}

int n;
vector<int> v;

ll dp(int b, int e, int p){
  static ll mm[3001][3001][2];
  static bool used[3001][3001][2];

  if(used[b][e][p]) return mm[b][e][p];
  else used[b][e][p] = true;
  
  if(b == e) return 0;

  if(p == 0) mm[b][e][p] = min(dp(b,e-1,1)-v[e-1],dp(b+1,e,1)-v[b]);
  else       mm[b][e][p] = max(dp(b,e-1,0)+v[e-1],dp(b+1,e,0)+v[b]);
  
  return mm[b][e][p];
}

int main(){
  cin >> n;
  v = vector<int>(n); cin >> v;
  cout << dp(0,n,1) << endl;
  return 0;
}
