#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include <vector>
#include<math.h>

using namespace std;
int main(){
	int max=0,a,b;
	char ch='A';
	while(1){
		cin>>a>>b;
		max=a+b;ch='A';
		if(a==0&&b==0)break;
		for(int i=0;i<4;i++)
		{
			cin>>a>>b;
			if(max<a+b){
				max=a+b;
				if(i==0)ch='B';
				if(i==1)ch='C';
				if(i==2)ch='D';
				if(i==3)ch='E';
			}
			
		}cout<<ch<<" "<<max<<endl;
	}
		return 0;
	}
			