#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for (int i = 0; i < (int)(j); i++)
#define repeat(i, j, k) for (int i = (j); i < (int)(k); i++)

template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &a : v) is >> a;
    return is;
}

const ll MOD = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, S; cin >> N >> S;
    vector<int> A(N); cin >> A;
    ll ans = 0;        
    
    vector<int> sum(S+1);
    rep(r, N) {
      sum[0] = r + 1;
      for(int s = sum.size() - 1; s >= 0; s--) {	
	if(s + A[r] <= S) sum[s + A[r]] = (sum[s + A[r]] + sum[s]) % MOD;	
      }
      ans = (ans + sum[S]) % MOD;
    }      
    
    cout << ans << endl;
    return 0;
}
