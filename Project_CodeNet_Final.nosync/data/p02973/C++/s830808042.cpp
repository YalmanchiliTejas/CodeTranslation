#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n){
    cin >> a[n-1-i];
  }
  vector<int> dp(n, INF);
	for (int i=0; i<n; ++i) {
		*upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
	}
  int ans=lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
    cout << ans << endl;
  return 0;
}
