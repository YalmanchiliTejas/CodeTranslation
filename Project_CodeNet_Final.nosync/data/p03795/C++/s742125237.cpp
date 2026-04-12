#include<iostream>
using namespace std;
int main(){
	int n,m,c;
	cin>>n;
	m=n*800;
	if(m>=12000){
	c=m-((m/12000)*200);
	cout<<c;}
	else
	cout<<m;
	
}