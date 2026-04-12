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

int main(){
  int h,w; cin >> h >> w;
  string s[100];
  for(int i = 0; i < h; ++i)cin >> s[i];
  bitset<100> bsh,bsw;
  for(int i = 0; i < h; ++i){
    bool f = true;
    for(int j = 0; j < w; ++j)f &= s[i][j] == '.';
    bsh[i] = f;
  }
  for(int i = 0; i < w; ++i){
    bool f = true;
    for(int j = 0; j < h; ++j)f &= s[j][i] == '.';
    bsw[i] = f;
  }
  for(int i = 0; i < h; ++i){
    if(bsh[i])continue;
    for(int j = 0; j < w; ++j){
      if(bsw[j])continue;
      cout << s[i][j];
    }
    cout << endl;
  }
  return 0;
}
