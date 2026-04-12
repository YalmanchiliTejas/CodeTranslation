#include<iostream>
#include<sstream>
using namespace std;
stringstream ans;
main()
{
	int n;cin>>n;
	ans<<"!";
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			cout<<"? ";
			for(int k=0;k<n;k++)cout<<(k==i||k==j);
			cout<<endl;
			int d;cin>>d;
			if(d)ans<<" ("<<i<<","<<j<<")";
		}
	}
	cout<<ans.str()<<endl;
}