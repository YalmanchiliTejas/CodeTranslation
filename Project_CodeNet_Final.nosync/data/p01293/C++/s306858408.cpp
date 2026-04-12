#include "bits/stdc++.h"
using namespace std;

char trump[4][13][2];
int tuyosa[4][13];
int pt[4];

//rankを求める
int srank(const char *x,char head)
{
	int a=0;
	switch(x[0])
	{
		case 'T':
		a=10;
		break;
		case 'J':
		a=20;
		break;
		case 'Q':
		a=21;
		break;
		case 'K':
		a=22;
		break;
		case 'A':
		a=23;
		break;
		default:
		a=x[0]-'0';
		break;
	}
	return a;
}

int main()
{
	char head;
	string debug[4]={"north","east","south","west"};
	while(1)
	{
		cin>>head;
		if(head=='#')
			break;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<13;j++)
			{
				cin>>trump[i][j];
				tuyosa[i][j]=srank(trump[i][j],head);
			}
		}
		fill(pt,pt+4,0);
		int prewinner=0;
		int winner=0;
		//13のトリック
		for(int i=0;i<13;i++)
		{
			int kiri=0;
			int tmp=0;
			for(int j=0;j<4;j++)
			{
				if(trump[j][i][1]==trump[prewinner][i][1])
					tmp|=(1<<j);
				if(trump[j][i][1]==head)
					kiri|=(1<<j);
			}
			int m=0;
			if(kiri>0)
			{
				for(int j=0;j<4;j++)
				{
					if((kiri&(1<<j))==0)
						continue;
					m=max(m,tuyosa[j][i]);
				}
				for(int j=0;j<4;j++)
				{
					if((kiri&(1<<j) && tuyosa[j][i]==m))
						winner=j;
				}
			}else if(tmp>0){
				for(int j=0;j<4;j++)
				{
					if((tmp&(1<<j))==0)
						continue;
					m=max(m,tuyosa[j][i]);
				}
				for(int j=0;j<4;j++)
				{
					if((tmp&(1<<j) && tuyosa[j][i]==m))
						winner=j;
				}
			}else{
				for(int j=0;j<4;j++)
				{
					m=max(m,tuyosa[j][i]);
				}
				for(int j=0;j<4;j++)
				{
					if((tuyosa[j][i]==m))
						winner=j;
				}
			}
			//cerr<<debug[winner]<<endl;
			pt[winner]++;
			prewinner=winner;
		}
		int ns=pt[0]+pt[2];
		int ew=pt[1]+pt[3];
		if(ns>ew)
			cout<<"NS "<<max(0,ns-6)<<endl;
		else
			cout<<"EW "<<max(0,ew-6)<<endl;
	}
	return 0;
}
