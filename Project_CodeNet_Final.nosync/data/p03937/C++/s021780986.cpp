#include<bits/stdc++.h>
using namespace std;
const int M=10;
char S[M][M];
int h,w;

int main(){
	scanf("%d%d",&h,&w);
	for(int i=0;i<h;++i)
		scanf("%s",S[i]);
	if(S[0][0]!='#'){
		puts("Impossible");
		return 0;
	}
	int x=0,y=0,cnt=1;
	while(x!=h-1 || y!=w-1){
		bool mx=x+1<h && S[x+1][y]=='#';
		bool my=y+1<w && S[x][y+1]=='#';
		if(mx==my){
			puts("Impossible");
			return 0;
		}
		if(mx)
			++x;
		else
			++y;
		++cnt;
	}
	for(int i=0;i<h;++i)
		for(int j=0;j<w;++j)
			if(S[i][j]=='#')
				--cnt;
	puts(cnt==0?"Possible":"Impossible");
	return 0;
}
