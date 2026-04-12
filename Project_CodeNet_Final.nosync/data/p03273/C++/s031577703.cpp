#include <iostream>
using namespace std;
#define N 102
struct node
{
	char a;
	bool ok;
} op[N][N];
int main()
{
	int H,W,count;
	while(cin>>H>>W)
	{
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)
			{
				cin>>op[i][j].a;
				op[i][j].ok=1;
			}
		}
		for(int i=0;i<H;i++)
		{
			count=0;
			for(int j=0;j<W;j++)
			{
				if(op[i][j].a=='.')
				{
					count++;
				}
			}
			if(count==W)
			{
				for(int j=i;j<H-1;j++)
				{
					for(int k=0;k<W;k++)
					{
						op[j][k].a=op[j+1][k].a;
					}
				}
				H--;
				i--;
			}
		}
		for(int i=0;i<W;i++)
		{
			count=0;
			for(int j=0;j<H;j++)
			{
				if(op[j][i].a=='.')
				{
					count++;
				}
			}
			if(count==H)
			{
				for(int j=i;j<W-1;j++)
				{
					for(int k=0;k<H;k++)
					{
						op[k][j].a=op[k][j+1].a;
					}
				}
				W--;
				i--;
			}
		}
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)
			{
				cout<<op[i][j].a;
			}
			cout<<endl;
		}
	}
	return 0;
}