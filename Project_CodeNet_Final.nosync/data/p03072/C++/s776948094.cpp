#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,s=0,ma=-1;
	
	cin>>n;
	int a[n+1];
	cin>>a[1];
	ma=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]>=ma){
			ma=a[i];
			s++;
		}
	}
	cout<<s+1<<endl;
	
	return 0;
}