#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double lf;
typedef long double Lf;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;

#define TRACE(x) cerr << #x << "  " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define _ << " " <<

#define fi first
#define sec second
#define mp make_pair

const int MAXN = 200100;
const int offset = (1 << 18);

struct tournament {
  ll p[offset * 2], prop[offset * 2];

  void send_prop(int cvor) {
    FOR(i, cvor * 2, cvor * 2 + 2) {
      prop[i] += prop[cvor];
      p[i] += prop[cvor];
    }
    prop[cvor] = 0;
  }

  void update(int cvor, int l, int r, int a, int b, ll x) {
    if (l > b || r < a) return;
    if (l >= a && r <= b) {
      prop[cvor] += x;
      p[cvor] += x;
      return;
    }

    send_prop(cvor);

    int mid = (l + r) / 2;

    update(cvor * 2, l, mid, a, b, x);
    update(cvor * 2 + 1, mid + 1, r, a, b, x);

    p[cvor] = max(p[cvor * 2], p[cvor * 2 + 1]);
  }

  ll get(int cvor, int l, int r, int a, int b) {
    if (l > b || r < a) return -(1LL << 50);
    if (l >= a && r <= b) return p[cvor];
    
    send_prop(cvor);

    int mid = (l + r) / 2;

    ll x = get(cvor * 2, l, mid, a, b);
    ll y = get(cvor * 2 + 1, mid + 1, r, a, b);
    return max(x, y);
  }

  void print() {
    FOR(i, 1, offset * 2) {
      TRACE(i _ p[i] _ prop[i]);
    }
  }
};

tournament T;

int n, m;

int L[MAXN], R[MAXN];
ll C[MAXN];

vector <int> v[MAXN];
ll dp[MAXN];

int main() {
  scanf("%d %d",&n,&m);
  REP(i, m) {
    scanf("%d %d %lld",&L[i],&R[i],&C[i]);
    T.update(1, 0, offset - 1, L[i], n + 1, -C[i]);
    T.update(1, 0, offset - 1, R[i] + 1, n + 1, C[i]);
    v[R[i] + 1].push_back(i);
  }

  //T.print();
  FOR(i, 1, n + 2) {
    for (auto x : v[i]) {
      T.update(1, 0, offset - 1, L[x], n + 1, C[x]);
      T.update(1, 0, offset - 1, R[x] + 1, n + 1, -C[x]);
    }
    //TRACE(i _ T.get(1, 0, offset - 1, 0, i - 1) _ T.get(1, 0, offset - 1, i, i));
    dp[i] = T.get(1, 0, offset - 1, 0, i - 1) - T.get(1, 0, offset - 1, i, i);
    T.update(1, 0, offset - 1, i, i, dp[i]);
  }

  cout << dp[n + 1] << endl;
  return 0;
}
