#include <bits/stdc++.h>
using namespace std; inline void fileio(const char* in, const char* out) { freopen(in, "r", stdin); freopen(out, "w", stdout); } 
#define TD typedef
#define forx(i,n) for(int i = 0; i < (n); ++i)
TD long long ll; TD long double ld; TD pair<int,int> pii; TD pair<ll, ll> pll; TD vector<int> VI; TD vector<bool> VB; TD vector<ll> VL;
const char nl = '\n'; const int INF = 0x3f3f3f3f; const ll LINF = 0x3f3f3f3f3f3f3f3fll; const ld EPS = 1e-9, PI = acos(-1);
#define ff first
#define ss second

const int N = 3005;
VL nums;

static bool is_set[N][N];
static ll mem[N][N];
//return X-Y for [left, right)
ll solve(int left, int right) {
  if (left == right) return 0; //no choice
  if (!is_set[left][right]) {
    mem[left][right] = max(
        nums[right-1] - solve(left, right-1)   ,
        nums[left] -    solve(left+1, right));
    is_set[left][right] = true;
  }
  return mem[left][right]; 
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // Emily <3
  int n;
  cin >> n;
  nums.resize(n);
  memset(is_set, 0, sizeof(is_set));
  forx(i,n) cin >> nums[i];
  cout << solve(0, n) << nl;
  
  cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << nl;
  return 0;
}

