#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

typedef struct _data {
	int x;
	int y;
} data;

int  main()
{
	char s[3];
	cin >> s;
	int ans = 0;
	rep(i, 2)
	{
		if (s[i] != s[i+1])
			ans = 1;
	}
	if (ans == 1) 
		cout << "Yes\n";
	else
		cout << "No\n";
	return (0);
}
