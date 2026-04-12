#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
static const int MAX=100;
int D[MAX][MAX];
int main(void)
{
	int H,W;
	cin >> H >> W;
	queue<int > Q;
	vector<int > P;
	
	for(int i=0;i<H;i++)
	{
		string x;
		cin >> x;
		int take=0;
		
		for(int j=0;j<W;j++)
		{
			if(x[j]=='.')
			{
				D[i][j]=1;
				take++;
			}
		}
		if(take==W)
			Q.push(i);
	}
	
	
	for(int i=0;i<W;i++)
	{
		int take=0;
		for(int j=0;j<H;j++)
			take+=D[j][i];
			
		if(take==H)
			P.push_back(i);
	}
	
	
	
	for(int i=0;i<H;i++)
	{
		if(Q.size())
		{
			int r=Q.front();
			if(r==i)
			{
				Q.pop();
				continue;
			}
		}
		for(int j=0;j<W;j++)
		{
			
			
			int put=-1;
			int k;
			for(k=0;k<P.size();k++)
			{
				if(P[k]==j)
				{
					put=1;
					break;
				}
			}
			
			
			if(put==1){}
			else if(D[i][j]==1)
				cout << ".";
			else
				cout << "#" ;
			
			
		}
		cout << endl;
	}
	
	
	
	return 0;
}