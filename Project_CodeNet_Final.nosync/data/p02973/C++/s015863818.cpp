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
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int n; cin >> n;
	deque<int> q;
	while (n--)
	{
		int a; cin >> a;
		int it = lower_bound(all(q), a) - q.begin();
		if (it == 0)q.push_front(a);
		else q[it - 1] = a;
	}
	cout << q.size() << endl;
}