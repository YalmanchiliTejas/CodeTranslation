#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,k,l,i=0;
	cin>>n>>m>>k;
	l=k;
	do
	{
		l+=m+k;
		i++;
	}
	while(l<n);
	if(l>n) i--;
	cout<<i<<endl;
	return 0;
}