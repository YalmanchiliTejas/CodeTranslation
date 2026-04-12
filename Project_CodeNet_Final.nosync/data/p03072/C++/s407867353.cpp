#include <bits/stdc++.h>
using namespace std;
#define for(i, a, b) for(int i=a; i<b; ++i)

int main(){
	int n; cin>>n;
	int max=0, ans=0;
	for(i, 0, n){
		int m; cin>>m;
		if (m>=max) max=m, ans++;
	}
	cout<<ans;
	return 0;
}