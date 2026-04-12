#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y,z;cin>>x>>y>>z;
	int a=0;
	while(a*y+(a+1)*z<=x)a++;
	cout<<a-1<<endl;
}