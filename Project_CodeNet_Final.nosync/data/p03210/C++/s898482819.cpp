#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a;
  	cin>>a;
	string yes_no[]={"NO","YES"};
  	cout<<yes_no[a==3 || a==5 || a==7]<<endl;
  	return 0;
}