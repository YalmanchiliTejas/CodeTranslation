#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
typedef struct {
	int p,q;
}pai;
int compare(const void* a,const void *b){
	pai s=*(pai*)a,t=*(pai*)b;
	return -s.q+t.q;
}
int main(){
	pai pa[500];
	int x,y,k=0;
	while(scanf("%d,%d",&x,&y),x||y){
		pa[k].p=x;
		pa[k++].q=y;
	}
	qsort(pa,k,sizeof(pai),compare);
	int r,ran=1,s[500];
	int pre=pa[0].q;
	for(int i=0;i<k;i++){
	if(pre==pa[i].q)
	s[pa[i].p]=ran;
		else{
			s[pa[i].p]=++ran;
			pre=pa[i].q;
		}
	}
	
	while(cin>>r){
		cout<<s[r]<<endl;
	}
	return 0;
}