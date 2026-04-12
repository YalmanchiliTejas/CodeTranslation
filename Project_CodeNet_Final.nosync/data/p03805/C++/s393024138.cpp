#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef long long int ll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)

const ll MOD = 1000000007;

using namespace std;
vector<int> e[8];
int n = 0;
int N, M;

void search(int v, vector<int> r)
{
	r.push_back(v);
	if (r.size() == N)
	{
		n++;
		return;
	}
	REP(i, e[v].size())
	{
		bool contain = false;
		REP(j, r.size())
		{
			if (e[v][i] == r[j])
			{
				contain = true;
				break;
			}
		}

		if (contain) continue;
		search(e[v][i], r);
	}
	return;
}

int main()
{
	cin >> N >> M;
	REP(i, M)
	{
		int a, b;
		cin >> a >> b;
		e[a - 1].push_back(b - 1);
		e[b - 1].push_back(a - 1);
	}

	vector<int> r;
	search(0, r);

	cout << n << endl;
	return 0;
}