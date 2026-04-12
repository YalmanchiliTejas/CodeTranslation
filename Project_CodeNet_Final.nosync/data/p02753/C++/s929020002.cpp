#include<iostream>
using namespace std;
int main()
{
	char text[3];
	int a[3];
    for(int i=0;i<=2;i++)
    {
    	cin>>text[i];
		a[i]=int(text[i]);	
	}
    if(a[0]==a[1]&&a[0]==a[2]&&a[1]==a[2])
	cout<<"No"<<endl;
	else
	cout<<"Yes"<<endl;
}