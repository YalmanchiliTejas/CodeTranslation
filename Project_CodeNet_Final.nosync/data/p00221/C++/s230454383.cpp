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
			int k;
/*			if(j==m)
			{
				j=0;
			}
			int over=0;
			for(k=j;ans[k]==0;++k)
			{
				if(k>=m)
				{
					over=1;
					break;
				}
			}
			if(over!=1)
				j=k;
*/
			int flag=0;
			for(int l=0;l<m;l++)
			{
				if(ans[l]!=0)
				flag++;
			}
//			cout << "--------nowflag:" << flag << "-----------  " ;
			if(flag>1)
			{
				if(i%3==0 && i%5==0)
				{
					if(str!="FizzBuzz")
					{
//						cout << "notFizzBuzz j:" << j << endl;
						ans[j]=0;
					}
					else
					{
//						cout << "safe j:" << j << endl;
					}
				}
				else if(i%3==0)
				{
					if(str!="Fizz")
					{
//						cout << "notFizz j:" << j << endl;
						ans[j]=0;
					}
					else
					{
//						cout << "safe j:" << j << endl;
					}
				}
				else if(i%5==0)
				{
					if(str!="Buzz")
					{
//						cout << "notBuzz j:" << j << endl;
						ans[j]=0;
					}
					else
					{
//						cout << "safe j:" << j << endl;
					}
				}
				else
				{
					if(str!=ch)
					{
//						cout << "notMath j:" << j << endl;
						ans[j]=0;
					}
					else
					{
//						cout << "safe j:" << j << endl;
					}
				}
				j++;
				int c;
				for(c=j;ans[c]==0;)
				{
					c++;
					if(c>m-1)
						c=0;
//					cout << "ans[" << c << "]:" << ans[c] << endl;
				}
				j=c;
			}
		}
		int las;
		for(i=0;i<m;i++)
		{
			if(ans[i]!=0)
				las=i;
		}
		
//		cout << "ans:" ;
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