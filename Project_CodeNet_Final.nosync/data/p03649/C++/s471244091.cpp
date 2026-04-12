#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <cmath>
#include <set>
#include <list>
#include <deque>
#include <map>
#include <queue>
#include <fstream>
#include <cassert>
#include <cmath>
#include <sstream>
#include <time.h>
#include <iomanip>
#include <complex>
#include <unordered_map>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<unsigned, unsigned> ii;
typedef pair<double,double> dd;
typedef pair<char,char> cc;
typedef vector<ii> vii;
typedef long long ll;
typedef pair<ll, ll> l4;
typedef long double ld;

typedef unsigned ui;
#define mp make_pair
#define pb push_back

const int maxn = 50;
int n;
ll a[maxn];

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", a+i);
  ll ans = 0;
  bool done = false;
  while (!done)
    {
      done = true;
      for (int i = 0; i < n; ++i)
	if (a[i] >= n)
	  {
	    done = false;
	    ll tmp = a[i]/n;
	    ans += tmp;
	    a[i] %= n;
	    for (int j = 0; j < n; ++j)
	      if (i != j)
		a[j] += tmp;
	  }
    }
  printf("%lld\n", ans);
}
