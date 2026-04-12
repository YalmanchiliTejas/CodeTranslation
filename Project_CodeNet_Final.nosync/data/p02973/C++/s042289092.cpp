#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
#define MAXN 100000

vector <int> sequence;
int n, ldslen;
multiset<int> decrease;

void find_lds()
{
	for (int i = 0; i<n; i++)
	{
		auto it = decrease.lower_bound(sequence[i]);
		if (it == decrease.begin())
			decrease.insert(sequence[i]);
		else
		{
			--it;
			decrease.erase(it);
			decrease.insert(sequence[i]);
		}
	}
	ldslen = decrease.size();
}

int main()
{
	usecppio
	cin >> n;
	sequence.resize(n);
	for (int i = 0; i<n ;i++)
		cin >> sequence[i];
	find_lds();
	cout << ldslen;
}