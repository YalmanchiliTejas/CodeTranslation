#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 9999999999;
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
  T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }


int N,M;

int main() {
  cin >>N >>M;
  Graph G(N);
  rep(i, M){
    int a,b; cin >>a >>b;
    a--; b--;
    G[a].push_back(b); G[b].push_back(a);
  }
  int res = 0;

  vector<int> tmp(N);
  rep(i, N) tmp[i] = i;

  do{
    bool ok = true;
    if (tmp[0] != 0) continue;
    for (int i=0; i<N-1; i++){
      int nowx = tmp[i], nextx = tmp[i+1];
      bool dame = true;
      for (auto x : G[nowx]){
        if (x == nextx){
          dame = false;
          break;
        }
      }
      if (dame){
        ok = false; break;
      }
    }
    if (ok){
      res++;
    }
  } while(next_permutation(all(tmp)));

  cout <<res <<endl;
}