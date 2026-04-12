#include <stdio.h>
typedef struct{
	int num,ans,rank;
}Pair;
void swap(Pair *a,Pair *b){
	Pair tmp=*a;
	*a=*b;*b=tmp;
}
int main(){
	int num,ans,i=0;
	Pair a[256];
	while(1){
		scanf("%d,%d",&num,&ans);
		if(!num&&!ans) break;
		a[i].num=num;
		a[i].ans=ans;
		i++;
	}
	for(int j=0;j<i;j++){
		for(int k=j+1;k<i;k++) if(a[k].ans>a[j].ans) swap(&a[k],&a[j]);
	}
	int tmp=a[0].ans,k=1;
	for(int j=0;j<i;j++){
		if(a[j].ans==tmp) a[j].rank=k;
		else{
			k++;
			tmp=a[j].ans;
			a[j].rank=k;
		}
	}
	while(~scanf("%d",&num)){
		for(int j=0;j<i;j++) if(num==a[j].num) printf("%d\n",a[j].rank);
	}
	return 0;
}