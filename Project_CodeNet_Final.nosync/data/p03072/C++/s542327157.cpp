#include<bits/stdc++.h>
using namespace std;

int ans,n,x,maxi;

int main(){
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d",&x);
		maxi = max(maxi,x);
		if(maxi<=x) ans++;
	}
	printf("%d\n",ans);
	return 0;
}