#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d,e;
	cin>>a>>b>>c;
	d=a-c;
	e=(d-d%(b+c))/(b+c);
	cout<<e<<endl;	
}
