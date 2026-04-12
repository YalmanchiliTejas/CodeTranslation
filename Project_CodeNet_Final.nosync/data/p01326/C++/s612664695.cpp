#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
string ptn[5];
long long pattern(int s, int n)
{
	int x=1,y=1,yc=0,yz=0;
	for(int i=0; i<n*8; i++)
	{
		switch(str[s+i])
		{
			case 'x':
				if(ptn[n][i]=='x') x=(x*2)%1000000;
				if(ptn[n][i]=='y') y=(y*2)%1000000;
				break;
			
			case '1':
				if(ptn[n][i]=='0') return 0;
				if(ptn[n][i]=='y') yc++;
				break;
			
			case '0':
				if(ptn[n][i]=='1') return 0;
				if(ptn[n][i]=='y')
				{
					int t = (n==2?4:5);
					if(++yz == t) return 0;
				}
				break;
		}
	}

	if(y>1 && yc==0) y-=1;
		
	return (x*y)%1000000;
}

int main()
{
	ptn[1] = "0xxxxxxx";
	ptn[2] = "110yyyyx10xxxxxx";
	ptn[3] = "1110yyyy10yxxxxx10xxxxxx";
	ptn[4] = "11110yyy10yyxxxx10xxxxxx10xxxxxx";

/*
	str="xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	cout << pattern(0,1) << endl;
	cout << pattern(0,2) << endl;
	cout << pattern(0,3) << endl;
	cout << pattern(0,4) << endl;
*/

	int N;
	while(cin>>N, N)
	{
		str="";
		for(int i=0; i<N; i++)
		{
			string tmp;
			cin >> tmp;
			str += tmp;
		}
		
		long long dp[1024] = {0};
		dp[0] = 1;
		
		for(int i=1; i<=N; i++)
		{
			for(int n=1; n<=4; n++)
			{
				if(i-n < 0) break;    
				dp[i] = (dp[i] + dp[i-n]*pattern((i-n)*8, n))%1000000;
			}
		}
		
		cout << dp[N] << endl;
	}	
}