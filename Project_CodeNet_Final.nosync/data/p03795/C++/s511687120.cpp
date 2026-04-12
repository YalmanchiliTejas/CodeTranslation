#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
double c;
int main()
{
	cin>>n;
	c=floor((n*1.0)/15);
	cout<<n*800-c*200<<endl;
	return 0;
}