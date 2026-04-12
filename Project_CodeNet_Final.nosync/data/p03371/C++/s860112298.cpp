#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vecs vector<string>
#define vec2ll vector<vector<long long>>
#define vecbool vector<bool>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)

int main()
{
  ll a, b, c, x, y, p;
  cin >> a >> b >> c >> x >> y;
  if (a + b <= 2 * c)
	p = a * x + b * y;
  else if (a >= 2 * c && b >= 2 * c)
	p = max(x, y) * 2 * c;
  else if (a >= 2 * c)
	p = 2 * c * x + max(y-x, (ll)0) * b;
  else if (b >= 2 * c)
	p = max(x-y, (ll)0) * a + 2 * c * y;
  else if (a + b >= 2 * c)
	p = min(x, y) * 2 * c + max(x - min(x, y), (ll)0) * a + max(y - min(x, y), (ll)0) * b;
  
  cout << p << endl;
}
