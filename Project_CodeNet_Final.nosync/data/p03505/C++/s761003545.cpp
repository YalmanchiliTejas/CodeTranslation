#include<cstdio>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;
int main() 
{
	long long k,a,b;
	cin>>k>>a>>b;
	if(a>=k)
	{
		cout<<1<<endl;
		return 0;
	}
	if(a<=b)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<((k-b-1)/(a-b))*2+1<<endl;
	return 0;
}