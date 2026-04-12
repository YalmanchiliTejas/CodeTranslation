#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	int b=a/15;
	cout<<(a<15?800*a:800*a-200*b);
	return 0;
 } 