#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <stack>
#define REP(i, n) for(int i=0; i<n; i++)
#define REPR(i, n) for(int i=n; i>0; i--)
#define FOR(i, m, n) for(int i=m; i<n; i++)
#define FORR(i, m, n) for(int i=m; i>=n; i--)
#define INF 1999999999
#define ll long long
#define VSORT(v) sort(v.begin(), v.end())
#define pb(a) push_back(a)
using namespace std;

#ifdef INPUT
stringstream input(R"(
5
3
3
1
1
5
)");
#define cin input
#endif

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	REP(i,n)
		cin >> a[i];
	sort(a.begin(), a.end());

	int p, q, ap, aq;
	p = a[0];
	q = a[n-1];
	a.pop_back();
	a.erase(a.begin());
	ll mx = q-p;

	if(n>2)
	{
		REP(i, n-2)
		{
			ap = a[0];
			aq = a[n-3-i];
			if(max(abs(ap-p), abs(ap-q)) > max(abs(aq-p), abs(aq-q)))
			{
				if(abs(ap-p)<abs(ap-q))
				{
					mx += abs(ap-q);
					q = ap;
				}
				else
				{
					mx += abs(ap-p);
					p = ap;
				}
				a.erase(a.begin());	
			}
			else
			{
				if(abs(aq-p)<abs(aq-q))
				{
					mx += abs(aq-q);
					q = aq;
				}
				else
				{
					mx += abs(aq-p);
					p = aq;
				}
				a.pop_back();
			}
		}
	}
	cout << mx << endl;
}