//hi
#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
typedef long long int LL;
char s[10][10];

bool go(int h,int w){
	if(s[0][0]!='#') return false;
	int x=0, y=0;
	s[0][0]='.';
	while(x!=h-1 || y!=w-1){
		//printf("%d %d\n",x,y);
		if((x+1<h&&s[x+1][y]=='#') && (y+1<w&&s[x][y+1]=='#')) return false;
		if((x+1<h&&s[x+1][y]!='#') && (y+1<w&&s[x][y+1]!='#')) return false;
		if(x+1<h && s[x+1][y]=='#') x=x+1, s[x][y]='.';
		else if(y+1<w && s[x][y+1]=='#') y=y+1, s[x][y]='.';
		else return false;
	}
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			if(s[i][j]=='#') return false;
	return true;
}
int main(void){
    int h,w;
    scanf("%d%d",&h,&w);
    int i,j;
    for(i=0;i<h;i++)
		scanf("%s",s[i]);
	if(go(h,w)) printf("Possible\n");
	else printf("Impossible\n");
	
    return 0;
}
