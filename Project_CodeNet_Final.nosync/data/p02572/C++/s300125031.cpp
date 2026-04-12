#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef pair<int,int> pii;
const int mod = (int) 1000000007;
const int inf = (int) 2e18;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cout << fixed << setprecision(9);
	#ifdef LOCAL_DEFINE
		freopen("in.txt", "rt", stdin);
	#endif
  // code
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i=0; i<n; i++) cin >> arr[i];
  vector<int> suffix(n, 0);
  suffix[n-1] = arr[n-1];
  for(int i=n-2; i>=0; i--) suffix[i] = suffix[i+1] + arr[i];
  int res = 0;
  for(int i=0; i<n-1; i++){
    res = (res + ((arr[i] % mod) * (suffix[i+1] % mod)) % mod) % mod;
  }
  cout << res << "\n";
  return 0;
}
