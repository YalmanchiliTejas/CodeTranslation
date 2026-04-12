#include <bits/stdc++.h>

using namespace std;

long long int patty[51]={0,};
long long int l[51]={0,};

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	patty[0] = 1;
	l[0] = 1;
	for(int i=1;i<=50;i++)
	{
		patty[i] = 2*patty[i-1] + 1;
		l[i] = 2*l[i-1] + 3;
	}

	long long int n,x;
	long long int res = 0;

	cin >> n >> x;

	while(1)
	{
		if(n==0)
		{
			res += 1;
			break;
		}
		//cout << n << ' ' << x << '\n';
		if(x<=1 || x>l[n])
		{
			break;
		}
		else if(x>1 && x<l[n-1]+2)
		{
			n-=1;
			x-=1;
		}
		else if(x==l[n-1]+2)
		{
			res += (patty[n-1] + 1);
			break;
		}
		else if(x>l[n-1]+2 && x<l[n])
		{

			res += (patty[n-1] + 1);
			x-=(l[n-1]+2);
			n-=1;
		}
		else if(x==l[n])
		{
			res += 2*patty[n-1] + 1;
			break;
		}
	}

	cout << res << '\n';
	return 0;
}