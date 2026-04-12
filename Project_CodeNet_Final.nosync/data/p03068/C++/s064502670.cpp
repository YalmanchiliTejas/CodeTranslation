#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e5+5;
int  a[N];

int main()
{
	IOS;
	int n,k;
	string s;
	cin >> n >> s >> k;
	char lol = s[k-1];
	for(int i = 0; i < n; i++)
	{
		if(lol == s[i])
		{
			cout << s[i];
			continue;
		}
		cout<<"*";
	}
	return 0;
}
