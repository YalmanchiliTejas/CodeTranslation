#include<iostream>
using namespace std;
int main(){
	int x,s,sum=0;
	cin>>x;
	s=x;
	if(x<15)
	{
		cout<<(s*800);}
	else 
	{
	while(x>=15)
	{sum=sum+1;
	x=x-15;
	}
		cout<<(s*800)-(200*sum);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
}