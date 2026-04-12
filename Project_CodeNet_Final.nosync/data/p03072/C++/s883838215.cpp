#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int N;
int H[200];

int C = 0;
int ans = 0;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> H[i];
	}

	for (int i = 0; i < N; i++)
	{
		if (C <= H[i])
		{
			C = H[i];
			ans++;
		}
	}

	cout << ans << endl;
}