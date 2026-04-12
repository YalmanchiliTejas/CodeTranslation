#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define allR(v) v.rbegin(), v.rend()
#define PRINT(v) for (auto x : (v)) cout <<x <<" " ; cout <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
typedef pair<int,int> Pi;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
const int inf = 1001001001;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }

template<class T> struct edge { int to; T cost;};


// [0, N-1]ではなく[1, N], 1-indexed
struct BIT {
  int N;
  int MAX_N = 200000;
  vector<ll> bit; // bit[1]...bit[N]を使用

  BIT(int n) : N(n), bit(MAX_N+1) {}

  ll sum(int a){          // 1～a (1-indexed)の和を求める
    ll ret=0;
    for (int i=a; i>0; i -= i & -i) ret += bit[i];
    return ret;
  }

  void add(int a, ll x){  // a番目(1-indexed)に x を加える
    for (int i=a; i<=MAX_N; i += i & -i) bit[i] += x;
  }
};


void compress(vector<int> &a){
  vector<int> com(a.size());
  rep(i, a.size()) com[i] = a[i];
  sort(all(com));
  com.erase(unique(all(com)), com.end());
  rep(i, a.size()) a[i] = lower_bound(all(com), a[i]) - com.begin() + 1;
}

int main() {
  int N; cin >>N;
  vector<int> A(N); rep(i, N) cin >>A[i];
  compress(A);
  // 座標圧縮しておく。ただし1-indexed
  // 各aiについて、既に見たものの中で自分未満のもののうち最大のものを自分に置き換える
  BIT bit(N);
  rep(i, N){
    int a = A[i];
    if (a == 1){
      bit.add(a, 1);
    }else if (bit.sum(a-1) == 0){
      bit.add(a, 1);
    }else{
      // 自分未満のやつがいた！
      int x = bit.sum(a-1);
      // 具体的にはbit.sum(i) = x となる最小のやつを見つける
      int ok = a-1, ng = 0;
      while (abs(ok-ng) > 1){
        int mid = (ok+ng)/2;
        if (bit.sum(mid) == x) ok = mid;
        else ng = mid;
      }
      bit.add(ok, -1);
      bit.add(a, 1);
    }
  }
  int res = bit.sum(N);
  cout <<res <<endl;
}