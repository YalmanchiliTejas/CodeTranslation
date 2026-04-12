#include<bits/stdc++.h>
using namespace std;
int i,j;
char a[10][10];
bool fg=true;
void hh(int x,int y){
	if(x==i-1&&y==j-1&&fg) {
	fg=false;
	for(int ii=0;ii<i;++ii)
		for(int ij=0;ij<j;++ij)
			if(a[ii][ij]!='.'&&(ii!=0||ij!=0)) fg=true;
	}
	if(a[x][y+1]=='#'){
		a[x][y+1]='.';
		hh(x,y+1);
		a[x][y+1]='#';
	}
	if(a[x+1][y]=='#'){
		a[x+1][y]='.';
		hh(x+1,y);
		a[x+1][y]='#';
	}
}
int main(){
	scanf("%d%d",&i,&j);
	for(int ii=0;ii<i;++ii)
		scanf("%s",a[ii]);
	hh(0,0);
//	for(int ii=0;ii<i;++i)
//		for(int ij=0;ij<j;++j)
//			if(a[ii][ij]!='.') fg1=
	if(fg) printf("Impossible");	
	else printf("Possible");
	return 0;
}