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

int n, k;
string s;

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

int C(int a, int b)
{
	int res = 1;
	for (int i = a; i > a - b; i -- ) res = res * i;
	for (int i = 1; i <= b; i ++ ) res = res / i;
	return res;
}

int main()
{
	cin >> s >> k;
	n = s.size();
	
	int res = 0;
	for (int i = 1; i < n; i ++ )
		if (i >= k)
			res += C(i - 1, k - 1) * qp(9, k);
	
	vector<int> num;
	for (int i = 0; i < n; i ++ ) num.PB(s[i] - '0');
	
	// cout << res << endl;
	
	int last = 0;
	for (int i = 0; i < n; i ++ )
	{
		int x = num[i];
		
		if (x)
		{
			if (i) res += C(n - i - 1, k - last) * qp(9, k - last);
			last ++ ;
			res += (x - 1) * C(n - i - 1, k - last) * qp(9, k - last);
		}
		
		// cout << res << endl;
		
		if (last == k)
		{
			res ++ ;
			break;
		}
	}
	
	cout << res << endl;
	return 0;
}