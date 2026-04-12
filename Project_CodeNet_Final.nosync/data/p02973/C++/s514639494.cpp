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
	deque<int> b;
	rep(i, 0, n - 1)
	{
		int a; cin >> a;
		int pos = lower_bound(all(b), a) - b.begin();
		if (pos == 0)b.push_front(a);
		else b[pos - 1] = a;
	}
	cout << b.size() << endl;
}