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

using namespace std;
typedef long long ll;
#define rep(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))
#define all(x) x.begin(),x.end()


int main()
{
	int n; cin >> n;
	int ans = 1;
	vector<int> b;
	int f; cin >> f;
	b.push_back(f);
	rep(i, 1, n - 1)
	{
		int a; cin >> a;
		if (b[0] >= a)b.insert(b.begin(), a);
		else
		{
			int pos = upper_bound(all(b), a - 1) - b.begin();
			b[pos - 1] = a;
		}
	}
	cout << b.size() << endl;
}