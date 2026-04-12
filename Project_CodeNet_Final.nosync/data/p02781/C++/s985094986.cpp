#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 110, M = 1010;

int n, m;
char s[N];

int C(int a, int b)
{
	int res = 1;
	for (int i = a; i > a - b; i -- ) res *= i;
	for (int i = 1; i <= b; i ++ ) res /= i;
	return res;
}

int qp(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int f(int n)
{
	if (!n) return 0;
	
	vector<int> nums;
	for (int i = n; i; i -- ) nums.PB(s[i] - '0');
	
	int res = 0;
	int last = 0;
	for (int i = n - 1; i >= 0; i -- )
	{
		int x = nums[i];
		if (x)
		{
			res += qp(9, m - last) * C(i, m - last);
			res += (x - 1) * qp(9, m - last - 1) * C(i, m - last - 1);
			last ++ ;
		}
		
		if (last == m)
		{
			res ++ ;
			break;
		}
		
		// if (!i) res ++ ;
	}
	
	return res;
}

int main()
{
	cin >> s + 1 >> m;
	n = strlen(s + 1);
	cout << f(n) << endl;
	return 0;
}