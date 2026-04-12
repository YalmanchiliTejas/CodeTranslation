#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	int n,s;
	cin>>n;
	s=n*800;
	s-=(n/15)*200;
	cout<<s<<endl;
	return 0;
} 