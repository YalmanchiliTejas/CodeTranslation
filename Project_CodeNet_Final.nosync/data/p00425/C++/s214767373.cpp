#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <vector>
#include <stack>

using namespace std;
////////////////*My library*////////////////////////
#define rep_to(a,i,n) for(int i=a;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_r(i,n) for(int i=n-1;i>=0;i--)
#define debug(x) cout<<x<<endl
#define s_1(x) cin>>x
#define s_2(x,y) cin>>x>>y
////////////////////////////////////////////////////

////////////////////////
/*prime()*/
/*primecount()*/
/*sort()*/
/*imos???*/
/*????????¢?´¢*/
/*??±???????????¢?´¢*/
/*???????¨???????*/
///////////////////////
void log(int ban[])
{
	rep_to(1,i,7)cout<<ban[i]<<" ";
	cout<<endl;
}
int main()
{
	int N;
	char str[10000]={};

	while(1)
	{
		int sum=1;
		int ban[7]={0,1,2,3,4,5,6};
		s_1(N);
		if(N==0)break;
		rep(i,N)
		{
			s_1(str);
			if(strstr(str,"North")!=NULL)
			{
				swap(ban[1],ban[2]);
				swap(ban[2],ban[6]);
				swap(ban[6],ban[5]);
			}
			else if(strstr(str,"East")!=NULL)
			{
				swap(ban[1],ban[4]);
				swap(ban[4],ban[6]);
				swap(ban[6],ban[3]);
			}
			else if(strstr(str,"West")!=NULL)
			{
				swap(ban[1],ban[3]);
				swap(ban[3],ban[6]);
				swap(ban[6],ban[4]);
			}
			else if(strstr(str,"South")!=NULL)
			{
				swap(ban[1],ban[5]);
				swap(ban[5],ban[6]);
				swap(ban[6],ban[2]);
			}
			else if(strstr(str,"Right")!=NULL)
			{
				swap(ban[2],ban[3]);
				swap(ban[3],ban[5]);
				swap(ban[5],ban[4]);
			}
			else if(strstr(str,"Left")!=NULL)
			{
				swap(ban[2],ban[4]);
				swap(ban[4],ban[5]);
				swap(ban[5],ban[3]);
			}
			sum+=ban[1];
		}
		cout<<sum<<endl;
	}
	
	return 0;
}