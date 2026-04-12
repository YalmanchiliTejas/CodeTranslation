#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,h[20],cnt=1;
	cin>>n;
	for(int i=0;i<n;i++) cin>>h[i];
	for(int i=1;i<n;i++){
		bool ok=true;
		for(int j=0;j<i;j++) if(h[j]>h[i]) ok=false;
		if(ok==true) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
} 
