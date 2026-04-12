#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define f first
#define s second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
#define FILL(a, b) memset(a, b, sizeof a)
#define ALL(a) a.begin(), a.end()
#define SZ(a) ((int)a.size())

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1LL * INF*INF;
const int MAX = 1e5;
const double PI = acos(-1.);
const double EPS = 1e-8;

int n;
VI x(100005);

LL res()
{
	int pos = n / 2;
	if (n % 2 == 0)
	{
		pos--;
	}
	multiset<int> s;
	FOR(I, 0, n)
	{
		s.insert(x[I]);
	}
	x[pos] = *s.begin();
	s.erase(s.begin());
	for(int i = 1;i + pos < n;++i)
	{
		if (i % 2)
		{
			x[pos+i] = *(--s.end());
			s.erase((--s.end()));
			if (s.empty())
			{
				break;
			}
			x[pos-i] = *(--s.end());
			s.erase((--s.end()));
		}
		else
		{
			x[pos+i] = *s.begin();
			s.erase(s.begin());
			if (s.empty())
			{
				break;
			}
			x[pos-i] = *s.begin();
			s.erase(s.begin());
		}
	}
	LL ans = 0;
	FOR(i, 1, n)
	{
		ans += abs(x[i] - x[i-1]);
	}
	return ans;
}

LL res2()
{
	int pos = n / 2;
	if (n % 2 == 0)
	{
		pos--;
	}
	multiset<int> s;
	FOR(I, 0, n)
	{
		s.insert(x[I]);
	}
	x[pos] = *(--s.end());
	s.erase(--s.end());
	for(int i = 1;i + pos < n;++i)
	{
		if (i % 2 == 0)
		{
			x[pos+i] = *(--s.end());
			s.erase((--s.end()));
			if (s.empty())
			{
				break;
			}
			x[pos-i] = *(--s.end());
			s.erase((--s.end()));
		}
		else
		{
			x[pos+i] = *s.begin();
			s.erase(s.begin());
			if (s.empty())
			{
				break;
			}
			x[pos-i] = *s.begin();
			s.erase(s.begin());
		}
	}
	LL ans = 0;
	FOR(i, 1, n)
	{
		ans += abs(x[i] - x[i-1]);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> x[i];
	}

	LL ans = res();
	cout << max(ans, res2());

	return 0;
}











