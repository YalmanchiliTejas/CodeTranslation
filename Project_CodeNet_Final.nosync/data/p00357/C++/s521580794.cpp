#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,d[300001],flg,i,cntm;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&d[i]);
	}
	cntm=d[1]/10;
	flg=0;
	for(i=1;i<n;i++){
		cntm=max(cntm,d[i]/10);
		if(cntm<=0){
			flg=1;
			break;
		}
		cntm--;
	}
	if(flg==1){
		printf("no\n");
	}
	else{
		for(i=n;i>1;i--){
			cntm=max(cntm,d[i]/10);
			if(cntm<=0){
				flg=1;
				break;
			}
			cntm--;
		}
		if(flg==1){
			printf("no\n");
		}
		else{
			printf("yes\n");
		}
	}
	return 0;
}
