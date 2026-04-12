//6ota hackman
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,count2=0,count1=0,flag=0;
	cin>>n>>m;
	char a[100][100] ;
	int i,j;
	for(i=0;i<n;i++)
	for( j=0;j<m;j++)
	{
	cin>>a[i][j];
	if(a[i][j]=='#')
	count1++;
    }
    i=0;j=0;
	while(i!=n-1 || j!=m-1)
	{
		if(a[i][j]=='#')
		count2++;
		
		if(i!=n-1 && j!=m-1)
		{
			if(a[i][j+1] == '#' && a[i+1][j]=='#')
			{
				flag=1;
				break;
			}
			else if(a[i][j+1]=='#')
			j+=1;
			else if(a[i+1][j] =='#')
			i+=1 ;
			else
			{
				flag=1;
				break;
			}
		}
		else if(i!=n-1)
		{
			if(a[i+1][j]=='#')
			i+=1;
			else
			{
				flag=1;
				break;
			}
			
		}
		else if(j!=m-1)
		{
			if(a[i][j+1]=='#')
			j+=1 ;
			else
			{
				flag=1;
				break;
			}
		}
	}
	count2++;
	//cout<<count1<<" "<<count2<<endl;;
	if(flag==1 || count2!=count1)
	cout<<"Impossible\n";
	else
	cout<<"Possible\n" ;
 	return 0;
}