#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int n;
char s[N], t[N];
char ani[] = {'S', 'W'};

bool check(int st, int l, int r)
{
	if (st == 'S' && s[1] == 'o' && l != r) return false;
	else if (st == 'S' && s[1] == 'x' && l == r) return false;
	else if (st == 'W' && s[1] == 'o' && l == r) return false;
	else if (st == 'W' && s[1] == 'x' && l != r) return false;
	
	t[0] = l, t[1] = st, t[2] = r;
	for (int i = 2; i <= n; i ++ )
		if (t[i] == 'S')
		{
			if (s[i] == 'x') t[i + 1] = t[i - 1] == 'W' ? 'S' : 'W';
			else t[i + 1] = t[i - 1];
		}
		else
		{
			if (s[i] == 'o') t[i + 1] = t[i - 1] == 'W' ? 'S' : 'W';
			else t[i + 1] = t[i - 1];
		}
		
	return t[0] == t[n] && t[n + 1] == t[1];
}

int main()
{
	scanf("%d%s", &n, s + 1);
	
	for (int i = 0; i < 2; i ++ )
		for (int j = 0; j < 2; j ++ )
			for (int k = 0; k < 2; k ++ )
				if (check(ani[i], ani[j], ani[k]))
				{
					t[n + 1] = '\0';
					puts(t + 1);
					return 0;
				}
	
	puts("-1");
	return 0;
}