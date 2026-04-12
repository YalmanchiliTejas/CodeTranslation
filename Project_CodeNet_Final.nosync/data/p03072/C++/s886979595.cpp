#include<bits/stdc++.h>
using namespace std;
int N,H[22]={},Ans;
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&H[i]);
	Ans=1;
	for(int i=2;i<=N;i++){
		int f=0;
		for(int j=1;j<i;j++)
		 if(H[j]>H[i]){
		 	f++;
		 	break;
		 }
		if(!f) Ans++;
	}
	printf("%d\n",Ans);
	return 0;
}