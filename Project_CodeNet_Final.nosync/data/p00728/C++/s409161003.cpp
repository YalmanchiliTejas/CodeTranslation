#include <iostream>

using namespace std;

int main()
{
	for(int n;cin>>n,n;){
		int x,sum=0,mx=0,mn=1000;
		for(int i=0;i<n;i++){
			cin>>x; sum+=x;
			if(x>mx) mx=x;
			if(x<mn) mn=x;
		}
		cout<<(sum-mn-mx)/(n-2)<<endl;
	}
	return 0;
}