#include<bits/stdc++.h>
using namespace std;
int n,k;
char c[15];
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) cin>>c[i];
	cin>>k;
	for(int i=1;i<=n;i++) {
		if(int(c[i])==int(c[k])) cout<<c[i];
		else cout<<"*";
	}
	return 0;
}