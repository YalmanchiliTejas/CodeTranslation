#include<iostream>
using namespace std;
int main()
{   
    int n,a[25],num=0,x=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];	
	    if(a[i]>=x) {num++;x=a[i];}
	}
	cout<<num;
	return 0;
}