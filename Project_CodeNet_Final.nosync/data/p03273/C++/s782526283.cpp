#include<cstdio>
using namespace std;
char jz[102][102];
int r,q,h,w;
bool ok=true;
bool d(int now){
	for(int i=1;i<=q;i++){
		if(jz[i][now]!='.')	return false;
	}
	return true;
}
bool c(int now){
	for(int i=1;i<=r;i++){
		if(jz[now][i]!='.')	return false;
	}
	return true;
}
void dd(int now){
	for(int i=now;i<=r;i++){
		for(int j=1;j<=q;j++){
			jz[j][i]=jz[j][i+1];
		}
	}
	return;
}
void dc(int now){
	for(int i=now;i<=q;i++){
		for(int j=1;j<=r;j++){
			jz[i][j]=jz[i+1][j];
		}
	}
	return;
}
int main(){
	scanf("%d%d",&h,&w);
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			scanf(" %c",&jz[i][j]);
		}
	}
	r=w;q=h;
	while(ok){
		ok=false;
		for(int i=1;i<=r;i++){
			if(d(i)){
				ok=true;
				dd(i);
				--r;
			}
		}
		for(int i=1;i<=q;i++){
			if(c(i)){
				ok=true;
				dc(i);
				--q;
			}
		}
	} 
	for(int i=1;i<=q;i++){
		for(int j=1;j<=r;j++){
			printf("%c",jz[i][j]);
		}
		printf("\n");
	}
	return 0;
}