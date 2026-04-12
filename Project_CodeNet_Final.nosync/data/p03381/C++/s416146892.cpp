// V solo
#include <bits/stdc++.h>

#define forn(i, a, b) for (int i = a; i <= b; ++i)
#define forr(i, a, b) for (int i = a; i >= b; --i)

using namespace std;

const int N = (int)3e5 + 1;
const int INF = 1e9 + 7;

typedef long long ll;
typedef long double ld;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

int n, ans[N];
pii a[N];
int main (){
  scanf ("%d", &n);
  forn (i, 1, n){
    scanf ("%d", &a[i].first);
    a[i].second = i;
  }
  sort (a + 1, a + n + 1);
  int l = n / 2;
  forn (i, 1, n){
    if (i <= l){
      ans[a[i].second] = a[l + 1].first;
    } else {
      ans[a[i].second] = a[l].first;
    }
  }
  forn (i, 1, n){
    printf ("%d\n", ans[i]);
  }
  return 0;
}
