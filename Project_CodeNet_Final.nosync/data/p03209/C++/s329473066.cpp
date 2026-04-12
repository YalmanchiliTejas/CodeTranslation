#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define repi(i, a, b) for(ll i = ll(a); i < ll(b); ++i)
#define rep(i, n) repi(i, 0, n)
#define rerepi(i, a, b) for(ll i = ll(a)-1; i >= b; --i)
#define rerep(i, n) rerepi(i, n, 0)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <class T>ostream &operator<<(ostream &o,const vector<T>&v) {o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

const long long INF = 1LL << 60;

// 降順ソート
// std::sort(data.begin(),data.end(),std::greater<ll>());
// 昇順ソート
// std::sort(data.begin(),data.end());

// vector型の「data」に xが存在するかを、True or Falseで返す
// vector_finder(data, x)
bool vector_finder(std::vector<ll> vec, ll number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return true;
  }
  else { // 発見できなかったとき
    return false;
  }
}

// ここから開始だよ！
ll N, X;
std::vector<ll> ALL;
std::vector<ll> NIKU;

ll run(ll N, ll X) {
  ll ans = 0;
  
  if (N == 0) {
    return 1;
  }
  
  if (X >= 1) {
    X--;
  }
  
  if (X >= 1) {
    if (ALL[N-1] <= X) {
      X -= ALL[N-1];
      ans += NIKU[N-1];
    } else {
      ans += run(N-1, X);
      X = 0;
    }
  }
  
  if (X >= 1) {
    X--;
    ans++;
  }
  
  if (X >= 1) {
    if (ALL[N-1] <= X) {
      X -= ALL[N-1];
      ans += NIKU[N-1];
    } else {
      ans += run(N-1, X);
      X = 0;
    }
  }
  
  if (X >= 1) {
    X--;
  }
  
  return ans;
}

int main() {
	// 呪文エリア
	cin.tie(0);
	ios::sync_with_stdio(false);
	// 詠唱完了
	
	cin >> N >> X;
	ALL.push_back(1);
  NIKU.push_back(1);
	
	repi(i, 1, N+1){
		ALL.push_back((ALL[i-1] * 2) + 3);
    NIKU.push_back((NIKU[i-1] * 2) + 1);
	}
	
	cout << run(N, X) << endl;
	
	return 0;
}
