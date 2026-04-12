#include<iostream>
#include<string>
using namespace std;
int main(){
	int n,t,e,x,set=-1;
	cin>>n>>t>>e;
	for(int i=0;i<n;i++){
		cin>>x;
		if((t/x)*x>=t-e&&(t/x)*x<=t+e)
			set=i+1;
		if((t/x)*x+x>=t-e&&(t/x)*x+x<=t+e)
			set=i+1;
	}
	cout<<set<<endl;
	return 0;
}