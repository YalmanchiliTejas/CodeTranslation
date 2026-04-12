#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <cmath>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define PI 3.14159265
using namespace std;
const int MAX = 1e5 + 10;
const ll MOD = 1e9 + 7;
int N, M, K, Q;
deque<int> dq;

int main()
{
	int i, j, k;
	scanf("%d", &N);
	int x;
	for (i = 1; i <= N; ++i) {
		scanf("%d", &x);
		if (i % 2 == 1) dq.push_back(x);
		else dq.push_front(x);
	}
	vector<int> vt;
	while (!dq.empty()) {
		vt.push_back(dq.front());
		dq.pop_front();
	}
	if (N % 2 == 1) reverse(vt.begin(), vt.end());
	for (i = 0; i < vt.size(); ++i) printf("%d ", vt[i]);

}
