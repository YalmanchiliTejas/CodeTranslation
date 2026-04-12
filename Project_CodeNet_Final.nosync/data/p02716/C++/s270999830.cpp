#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

long long guusuuDP(long long N,long long num[])
{
	long long ma[N][2];
	ma[1][0] = num[0];
	ma[1][1] = num[1];
	int i;
	for(i=1;i<=(N/2-1);i++)
	{
		ma[2*i+1][0] = ma[2*i-1][0] + num[2*i];
		ma[2*i+1][1] = max((ma[2*i-1][0]),(ma[2*i-1][1]))
		+ num[2*i+1];
	}
	return max(ma[N-1][0],ma[N-1][1]);
}
long long kisuuDP(long long N,long long num[])
{
	long long ma[N][2];
	ma[2][0] = max(num[0],num[1]);
	ma[2][1] = num[2];
	long long i;
	long long sum[(N+1)/2];
	sum[0] = num[0];
	for(i=1;i<=(N-1)/2;i++)
	{
		sum[i] = sum[i-1] + num[2*i];
	}
	for(i=2;i<=(N-1)/2;i++)
	{
		ma[2*i][1] = max(ma[2*i-2][0],ma[2*i-2][1])
		+ num[2*i];
		ma[2*i][0] = max(sum[i-1],ma[2*i-2][0]+num[2*i-1]);
	}
	return max(ma[N-1][0],ma[N-1][1]);
}
int main()
{
	long long N;
	cin >> N;
	long long num[N];
	long long i;
	for(i=0;i<N;i++)
	{
		cin >> num[i];
	}
	if(N % 2 == 0) cout << guusuuDP(N,num) << endl;
	else if(N % 2 == 1) cout << kisuuDP(N,num) << endl;
	return 0;
}
