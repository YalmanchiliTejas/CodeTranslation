#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector
#define pb push_back
#define INF 1000000007

int main(void)
{
  int n;
  cin >> n;
  vec<int> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n) a[i] = INF - 1 - a[i];

  vec<int> s(n, INF);
  vec<int> id(n);
  rep(i, n) {
    id[i] = distance(s.begin(), upper_bound(s.begin(), s.end(), a[i]));
    s[id[i]] = a[i];
  }
  int m = *max_element(id.begin(), id.end());
  cout << m + 1 << endl;
  return 0;
}

