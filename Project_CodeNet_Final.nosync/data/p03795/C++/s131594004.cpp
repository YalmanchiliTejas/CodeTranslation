#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;
int n;
long long t,you;
int main()
{
	scanf("%d",&n);
	t=n*800;
	you=(n/15)*200;
	cout<<t-you<<endl;
return 0;
}
