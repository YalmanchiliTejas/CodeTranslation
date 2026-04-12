#include<cstring>
#include<algorithm>
#include<functional>
#include<iostream>

using namespace std;
int main(void)
{
	int n,sum,A;
	cin>>n;
	sum=n*800;
	A=n/15;
	A*=200;
	cout<<sum-A<<endl;
	return 0;
}