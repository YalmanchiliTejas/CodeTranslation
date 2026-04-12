#include<iostream>
#include<vector>
using namespace std;
int N;
int S[500],T[500];
unsigned long A[500][500],U[500],V[500];
int tx[500],ty[500];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>S[i];
	for(int i=0;i<N;i++)cin>>T[i];
	for(int i=0;i<N;i++)cin>>U[i];
	for(int i=0;i<N;i++)cin>>V[i];
	for(int k=0;k<64;k++)
	{
		const unsigned long now=1uL<<k;
		int xc[4]={},yc[4]={};
		for(int i=0;i<N;i++)
		{
			if(S[i]==0)
			{
				if(U[i]&now)tx[i]=3;
				else tx[i]=1;
			}
			else
			{
				if(U[i]&now)tx[i]=2;
				else tx[i]=0;
			}
			xc[tx[i]]++;
			if(tx[i]==3)
			{
				for(int j=0;j<N;j++)A[i][j]|=now;
			}
		}
		for(int j=0;j<N;j++)
		{
			if(T[j]==0)
			{
				if(V[j]&now)ty[j]=3;
				else ty[j]=1;
			}
			else
			{
				if(V[j]&now)ty[j]=2;
				else ty[j]=0;
			}
			yc[ty[j]]++;
			if(ty[j]==3)
			{
				for(int i=0;i<N;i++)A[i][j]|=now;
			}
		}
		if(xc[0]>0&&yc[3]>0||xc[3]>0&&yc[0]>0)
		{
			cout<<-1<<endl;
			return 0;
		}
		if(xc[2]==0&&yc[2]==0)continue;
		if(xc[3]>0&&yc[3]>0)continue;
		vector<int>xi,yi;
		for(int i=0;i<N;i++)if(tx[i]>=2)xi.push_back(i);
		for(int j=0;j<N;j++)if(ty[j]>=2)yi.push_back(j);
		int xa=0,ya=0;
		if(xi.size()==0)
		{
			if(yc[2]==1)xa=1;
			else if(yc[2]>=2)xa=2;
		}
		else if(xi.size()==1)
		{
			if(yc[2]>=2)ya=1;
		}
		if(yi.size()==0)
		{
			if(xc[2]==1)ya=1;
			else if(xc[2]>=2)ya=2;
		}
		else if(yi.size()==1)
		{
			if(xc[2]>=2)ya=1;
		}
		for(int i=0;i<N;i++)if(tx[i]==1&&xa>0)
		{
			xa--;
			xi.push_back(i);
		}
		for(int j=0;j<N;j++)if(ty[j]==1&&ya>0)
		{
			ya--;
			yi.push_back(j);
		}
		for(int id=0;id<xi.size()||id<yi.size();id++)
		{
			A[xi[id%xi.size()]][yi[id%yi.size()]]|=now;
		}
	}
	for(int i=0;i<N;i++)
	{
		if(S[i]==0)
		{
			unsigned long now=A[i][0];
			for(int j=1;j<N;j++)now&=A[i][j];
			if(now!=U[i])
			{
				cout<<-1<<endl;
				return 0;
			}
		}
		else
		{
			unsigned long now=A[i][0];
			for(int j=1;j<N;j++)now|=A[i][j];
			if(now!=U[i])
			{
				cout<<-1<<endl;
				return 0;
			}
		}
		if(T[i]==0)
		{
			unsigned long now=A[0][i];
			for(int j=1;j<N;j++)now&=A[j][i];
			if(now!=V[i])
			{
				cout<<-1<<endl;
				return 0;
			}
		}
		else
		{
			unsigned long now=A[0][i];
			for(int j=1;j<N;j++)now|=A[j][i];
			if(now!=V[i])
			{
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)cout<<A[i][j]<<(j+1==N?'\n':' ');
	}
}
