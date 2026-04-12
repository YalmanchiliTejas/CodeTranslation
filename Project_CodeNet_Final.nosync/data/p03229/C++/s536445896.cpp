#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>
#include <queue>
#include <cmath>
#include <cmath>
#include <string>
#include <deque>
using namespace std;

typedef long long ll;

ll ABS(ll a, ll b)
{
	if (a - b >= 0)return a - b;
	else return b - a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ll ans = 0;
	deque<ll>dq(n);
	deque<ll>dq2(n);
	for (int i = 0; i < n; i++) {
		cin >> dq[i];
		dq2[i] = dq[i];
	}
		
	sort(dq.begin(), dq.end());
	sort(dq2.begin(), dq2.end());
	deque<ll>a;
	deque<ll>b;
	a.push_back(dq[0]);
	dq.pop_front();
	while (!dq.empty()) {
		a.push_front(dq.back());//가장큰거 
		dq.pop_back();
		if (dq.empty())break;
		a.push_back(dq.back());
		dq.pop_back();
		if (dq.empty())break;
		a.push_front(dq.front());
		dq.pop_front();
		if (dq.empty())break;
		a.push_back(dq.front());
		dq.pop_front();
		if (dq.empty())break;
		
	}
	int t = a.size();
	for (int i = 1; i < t; i++)
		ans += ABS(a[i],a[i - 1]);
	b.push_back(dq2[dq2.size() - 1]);
	dq2.pop_back();
	while (!dq2.empty())
	{
		b.push_front(dq2.front());
		dq2.pop_front();
		if (dq2.empty())break;
		b.push_back(dq2.front());
		dq2.pop_front();
		if (dq2.empty())break;
		b.push_front(dq2.back());
		dq2.pop_back();
		if (dq2.empty())break;
		b.push_back(dq2.back());
		dq2.pop_back();
		if (dq2.empty())break;

	}
	int p = b.size();
	ll ans2 = 0;
	for (int i = 1; i < p; i++)
		ans2 += ABS(b[i], b[i - 1]);
	cout << max(ans, ans2);
}