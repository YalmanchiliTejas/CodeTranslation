#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int h[22];
	scanf("%d ",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);int finalhe=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(h[i]>=finalhe) ans++;
		finalhe=max(finalhe,h[i]);
		
	}
	cout<<ans;
	return 0;
}