#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>

using namespace std;

 
int main(){

	int n,t,E;
	int x;
	int sum=0;
	cin>>n>>t>>E;
	for(int i=0;i<n;i++){
		cin>>x;
		bool f=false;
		for(int j=0;j*x<=t+E;j++)
		{
			if(j*x>=t-E&&j*x<=t+E)f=true;
		}
		if(f==true)sum=i+1;
	}

	if(sum==0)sum=-1;
	cout<<sum<<endl;
	
	return 0;
}