#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n,h[100],i,m=0,count=0;

	cin>>n;
	for(int i=0;i<n;i++)cin>>h[i];

	for(i=0;i<n;i++){
		if(h[i]>=m)count++;
		m=max(h[i],m);
	}
	cout<<count<<endl;	
}