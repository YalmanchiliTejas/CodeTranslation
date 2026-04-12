#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7,MAX = 1e5;

vector<string> M;

int h,w;
bool ans;
void serch(int x,int y)
{
	
	if(x>=h||y>=w)return ;
	if(M[x][y]=='.')return;
	M[x][y] = '.';
	if(x+1<h&&M[x+1][y]=='#')serch(x+1,y);
	else serch(x,y+1);
}

int main()
{
	
	cin >> h >> w;
	for(int i =0;i<h;i++)
	{
		string s;
		cin >> s;
		M.push_back(s);
	}
	serch(0,0);
	for(int i = 0;i<h;i++)
	{
		for(int j = 0;j<w;j++)
		if(M[i][j]=='#')ans = true;
	}
	if(ans)
	{
		cout<<"Impossible"<<endl;
	}
	else
	{
		cout<<"Possible"<<endl;
	}
	
	

	return 0;
}
