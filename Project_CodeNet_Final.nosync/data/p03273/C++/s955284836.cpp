/*
ID: jerrywcy
TASK: AtCoder Beginner Contest 107 Problem B
LINK: https://abc107.contest.atcoder.jp/tasks/abc107_b
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int h,w;
int g[110][110];
bool mh[110],mw[110];

int main()
{
	cin>>h>>w;
	int i,j;
	for (i=1;i<=h;i++){
		string s;
		cin>>s;
		for (j=1;j<=w;j++){
			if (s[j-1]=='.')g[i][j]=0;
			else g[i][j]=1;
		}
	}
	
	for (i=1;i<=h;i++){
		for (j=1;j<=w;j++){
			mh[i]|=g[i][j];
			mw[j]|=g[i][j];
		}
	}
	
	for (i=1;i<=h;i++){
		if (!mh[i])continue;
		for (j=1;j<=w;j++){
			if (!mw[j])continue;
			if (g[i][j])cout<<'#';
			else cout<<'.';
		}
		cout<<endl;
	}

	return 0;
}

