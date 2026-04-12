#include<bits/stdc++.h>
#define N 10
using namespace std;
char s[N][N];
int H,W;
int main(){
	cin>>H>>W;
	for(int i=1;i<=H;i++)
		scanf("%s",s[i]+1);
	int lastr=0,lastc=1;
	for(int i=2;i<=H+W;i++){
		int num=0;
		for(int r=1;r<=min(i-1,H);r++){
			int c=i-r;if(c>W||s[r][c]!='#') continue;
			if(num==0&&(abs(lastr-r)+abs(lastc-c)==1)) lastr=r,lastc=c,num++;
			else return puts("Impossible"),0;
		}
	}
	puts("Possible");
	return 0;
}