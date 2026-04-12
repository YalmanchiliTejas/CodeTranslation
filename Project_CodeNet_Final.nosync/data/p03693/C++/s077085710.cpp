#include<stdio.h>
#include<utility>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	int b =0;
	b=a[0]*100+a[1]*10+a[2];
	if(b%4==0)
	cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}


