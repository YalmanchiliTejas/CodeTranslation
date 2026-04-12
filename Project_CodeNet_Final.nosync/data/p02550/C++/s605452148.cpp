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
  ll n,x,m; cin >> n >> x >> m;
  ll a[100000] = {};
  ll b[100000] = {};
  bitset<100000> bs;
  ll cnt = 1;
  ll ans = x;
  while(1){
    if(cnt == n){
      cout << ans << endl;
      break;
    }
    cnt++;
    x = (x*x) % m;    
    ans += x;
    if(bs[x]){
      ll diffa = b[x] - ans;
      ll diffc = a[x] - cnt;
      ll rans = ans + ((n-cnt)/diffc)*diffa;
      n = (n-cnt)%diffc;
      for(ll i = 0; i < n; ++i){
	x = (x*x)%m;
	rans += x;
      }
      cout << rans << endl;
      return 0;
    }
    bs[x] = 1;
    a[x] = cnt;
    b[x] = ans;
  }  
  return 0;
}
