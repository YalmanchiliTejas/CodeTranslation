#include<bits/stdc++.h>
using namespace std;
int read(){
	int ans=0;char c=getchar();
    while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}
int main(){
	int n;
	n=read();
	cout<<n*800-(n/15)*200<<endl;
	return 0;
}
	
