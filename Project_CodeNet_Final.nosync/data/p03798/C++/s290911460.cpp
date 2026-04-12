#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n,lr[100005],put[100005];
char c[100005];
//0-->S 1-->W
void print(){
	for(int i=1;i<=n;i++)
	if(put[i]==0)printf("S");
	else printf("W");
}

void work(int num1,int num2){
	memset(put,0,sizeof(put));
	put[1]=num1;
	put[2]=num2;
	for(int i=2;i<=n;i++){
		if((c[i]=='x'&&put[i]==1)||(c[i]=='o'&&put[i]==0))
		put[i+1]=put[i-1];
		if((c[i]=='o'&&put[i]==1)||(c[i]=='x'&&put[i]==0))
		put[i+1]=1-put[i-1];
	}
	if(((c[1]=='x'&&put[1]==1)||(c[1]=='o'&&put[1]==0))&&put[2]==put[n]&&put[n+1]==put[1]){
		print();
		exit(0);
	}
	if(((c[1]=='o'&&put[1]==1)||(c[1]=='x'&&put[1]==0))&&put[2]+put[n]==1&&put[n+1]==put[1]){
		print();
		exit(0);
	}
}

int main(void){
	scanf("%d",&n);
	scanf("%s",c+1);
	for(int i=0;i<=1;i++){
		for(int j=0;j<=1;j++){
			work(i,j);
		}
	} 
	printf("-1");
}