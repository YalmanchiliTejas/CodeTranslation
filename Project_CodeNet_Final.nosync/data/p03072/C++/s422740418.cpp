#include<iostream>
using namespace std;
int main()
{
	int n,x,maxi=-5,cnt=0;
	cin>>n;
	cin>>x;
	maxi=x;cnt++;
	for(int i=1;i<n;i++)
	{
		cin>>x;
		if(x>=maxi)
		cnt++;
		if(x>maxi)
		maxi=x;
		
	}
	cout<<cnt;
	
	
	
	
	
	
	
	return 0;
}