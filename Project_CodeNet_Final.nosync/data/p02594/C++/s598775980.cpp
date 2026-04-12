#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename K,typename V>
using umap = unordered_map<K,V>;
template <typename V>
using uset = unordered_set<V>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i,n) for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ALL(v) v.begin(),v.end()

#define INF 1'000'000'000'000 //10^12
#define MOD 1'000'000'007
//グリッドグラフの範囲チェック
bool range_validation(int y,int x,int h,int w){
    return y>=0 && y<h && x>=0 && x < w;
}
//ビットカウント
int popcount(long bits){
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

int gcd(ll a, ll b){
  if(b == 0){
    return a;
  }else{
    return gcd(b,a%b);
  }
}

vector<ll> sieve(ll n){
  int p = 0;
  vector<bool> is_prime(n+1,true);
  vector<ll> res;
  for(int i=2;i<=n;i++){
    if(is_prime[i]){
      res.push_back(i);
      for(int j=2*i;j<=n;j+=i){
        is_prime[j] = false;
      }
    }
  }
  return res;
}

vector<ll> divisor(ll n){
  vector<ll> list;
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      list.push_back(i);
      if(n/i != i){
        list.push_back(n/i);
      }
    }
  }
  return list;
}

umap<int,int> prime_factor(ll n){
  umap<int,int> fac;
  for(int i=2;i*i<=n;i+=2){
    if(n%i == 0){
      int count = 0;
      while(n%i == 0){
        count++;
        n /= i;
      }
      fac[i] = count;
    }
  }
  if(n!=1)fac[n] = 1;
  return fac;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int x;
  cin >> x;
  if(x >= 30){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
