#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int cnt;
bool p[100000];
main()
{
	while(cin>>n>>m,n)
	{
		cnt=n;
		for(int i=0;i<n;i++)p[i]=1;
		int i=0,j=1;
		for(;cnt>1&&j<=m;j++)
		{
			string s;cin>>s;
			string t=to_string(j);
			if(j%15<1)t="FizzBuzz";
			else if(j%5<1)t="Buzz";
			else if(j%3<1)t="Fizz";
			if(s!=t)cnt--,p[i]=0;
			i=(i+1)%n;
			while(!p[i])i=(i+1)%n;
		}
		for(;j<=m;j++)
		{
		    string s;cin>>s;
		}
		int f=0;
		for(int i=0;i<n;i++)if(p[i])cout<<(f++?" ":"")<<i+1;
		cout<<endl;
	}
}

