#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	char mat[101][101];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>mat[i][j];
	}
	queue<int> qi;
	queue<int> qj;
	qi.push(0);
	qj.push(0);
	bool visited[101][101];
	memset(visited,0,sizeof(visited));
	visited[0][0]=1;
	while(!qi.empty())
	{
		int topi=qi.front();
		qi.pop();
		int topj=qj.front();
		qj.pop();
		if(topi+1<n&&topj+1<m)
		{
			if(mat[topi+1][topj]=='.'&&mat[topi][topj+1]=='.')
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
			else if(mat[topi+1][topj]=='#'&&mat[topi][topj+1]=='#')
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
			else if(mat[topi+1][topj]=='#')
			{
				qi.push(topi+1);
				qj.push(topj);
				visited[topi+1][topj]=true;
			}
			else if(mat[topi][topj+1]=='#')
			{
				qi.push(topi);
				qj.push(topj+1);
				visited[topi][topj+1]=true;
			}
		}
		else if(topi+1<n)
		{
			if(mat[topi+1][topj]=='#')
			{
				qi.push(topi+1);
				qj.push(topj);
				visited[topi+1][topj]=true;
			}
			else
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
		}
		else if(topj+1<m)
		{
			if(mat[topi][topj+1]=='#')
			{
				qi.push(topi);
				qj.push(topj+1);
				visited[topi][topj+1]=true;
			}
			else
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mat[i][j]=='#'){
			if(!visited[i][j])
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
			}
		}
	}
	cout<<"Possible"<<endl;
	return 0;
}