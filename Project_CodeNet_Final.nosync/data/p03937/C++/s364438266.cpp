#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define MOD (1000000007)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll gcd(ll a, ll b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}

const ll INF = 1LL << 60;

int H,W;
bool seen[8][8];

const int dh[2] = {1,0};
const int dw[2] = {0,1};

void dfs(vector<string> &G, int h, int w){
  seen[h][w] = true;
  if(h+1 < H && G[h+1][w] == '#' && w+1 < W && G[h][w+1] == '#') return;
  rep(dir, 2){
    int nh = h + dh[dir];
    int nw = w + dw[dir];
    if(nh == -1 || nh == H || nw == -1 || nw == W ) continue;
    if(G[nh][nw] == '#') dfs(G, nh, nw);
  }
}

int main(){
  cin >> H >> W;
  vector<string> G(H); rep(i, H) cin >> G[i];

  memset(seen, false, sizeof(seen));
  dfs(G, 0, 0);

  bool ok = true;
  rep(h, H) rep(w, W){
    if(G[h][w] == '#' && !seen[h][w]) ok = false;
  }

  std::cout << (ok ? "Possible" : "Impossible") << '\n';

}
