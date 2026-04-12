#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
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
#include <set>
#include <array>
#include <stdio.h>
#include <string.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define int long long
#define CONTAINS_VEC(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define ARY_REVERSE(v,a) (reverse((v), (v)+(a)))
#define REP(i, n) for (int (i)=0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
#define CONTAINS_SET(m, a) (m).find((a)) != m.end()
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }


int N;
int A[100001];



//---------- にぶたん[f,f,f,f,'t',t,t,t] ----------
bool isOK(int n)
{
	multiset<int, greater<int>> s;
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		int a = A[i];
		auto it = s.upper_bound(a);
		if (it == s.end())
		{
			s.insert(a);
			count++;
		}
		else
		{
			s.erase(it);
			s.insert(a);
		}
	}

	return count <= n;
}

int binary_search(int n)
{
	int left = -1;
	int right = n;
	while (right - left > 1)
	{
		int mid = left + (right - left) / 2;
		if (isOK(mid))
			right = mid;
		else
			left = mid;
	}
	return right;
}


signed main()
{
	cin >> N;
	REP(i, N) cin >> A[i];

	int ans = binary_search(100001);

	cout << ans << endl;
}

