#include<iostream>
using namespace std;

int main()
{
	int H,W,a[110][110];
	int hlist[110],wlist[110];
	
	for(int i=0;i<110;i++)
	{
		hlist[i]=0;
		wlist[i]=0;
	}
	
	
	string tmp;
	cin >> H >> W;
	for(int i=0;i<H;i++)
	{
		cin >> tmp;
		for(int j=0;j<W;j++)
		{
			if(tmp[j]=='#')
			{
				a[i][j]=1;
				hlist[i]=1;
				wlist[j]=1;
			}
			else /*if(tmp[j]=='.')*/ a[i][j]=0;
		}
	}
	
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			if(hlist[i]==0 || wlist[j]==0){}
			else
			{
				if(a[i][j]==0)cout << ".";
				else cout << "#";
			}
		}
		if(hlist[i]==1)cout << endl;
	}
	return 0;
}