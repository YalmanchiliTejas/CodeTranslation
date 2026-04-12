#include<iostream>
using namespace std;

int main()
{
	int n,h[20],v=0,maxv=0;
	cin>>n;
	for(int i=0;i<n;i++) cin>>h[i];
	
	for(int i=0;i<n;i++){
		if(h[i]>=maxv){
			maxv=h[i];
			v++;
		}
	}
	
	cout<<v<<endl;
	
	return 0;
}
