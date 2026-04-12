#define  _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <iomanip>
#include <fstream>
#include <string>
#include <climits>

typedef long long ll;
typedef long double ld;

#define fi(n) for(int i = 0; i < (n); i++)
#define FOR(i, k, n) for(int i = (k); i < (n); i++)
#define RFOR(i, k, n) for(int i = (k); i >= (n); i--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const int INF = INT_MAX;
const int mod = 1e9 + 7;
const long long LINF = LLONG_MAX;

using namespace std;

int main()
{
	int n;
	cin >> n;
	queue<pair<ll, int>> que;
	set<int> mbcu;
	fi(n)
	{
		ll x;
		cin >> x;
		que.push({ x, i });
		mbcu.insert(i);
	}
	ll answ = 0, pl = 0;
	vector<ll> m(n);
	
	while (!que.empty() && !mbcu.empty())
	{
		ll v = que.front().first;
		int i = que.front().second;
		que.pop();
		v += answ - m[i];
		
		if (v >= n)
		{
			ll newansw = v / n;
			v = v % n;
			answ += newansw;
			m[i] = answ;
			mbcu.insert(i);
			que.push({ v, i });
		}
		else
		{
			mbcu.erase(i);
			m[i] = answ;
			que.push({ v, i });
		}
	}

	cout << answ << endl;

	return 0;
}