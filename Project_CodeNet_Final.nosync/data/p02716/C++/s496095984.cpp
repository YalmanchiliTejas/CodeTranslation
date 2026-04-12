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

ll Solve(int i,int j){
  if(i<0) return 0;
  if( j<(i)/2 || j>(i+2)/2) return -1001001001001001;
  static map<P<int,int>,ll> mp;
  if(mp.find({i,j}) != mp.end()) return mp[{i,j}];
  ll t = 0;
  if(i == 0){
    if(j > 1) return -1001001001001001;
    if(j == 0) return 0;
    return v[i];
  } else {
    t = max(Solve(i-2,j-1)+v[i],Solve(i-1,j));
  }
  return mp[{i,j}] = t;
}

int main(){
  cin >> n;
  v.resize(n);
  cin >> v;
  cout << Solve(n-1,n/2) << endl;
  return 0;
}
