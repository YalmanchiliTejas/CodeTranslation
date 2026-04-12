#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,p=0,r=0,ans=0,c=0;
	scanf("%d",&x);
	p=800*x;
	for(int i=x;i>=15;i-=15){
	   c=c+1;
	   }
		r=c*200;
		ans=p-r;
		printf("%d",ans);
	
}