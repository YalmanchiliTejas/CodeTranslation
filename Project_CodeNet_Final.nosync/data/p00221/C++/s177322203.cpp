#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n,m;
	int i,j;
	char ch[100];
	string str;
	
	for(;;)
	{
		cin >> m >> n  ;
		if(n==0 && m==0)
			break;
		
		int ans[1024]={0};
		for(i=0;i<m;i++)
			ans[i]=i+1;
		
		j=0;
		for(i=1;i<=n;i++)
		{
			cin >> str ;
			
			sprintf(ch,"%d",i);
			int flag=0;
			for(int l=0;l<m;l++)
			{
				if(ans[l]!=0)
				flag++;
			}
			if(flag>1)
			{
				if(i%3==0 && i%5==0)
				{
					if(str!="FizzBuzz")
						ans[j]=0;
				}
				else if(i%3==0)
				{
					if(str!="Fizz")
						ans[j]=0;
				}
				else if(i%5==0)
				{
					if(str!="Buzz")
						ans[j]=0;
				}
				else
				{
					if(str!=ch)
						ans[j]=0;
				}
				j++;
				int c;
				for(c=j;ans[c]==0;)
				{
					c++;
					if(c>m-1)
						c=0;
				}
				j=c;
			}
		}
		int las;
		for(i=0;i<m;i++)
			if(ans[i]!=0)
				las=i;
		
		for(i=0;i<m;i++)
		{
			if(ans[i]!=0)
			{
				cout << ans[i] ;
				if(i<las)
					cout << " " ;
			}
		}
		cout << endl;
	}
}