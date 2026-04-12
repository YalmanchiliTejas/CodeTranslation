#include <bits/stdc++.h>
#define r(i,a,n) for(int i=a;i<n;i++)
using namespace std;
int main(){
	int n,t,e,p=-1,a;
	cin>>n>>t>>e;
	r(i,0,n){
		cin>>a;
		if((t+e)%a<=2*e)p=i+1;
	}
	cout<<p<<endl;
}