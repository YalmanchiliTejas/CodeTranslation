//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


// CHECK THE LIMITS
typedef long long ll;

const int MOD = 1000000007;
const ll INFLL = 1e18;
const int INF = 1e9;
const int NMAX = 1000001;

int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
} 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	string s;
	int k;
	cin >> s >> k;

	ll ans = 0;
	int n = (int) s.length();
	for(int i = 0; i< n; i++)
	{
		for(int cif1 = 1; cif1 <= 9; ++cif1)
		{
			if(i == 0 && cif1 > (s[0] - '0'))
				continue;
			bool less1 = i || cif1 < s[0] - '0';
			if(k == 1)
				ans++;
			else
			{
				for(int j = i+1; j< n; ++j)
				{
					for(int cif2 = 1; cif2 <= 9; ++cif2)
					{
						if(!less1 && cif2 > s[j] - '0')
						{
							continue;
						}

						bool less2 = less1 || cif2 < s[j] - '0';

						if(k == 2)
							ans++;
						else
						{
							for(int k = j+1; k < n; ++k)
							{
								for(int cif3 = 1; cif3 <= 9; ++cif3)
								{
									if(!less2 && cif3 > s[k] - '0')
										continue;
									ans++;
								}
								if(s[k] > '0')
									less2 = 1;
							}
						}
					}
					if(s[j] > '0')
						less1 = 1;
				}
			}
		}
	}
	cout << ans;

    return 0;
}