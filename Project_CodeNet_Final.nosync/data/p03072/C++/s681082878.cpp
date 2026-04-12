#include<iostream>
using namespace std;
int N,M,H;
main()
{
	cin>>N;
	int cnt=0;
	for(int i=0;i<N;i++)
	{
		cin>>H;
		cnt+=M<=H;
		if(M<H)M=H;
	}
	cout<<cnt<<endl;
}
