#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a,b,c;

int main(){
	
	cin>>a>>b>>c;
	a=a*10+b;
	a=a*10+c;
	if(a%4==0)cout<<"YES";
	else cout<<"NO";
	return 0;
}