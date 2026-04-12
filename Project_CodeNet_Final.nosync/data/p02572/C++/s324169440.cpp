#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1e9+7;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

long long mod(long long val, long long m) {
  long long res = val % m;
  if (res < 0) res += m;
  return res;
}


typedef pair<ll, ll> pll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i=0; i<N; i++) cin >> A[i];
    vector<ll> s(N+1);
    for (int i=0; i<N; i++){
        s[i+1] = (s[i] + A[i]) % MOD;
    }
    
    long long ans = 0;
    for (int i=0; i<N-1; i++){
        // cout << A[i] << " " << (s[N] - s[i+1])<< (A[i] * (s[N] - s[i])) << endl;
        ans += ((A[i]% MOD * mod(((s[N]%MOD) - (s[i+1]%MOD)), MOD)) % MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}
