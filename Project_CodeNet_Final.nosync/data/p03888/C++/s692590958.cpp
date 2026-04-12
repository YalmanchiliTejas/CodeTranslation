#include<bits/stdc++.h>
using namespace std;
double a,b,c,temp;
int main()
{
	cin>>a>>b;
	temp=1/a+1/b;
	c=1/temp;
	printf("%.10lf\n",c);
}