#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
int H,W;
vector<string> S;

bool ch(int h,int w)
{
	bool wf=false,hf=false;
	for(int i=0;i<H;i++)
		if(S[i][w]=='#')
			hf=true;
	for(int i=0;i<W;i++)
		if(S[h][i]=='#')
			wf=true;
	return hf&&wf;
}

int main()
{
	cin>>H>>W;
	for(int i=0;i<H;i++)
	{
		string ss;
		cin>>ss;
		S.push_back(ss);
	}

	for(int i=0;i<H;i++)
	{
		bool br=false;
		for(int j=0;j<W;j++)
		{
			if(ch(i,j))
			{
				putchar(S[i][j]);
				br=true;
			}
		}
		if(br)
			puts("");
	}
}
