#include<bits/stdc++.h>
using namespace std;
char s[10][10];
int main(){
	int h,w,x=0,y=0,cnt=0;
	scanf("%d%d",&h,&w);
	for(int i=0;i<h;i++){
		scanf("%s",s[i]);
		for(int j=0;j<w;j++) cnt+=(s[i][j]=='#');
	}
	while(x+1<h||y+1<w){
		if(s[x][y]!='#') break;
		cnt--;
		bool d=x+1<h&&s[x+1][y]=='#',r=y+1<w&&s[x][y+1]=='#';
		if(d&&!r) x++;
		else if(!d&&r) y++;
		else break;
	}
	if(x+1<h||y+1<w||cnt>1) puts("Impossible");
	else puts("Possible");
	return 0;
}