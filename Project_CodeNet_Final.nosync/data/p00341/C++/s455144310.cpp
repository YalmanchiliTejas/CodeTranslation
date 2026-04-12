#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int e[12],i,n,m;
	for(i=0;i<12;i++){
		scanf("%d",&e[i]);
	}
	sort(e,e+12);
	m=0;
	for(i=0;i<3;i++){
		if(e[i]!=e[i+1]){
			m++;
		}
		
	}
	for(i=4;i<7;i++){
		if(e[i]!=e[i+1]){
			m++;
		}
	}
	for(i=8;i<11;i++){
		if(e[i]!=e[i+1]){
			m++;
		}
	}
	if(m==0){
		printf("yes\n");
	}
	else{
		printf("no\n");
	}
	return 0;
}

