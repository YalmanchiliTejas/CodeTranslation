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

bool check(int u, int l, int r)
{
	t[0] = ani[l], t[1] = ani[u], t[2] = ani[r];
	if (t[1] == 'S' && s[1] == 'o' && t[0] != t[2]) return false;
	if (t[1] == 'S' && s[1] == 'x' && t[0] == t[2]) return false;
	if (t[1] == 'W' && s[1] == 'x' && t[0] != t[2]) return false;
	if (t[1] == 'W' && s[1] == 'o' && t[0] == t[2]) return false;
	
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
	
	return t[0] == t[n] && t[n + 1] == t[1];
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