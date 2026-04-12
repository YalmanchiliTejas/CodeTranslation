#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int nh,nw,h,w,H,W,a[114][514]={0};
	char c;
	cin>>H>>W;
	for(h=1;h<=H;h++)for(w=1;w<=W;w++)
	{
		cin>>c;
		if(c=='#')a[h][w]=1;
	}
	int dh[4]={1,0,-1,0},dw[4]={0,1,0,-1};
	h=w=1;
	for(;;)
	{
		int f=0;
		a[h][w]=0;
		for(int d=0;d<4;d++)
		{
			if(a[h+dh[d]][w+dw[d]]==1)
			{
				f++;
				if(d>1||f>1)
				{
					cout<<"Impossible"<<endl;
					return 0;
				}
				nw=w+dw[d],nh=h+dh[d];
			}
		}
		if(w==W&&h==H&&a[h-1][w]==0&&a[h][w-1]==0)
		{
			cout<<"Possible"<<endl;
			return 0;
		}
		else if(W==w&&H==h)
		{
			cout<<"Impossible"<<endl;
			return 0;
		}
		h=nh,w=nw;
	}
	cout<<"Impossible"<<endl;
}