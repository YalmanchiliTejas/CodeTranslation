#include<iostream>
using namespace std;
long long int a[10000];
long long int cache[5000][5000][2]={0};
long long int optimalResult(int i,int j,int k)
{
	if(i>j)
	return 0;
	if(cache[i][j][k]!=0)
	return cache[i][j][k];
	if(k==0)
	{
		long long int x=a[i]+optimalResult(i+1,j,1);
		long long int y=a[j]+optimalResult(i,j-1,1);
		return cache[i][j][k]=x>y?x:y;
	}
		if(k==1)
	{
		long long int x=-a[i]+optimalResult(i+1,j,0);
		long long int y=-a[j]+optimalResult(i,j-1,0);
		return cache[i][j][k]=x>y?y:x;
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	long long int x=optimalResult(0,n-1,0);
	cout<<x;
}