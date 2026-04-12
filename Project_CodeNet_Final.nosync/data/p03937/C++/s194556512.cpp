#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, j, n) for (ll i = j; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define INF (1000000000)
#define MOD (1000000007)
#define MAX (100000)
#define pii pair<int, int>

/////////////////////////////////////////////////////////

class XY{
public:
  ll x, y;
  XY() {x = y = 0;}
  XY(ll u, ll v) {x = u; y = v;}
};

template<typename T1, typename T2>
void chmin(T1 &a, T2 b) {if(a > b) a = b;}
template<typename T1, typename T2>
void chmax(T1 &a, T2 b) {if(a < b) a = b;}

template<typename T1, typename T2>
ll mypow(T1 a, T2 n){
  if(n == 0) return 1;
  if(n == 1) return a;
  if(n % 2) return a * mypow(a, n - 1);
  ll tmp = mypow(a, n / 2);
  return tmp * tmp;
}

template<typename T>
int BS(vector<T> V, int left, int right, T key){
  int mid = (left + right) / 2;
  if(V[mid] <= key) left = mid;
  else right = mid;
  if(right - mid == 1) return left;
  else return BS(V, left, right, key);
}

ll comb(ll n, ll r){
	ll res = 1;
  rep(i, 0, r){
    res *= n - i;
    res /= i + 1;
  }
  return res;
}

/////////////////////////////////////////////////////////

int DFS(vector<vector<char>> &A, int h, int w){
  if(h == A.size() - 1 && w == A[0].size() - 1) return 1;
  int res = 0;
  if(h < A.size() - 1) if(A[h + 1][w] == '#') if(DFS(A, h + 1, w)) res = 1;
  if(w < A[0].size() - 1) if(A[h][w + 1] == '#') if(DFS(A, h, w + 1)) res = 1;
  return res;
}

void Main() {
  int H, W; cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  int cnt = 0;
  rep(i, 0, H) rep(j, 0, W) {
    cin >> A[i][j];
    if(A[i][j] == '#') cnt++;
  }
  string res;
  if(cnt == H + W - 1 && DFS(A, 0, 0)) res = "Possible";
  else res = "Impossible";
  cout << res << endl;
}

/////////////////////////////////////////////////////////

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << std::fixed << std::setprecision(15);

  Main();
}
