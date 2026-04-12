#include <bits/stdc++.h>

using namespace std;

static const int MAX_SIZE = 1 << 18;

typedef long long Int;

Int segMax[2 * MAX_SIZE - 1], segAdd[2 * MAX_SIZE - 1];

void add(int a, int b, Int x, int k = 0, int l = 0, int r = MAX_SIZE)
{
	if (r <= a || b <= l) return;
	
	if (a <= l && r <= b) {
		segAdd[k] += x;
		return;
	}
	
	add(a, b, x, k * 2 + 1, l, (l + r) / 2);
	add(a, b, x, k * 2 + 2, (l + r) / 2, r);

	segMax[k] = max(segMax[k * 2 + 1] + segAdd[k * 2 + 1], segMax[k * 2 + 2] + segAdd[k * 2 + 2]);
}

Int getMax(int a, int b, int k = 0, int l = 0, int r = MAX_SIZE)
{
	if (r <= a || b <= l) return (LLONG_MIN);
	
	if (a <= l && r <= b) return (segMax[k] + segAdd[k]);
	
	Int left = getMax(a, b, k * 2 + 1, l, (l + r) / 2);
	Int right = getMax(a, b, k * 2 + 2, (l + r) / 2, r);
	
	return (max(left, right) + segAdd[k]);
}

Int black[200001], white[200001];
int main()
{
  int n, m;
  
  scanf("%d %d", &n, &m);
  
  vector< pair<pair<int, int>, int> > v;
  
  long long tot = 0;
  for (int i = 0; i < m; i++) {
    int l, r, a;
    scanf("%d %d %d", &l, &r, &a);
    tot += a;
    v.push_back(make_pair(make_pair(r, l), a));
  }
  sort(v.begin(), v.end());
  int p = 0;
  long long black_max, white_max;
  black_max = white_max = 0;
  for (int i = 1; i <= n; i++) {
    black[i] = max(black_max, white_max);
    black_max = max(black_max, black[i]);
    while (p < m && v[p].first.first == i) {
      add(0, v[p].first.second, -v[p].second);
      p++;
    }
    white[i] = getMax(0, i);
    white_max = max(white_max, white[i]);
    add(i, i + 1, black[i]);
  }
  
  printf("%lld\n", tot + max(black_max, white_max));
  return 0;
}
