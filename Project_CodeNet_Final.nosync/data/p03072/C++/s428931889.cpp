#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,ipt,now=0,ans=0;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&ipt);
		if(ipt>=now) now=ipt, ans++;
	}
	printf("%d",ans);
}