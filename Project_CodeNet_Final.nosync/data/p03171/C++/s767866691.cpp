#include <bits/stdc++.h>
 
#define int long long 

using namespace std;

int N;
int seq[3000];
int xminusy[2][3001][3001];

int getbestsc(bool player,int cursbe,int cursaf)
{
	if(cursaf==cursbe)
	{
		return (player ? -1 : 1)*seq[cursaf];
	}
	if(xminusy[player][cursbe][cursaf]!=-1)
	{
		return xminusy[player][cursbe][cursaf];
	}
	int gscore;
	if(player)
	{
		gscore = min(-seq[cursbe]+getbestsc(0,cursbe+1,cursaf),
					 -seq[cursaf]+getbestsc(0,cursbe,cursaf-1));
	}
	else
	{
		gscore = max(seq[cursbe]+getbestsc(1,cursbe+1,cursaf),
					 seq[cursaf]+getbestsc(1,cursbe,cursaf-1));
	}
	xminusy[player][cursbe][cursaf]= gscore;
	//cout<<"player "<<player<<" seq from "<<cursbe<<" to "<<cursaf<<" gives score : "<<gscore<<endl;
	return gscore;
	
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>N;
	for(int i = 0 ; i < N ; i++)
	{
		cin>>seq[i];
		for(int j = 0 ; j <= N ; j ++ )
		{
			xminusy[0][i][j]=-1;
			xminusy[1][i][j]=-1;
		}
	}
	for(int j = 0 ; j <= N ; j ++ )
	{
		xminusy[0][N][j]=-1;
		xminusy[1][N][j]=-1;
	}
	cout<<getbestsc(0,0,N-1);
}