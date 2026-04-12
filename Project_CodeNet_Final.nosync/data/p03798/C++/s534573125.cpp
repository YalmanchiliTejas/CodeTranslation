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

int n;
char s[N], t[N];
char ani[] = {'S', 'W'};

bool check(int st, int l, int r)
{
	int a = ani[st], b = ani[l], c = ani[r];
	if (a == 'S' && s[1] == 'o' && b != c) return false;
	if (a == 'S' && s[1] == 'x' && b == c) return false;
	if (a == 'W' && s[1] == 'x' && b != c) return false;
	if (a == 'W' && s[1] == 'o' && b == c) return false;
	
	t[1] = a, t[0] = b, t[2] = c;
	for (int i = 2; i <= n; i ++ )
		if (t[i] == 'S')
		{
			if (s[i] == 'o') t[i + 1] = t[i - 1];
			else t[i + 1] = t[i - 1] == 'S' ? 'W' : 'S';
		}
		else
		{
			if (s[i] == 'x') t[i + 1] = t[i - 1];
			else t[i + 1] = t[i - 1] == 'S' ? 'W' : 'S';
		}
	
	return t[0] == t[n] && t[1] == t[n + 1];
}

int main()
{
	scanf("%d%s", &n, s + 1);
	
	for (int i = 0; i < 2; i ++ )
		for (int j = 0; j < 2; j ++ )
			for (int k = 0; k < 2; k ++ )
				if (check(i, j, k))
				{
					t[n + 1] = '\0';
					puts(t + 1);
					return 0;
				}
	
	puts("-1");
    return 0;
}