#include<bits/stdc++.h>
using namespace std;
char c[20][20];
int visited[20][20];

int main()
{
	int H,W;
	cin>>H>>W;
	
	int i,flag=1;
	
	for (i=0;i<H;i++)
	scanf("%s",c[i]);
	
	int posx=0,posy=0;
	visited[0][0]=1;
	
	while(posx!=(H-1) || posy!=(W-1))
	{
		if(c[posx+1][posy]=='#' && c[posx][posy+1]!='#')
		{
			
			visited[posx+1][posy]=1;
			posx++;
			continue;
		}
		
		if(c[posx][posy+1]=='#' && c[posx+1][posy]!='#')
		{
		
			visited[posx][posy+1]=1;
				posy++;
		}
		
		else 
		{
			flag=0;
			break;
		}
		
	}
	
	int j;
	for (i=0;i<H;i++)
	{
		for (j=0;j<W;j++)
		{
			//	cout<<visited[i][j]<<" ";
			if(c[i][j]=='#' && visited[i][j]==0)
			{
				if(i==H-1 && j==W-1)
				continue;
				
			
				else
				flag=0;
				//break;
			}
			
		}
		//cout<<endl;
	}
	
	if(flag)
	cout<<"Possible";
	
	else cout<<"Impossible";
	
}