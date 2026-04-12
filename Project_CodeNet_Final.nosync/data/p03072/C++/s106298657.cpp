#include<bits/stdc++.h>
using namespace std;
#define debug 1

int main() {
	int n,h,hmax=0;
	cin>>n;
	int ans=0;
	for(int i=0;i<n;i++) {
		scanf("%d",&h);
		if(h>=hmax) {
			ans++;
			hmax=h;
		}
	}
	cout<<ans<<endl; 
	return 0;
}
