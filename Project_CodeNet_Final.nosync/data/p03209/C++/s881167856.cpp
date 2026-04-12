#include<iostream>
#include<algorithm>
typedef long long lint;
using namespace std;

lint a[55];
lint p[55];

lint ans(lint n,lint x)
{
	if(n==0)return 1;
	if(x==1)return 0;
	else if(x<=1+a[n-1])return ans(n-1,x-1);
	else if(x==1+a[n-1]+1)return p[n-1]+1;
	else if(x<=2*a[n-1]+2)return p[n-1]+1+ans(n-1,x-(1+a[n-1]+1));
	else if(x==2*a[n-1]+3)return 2*p[n-1]+1;
}

int main()
{
	lint N,X;
	
	cin >> N >> X;
	
	a[0]=1;
	p[0]=1;
	for(lint i=0;i<N;i++)
	{
		a[i+1]=2*a[i]+3;
		p[i+1]=2*p[i]+1;
	}
	
	cout << ans(N,X) << endl;
	return 0;
}
