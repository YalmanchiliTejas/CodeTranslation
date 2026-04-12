#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int n, m;
int a[N], q[N];

int get(int x)
{
	q[m] = -0x3f3f3f3f;
	int l = 0, r = m;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (q[mid] < x) r = mid;
		else l = mid + 1; 
	}
	return r == m ? -1 : r;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	
	for (int i = 1; i <= n; i ++ )
	{
		int t = get(a[i]);
		if (t == -1) q[m ++ ] = a[i];
		else q[t] = a[i];
	}
	
	printf("%d\n", m);
	return 0;
}