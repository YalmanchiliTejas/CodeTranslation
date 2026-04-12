#include<iostream>
using namespace std;

int main(){
while(1){
	int n;
	scanf("%d",&n); if(n==0)break;
	int a[100002],b[100002],c,k=0; a[0]=-1;

	for(int i=1;i<=n;i++){
		scanf("%d",&c);
		if(i%2==1){
			if(a[k]==c)b[k]++;
			else {
				k++;
				a[k]=c;
				b[k]=1;
			}
		}
		else {
			if(a[k]==c)b[k]++;
			else {
				if(k==1){ a[k]=1-a[k]; b[k]++; }
				else {
					k--;
					b[k]+=b[k+1]+1;
				}
			}
		}
	}

	int ret=0;
	for(int i=1;i<=k;i++){
		if(a[i]==0)ret+=b[i];
	}

	printf("%d\n",ret);
}
}