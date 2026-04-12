#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    ll ans = 0;
    for(int i = k+1; i <= n; i++){
        int ab = n/i;
        ans += ab*(i-k);
        ans += max((n - ab*i)-(k-1), 0);
    }
  if(k == 0) ans -= n;
    cout << ans << endl;
}

