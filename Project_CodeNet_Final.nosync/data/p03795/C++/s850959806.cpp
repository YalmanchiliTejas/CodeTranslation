#include<iostream>
using namespace std;
int main()
{
	int N,x,y;
	cin>>N;


	if(N>=15){
	x=N*800;
	y=(N/15)*200;
	
		cout<<x-y;
}
	else{
		x=N*800;
	y=0;
	cout<<x-y;
}
}