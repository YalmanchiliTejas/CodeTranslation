#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <deque>
#include <cctype>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<long, long>;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
#define rep(i, n) for(int i = 0; i<n; i++)
#define rep_s(i, start, n) for(int i= start;  i<n; i++)
#define rep_down(i, n) for(int i = n-1; i>=0; i--)
#define rep_down_s(i, n, start) for(int i = n-1; i>=start; i--)
#define ALL(a) (a).begin(), (a).end()
#define ALL_str(a) (a).cbegin(), (a).cend()

string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alphabet_lower  = "abcdefghijklmnopqrstuvwxyz";
string numbers = "0123456789";

/*
using edge = struct {int to; ll cost;};
vector<edge> tree[limit];
ll depth[limit];

void dfs(int v, int p, ll d){
  depth[v] = d;
  //cout <<"v: " << v << endl;
  for (auto &e: tree[v]){
    //cout << "e.to: " << e.to << endl;
    if (e.to == p) continue;
    dfs(e.to, v, d+e.cost);
  }
}
*/
int keta_sum(int num){
  int dig, sum = 0;
  while(num){
    dig = num % 10;
    sum = sum + dig;
    num = num / 10;
  }
  return sum;
}

ll binary_search(ll left_key, ll border, ll low, ll high) {
     // 配列 a の左端と右端
    ll mid = (low+high)/2;
    while (high > low+1) {
       mid = (low+high)/2;
        if (left_key*mid>border) high = mid;
        else if (left_key*mid<border) low = mid;
        else {
          mid =mid-1;
          break;
        }
    }
    return mid;
}

bool IsPrime(ll a){
  ll b = sqrt(a);
  b++;
  while(b-->=2){
    if (a%b==0) return false;
  }
  return true;
}

ll gcd(ll a, ll b){
  ll tmp;
  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }

  ll r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(void){
  ll N, M, A, B, C, D, K,W, H, Q, X, Y;
  ll ans;
  string S, T;
  cin >> N;
  if (N == 3 || N==5||N==7) cout << "YES" <<endl;
  else cout << "NO" << endl;


}
