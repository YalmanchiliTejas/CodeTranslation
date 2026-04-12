#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;
#define MAXN 200200
#define INF 1001001001001001001LL

int n, m, nn = 1;
int l[MAXN], r[MAXN];
ll a[MAXN], pre;
vector<int> v[MAXN];
ll t[MAXN * 4], prop[MAXN * 4];
ll reza = 0LL;

void propaj(int cv, int lo, int hi)
{
  if (lo < hi) {
    prop[cv * 2] += prop[cv];
    prop[cv * 2 + 1] += prop[cv];
  }
  t[cv] += prop[cv];
  prop[cv] = 0;
}

void add(int cv, int le, int ri, int lo, int hi, ll val)
{
  propaj(cv, lo, hi);
  if (le > ri || lo > hi || le > hi || ri < lo) return;

  if (lo >= le && hi <= ri) {
    prop[cv] += val;
    propaj(cv, lo, hi);
    return;
  }

  int mid = (lo + hi) / 2;

  add(cv * 2, le, ri, lo, mid, val);
  add(cv * 2 + 1, le, ri, mid + 1, hi, val);
  t[cv] = max(t[cv * 2], t[cv * 2 + 1]);
}

ll maks(int cv, int le, int ri, int lo, int hi)
{
  propaj(cv, lo, hi);
  if (le > ri || lo > hi || le > hi || ri < lo) return -INF;

  if (lo >= le && hi <= ri) {
    return t[cv];
  }

  int mid = (lo + hi) / 2;

  ll lc = maks(cv * 2, le, ri, lo, mid);
  ll rc = maks(cv * 2 + 1, le, ri, mid + 1, hi);
  t[cv] = max(lc, rc);
  return t[cv];
}

int main()
{
  scanf("%d%d", &n, &m);
  for (int n2 = n; n2; n2 /= 2) nn *= 2;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%lld", &l[i], &r[i], &a[i]);
    l[i]--; r[i]--;
    v[l[i]].pb(i);
    v[r[i] + 1].pb(-i - 1);
  }
  for (int i = 0; i < n; i++) {//cout<<maks(1, 0, nn - 1, 0, i - 1)<<endl;
    for (int j: v[i]) {
      if (j >= 0) {
        add(1, l[j], r[j], 0, nn - 1, -a[j]);
        pre += a[j];
      }
      else {
        j = -j - 1;
        add(1, l[j], r[j], 0, nn - 1, a[j]);
        pre -= a[j];
      }
    }

    ll ri = max(maks(1, 0, i - 1, 0, nn - 1) + pre, pre);
    //cout<<ri<<' '<<pre<<'.'<<maks(1, 0, i - 1, 0, nn - 1)<<endl;
    add(1, i, i, 0, nn - 1, ri);
    reza = max(reza, ri);
  }
  printf("%lld\n", reza);
  return 0;
}
