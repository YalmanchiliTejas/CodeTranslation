#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define debug(x) cerr << #x << " = " << (x) << endl;
template<typename T>
ostream& operator<<(ostream& o, vector<T>& v) {
    for (auto& x : v) o << x << ' ';
    return o;
}

int n;
int arr[3030];
ll memo[3030][3030];
ll dp(int i, int j) {
  ll &res = memo[i][j];
  if (res != -1) return res;
  if (i > j) return res = 0;
  res = max(arr[i] - dp(i+1, j), arr[j] - dp(i, j-1));
  return res;
}

int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    memset(memo, -1, sizeof memo);
    cout << dp(0, n-1) << endl;
}
