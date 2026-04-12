#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int abc=a*100+b*10+c;
	if(abc%4==0){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
    return 0;
}
