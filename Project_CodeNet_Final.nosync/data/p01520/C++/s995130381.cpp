#include<iostream>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
	int N,T,E;
	int x,ans=-1;
	cin>>N>>T>>E;
	rep(i,N){
		cin>>x;
		int t=T;
		t%=x;
		if(t<=E || x-t<=E){
			ans=i+1;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}