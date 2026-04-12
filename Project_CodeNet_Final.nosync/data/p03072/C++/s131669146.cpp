#include<bits/stdc++.h>
using namespace std;
int h[25];
int ans,n;
bool f=true;
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) cin>>h[i];
	for(int i=1; i<=n; i++) {
		f=true;
		for(int j=i-1; j>0; j--) {
			if(h[i]<h[j]) {
				f=false;
				break;
			}
		}
		if(f==true)
			ans++;
	}
	cout<<ans<<endl;

	return 0;
}
