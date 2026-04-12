#include<iostream>
using namespace std;
int i,ans;
int main()
{
	int a[3];
	for(i=0;i<3;i++)
	cin>>a[i];
	ans+=a[0]*100+a[1]*10+a[2];
	if(ans%4==0)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	return 0;
}