#include<cstdio>

using namespace std;

int sai[6]={1,2,3,4,5,6};

int fun(char c)
{
	int fsai[6];
	if(c=='N')
	{
		fsai[0]=sai[1];
		fsai[1]=sai[5];
		fsai[2]=sai[2];
		fsai[3]=sai[3];
		fsai[4]=sai[0];
		fsai[5]=sai[4];
	}
	if(c=='E')
	{
		fsai[0]=sai[3];
		fsai[1]=sai[1];
		fsai[2]=sai[0];
		fsai[3]=sai[5];
		fsai[4]=sai[4];
		fsai[5]=sai[2];
	}
	if(c=='W')
	{
		fsai[0]=sai[2];
		fsai[1]=sai[1];
		fsai[2]=sai[5];
		fsai[3]=sai[0];
		fsai[4]=sai[4];
		fsai[5]=sai[3];
	}
	if(c=='S')
	{
		fsai[0]=sai[4];
		fsai[1]=sai[0];
		fsai[2]=sai[2];
		fsai[3]=sai[3];
		fsai[4]=sai[5];
		fsai[5]=sai[1];
	}
	if(c=='R')
	{
		fsai[0]=sai[0];
		fsai[1]=sai[2];
		fsai[2]=sai[4];
		fsai[3]=sai[1];
		fsai[4]=sai[3];
		fsai[5]=sai[5];
	}
	if(c=='L')
	{
		fsai[0]=sai[0];
		fsai[1]=sai[3];
		fsai[2]=sai[1];
		fsai[3]=sai[4];
		fsai[4]=sai[2];
		fsai[5]=sai[5];
	}
	for(int i=0;i<6;i++)
	{
		sai[i]=fsai[i];
	}
	return sai[0];
}

int main()
{
	while(true)
	{
		for(int i=0;i<6;i++)
		{
			sai[i]=i+1;
		}
		int n;
		int answer=1;
		scanf("%d",&n);
		if(n==0)break;
		for(int i=0;i<n;i++)
		{
			char c[10];
			scanf("%s",c);
			answer+=fun(c[0]);
		}
		printf("%d\n",answer);
	}
	return 0;
}