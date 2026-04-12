#ifdef LOCAL
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#else
#include <bits/stdc++.h>
#endif
using namespace std ;

typedef long long ll ;
#define rep(i , n ) for ( int i =0; i < n ; i++)
#define _sort(arg) sort(begin(arg), end(arg))
#define MOD 1000000007
#define pb push_back
#define DEBUG(x) cout << #x << ": " << x << endl;


#define INF 100007
/*
__attribute__((constructor))
void initial()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
}
*/

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	
	cin >> N;

	string s[N];
	int a[26];
	int b[26];
	memset(a, 0, sizeof(a));
	//memset(b, 0, sizeof(b));
	rep(i, 26)
	{
		b[i] = INF;
	}
	rep(i, N)
	{
		cin >> s[i];
		for(int j = 0; j < s[i].size(); j++)
		{
			a[s[i][j] - 'a']++;
		}
		for (int k = 0; k < 26; k++)
		{
			b[k] = min(a[k], b[k]);
		}
		
		memset(a, 0, sizeof(a));
	}

	bool flg = false;
	rep(i, 26)
	{
		char tmp = 'a';
		while(b[i] > 0)
		{
			tmp = i + 'a';
			cout << tmp;
			b[i]--;
			flg = true;
		}
	}

	if (!flg)
	{
		cout << " ";
	}
	
	cout << endl;

	return 0;
}
