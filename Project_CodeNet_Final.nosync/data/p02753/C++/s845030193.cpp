#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	if(char(a[0])==char(a[1])&&char(a[1])==char(a[2])&&char(a[0])==char(a[2]))cout<<"No";
	else
	cout<<"Yes";
	return 0;
 } 