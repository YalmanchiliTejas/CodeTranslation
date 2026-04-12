#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>
#include <cfloat>
#include <map>

#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define LOWER_BOUND(v,a) (lower_bound((v).begin(), (v).end(), (a)))
#define UPPER_BOUND(v,a) (upper_bound((v).begin(), (v).end(), (a)))
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
using namespace std;


signed main()
{
	int N, K;
	cin >> N >> K;

	if (K == 0)
	{
		cout << N * N << endl;
		return 0;
	}

	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		int l = K - 1;
		int ll = K % i;
		if (ll > 0)
		{
			l += (i - ll);
			sum += MAX(0, (i - MAX(ll, K)));
		}

		int r = N + 1;
		int rr = N % i;
		if (rr < i - 1)
		{
			r -= (rr + 1);
			sum += MAX(0, rr - K + 1);
		}

		int a = MAX(0, i - K);
		int s = ((r - l - 1) / i) * a;
		sum += s;
	}

	cout << sum << endl;
}





