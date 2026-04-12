#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;

vector<ll> cnt;
vector<ll> pat;

ll rec(ll N,ll X){
  if(X==0) return 0;
  if(N==0&&X==1) return 1;
  X--;
  if (X <= cnt[N - 1]) return rec(N - 1, X);
  X-=cnt[N-1];
  if (X == 1) return pat[N-1]+1LL;
  X--;
  if (X <= cnt[N - 1]) return pat[N-1] + rec(N - 1, X) + 1;
  return pat[N];
}

int main() {
    ll N,X;
    cin >> N >> X;
    cnt.resize(N+1); cnt[0] = 1;
    pat.resize(N+1); pat[0] = 1;
    rep(i,N){
        cnt[i + 1] = 3LL + 2 * cnt[i];
        pat[i + 1] = 1LL + 2 * pat[i];
    }
    cout << (ll)rec(N,X) << endl;
}