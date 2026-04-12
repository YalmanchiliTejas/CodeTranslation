#include<cstdio>
int N, d[300000], rd[300000];
bool trm(int, bool);

int main(void){
	int i;
	scanf("%d", &N);
	for(i=0; i<N; ++i){
		scanf("%d", d+i);
		d[i]/=10;
		rd[i]=d[i];
	}
	printf("%s\n", (trm(0, true))?"yes":"no");
	return(0);
}

bool trm(int c, bool l){
	int i;
	if((!l)&&(c==0)){return(true);}
	if(c==N-1){l=false;}
	for(i=(c+d[c]>=N)?N-1:c+d[c]; (i>c)&&(l); --i){
		if(trm(i, l)==true){return(true);}
		d[i]=0;
	}
	for(i=(c-rd[c]<0)?0:c-rd[c]; (i<c)&&(!l); ++i){
		if(trm(i, l)==true){return(true);}
		rd[i]=0;
	}
	
	return(false);
}
