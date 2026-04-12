#include<iostream>
#include<cstdio>
using namespace std;

int main(){
while(1){
	int n,c,a,b[100000+2],k=0,ans=0;
	scanf("%d",&n);
	if(n==0)break;
	scanf("%d",&a);
	b[0]=1;
	for(int i=2;i<=n;i++){
		scanf("%d",&c);
		if(c==(a+k)%2)b[k]++;
		else {
			if(i%2!=0){
				b[k+1]=1; k++;
			}
			else {
				if(k==0){a=c; b[0]+=1;}
				else {b[k-1]+=b[k]+1; k--;}
			}
		}
	}
	for(int i=a;i<=k;i+=2){
		ans+=b[i];
	}
	printf("%d\n",ans);
}
}