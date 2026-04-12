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

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

const ll INF = 1LL << 60;

int H,W;

void dfs(vector<string> &s, vector<vector<bool>> &seen, int h, int w){
  if(h+1 != H && s[h+1][w] == '#' && w+1 != W && s[h][w+1] == '#'){
    return;// 分岐があったらダメ
  }
  seen[h][w] = true;
  //printf("h:%d w:%d s[h+1][w]:%c\n",h, w, s[h+1][w] );

  if(h+1 != H && s[h+1][w] == '#'){
    dfs(s, seen, h+1, w);
  }
  if(w+1 != W && s[h][w+1] == '#'){
    dfs(s, seen, h, w+1);
  }
}

int main(){
  cin >> H >> W;
  vector<string> s(H);
  rep(h, H) cin >> s[h];

  vector<vector<bool>> seen(H,vector<bool>(W,false));

  dfs(s, seen, 0, 0);

  bool ok = true;
  if(!seen[H-1][W-1]) ok = false;
  rep(i, H) rep(j, W){
    if(!seen[i][j] && s[i][j] == '#') ok = false;
  }

  if(ok) std::cout << "Possible" << '\n';
  else std::cout << "Impossible" << '\n';
}
