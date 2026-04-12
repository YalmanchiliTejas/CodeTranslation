#include<iostream>
using namespace std;
int main(){
	int n,x;
	cin>>n;
	int c=0;
	for(int i=15;i<=n;i++)
	if(n>=15&&i%15==0)
	c++;
	x=(n*800)-(c*200);
	cout<<x;

	return 0;
}

