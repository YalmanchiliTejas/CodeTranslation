#pragma region
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	multiset<int> s;
	int n; cin >> n;
	while (n--)
	{
		int a; cin >> a;
		auto it = s.lower_bound(a);
		if (it == s.begin())s.insert(a);
		else
		{
			--it;
			s.erase(it);
			s.insert(a);
		}
	}
	cout << s.size() << endl;
}