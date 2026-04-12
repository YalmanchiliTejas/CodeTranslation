#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
#define INF INT32_MAX
#define INFL INT64_MAX
using namespace std;

void solve()	{
	int h,w;
	cin >> h >> w;
	string s[h];
	for(int i=0; i<h; i++)	cin >> s[i];
	for(int i=0; i<h; i++)	{
		bool f=1;
		for(int j=0; j<w; j++)	if(s[i][j]=='#') f=0;
		if(f)	{
			for(int j=0; j<w; j++)	s[i][j]='o';
		}
	}
	for(int i=0; i<w; i++)	{
		bool f=1;
		for(int j=0; j<h; j++)	if(s[j][i]=='#') f=0;
		if(f)	{
			for(int j=0; j<h; j++)	s[j][i]='o';
		}
	}
	for(int i=0; i<h; i++)	{
		bool f=0;
		for(int j=0; j<w; j++)	{
			if(s[i][j]!='o')	{f=1; cout << s[i][j];}
		}
		if(f) cout << endl;
	}
}

int main()	
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin >> t;
	for(int i=1; i<=t; i++)	{
		solve();
	}
	return 0;
}