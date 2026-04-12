#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)

using namespace std;

const int N=15;
int n,m,x,y,cnt; char s[N][N];

int main(){
	scanf("%d%d",&n,&m);
	rep (i,1,n){
		scanf("%s",s[i]+1);
		rep (j,1,m) if (s[i][j]=='#') cnt++;
	}
	if (cnt!=n+m-1) return puts("Impossible"),0;
	x=y=1;
	if (s[1][1]!='#') return puts("Impossible"),0;
	while (x<n||y<m){
		int f1=x<n&&s[x+1][y]=='#';
		int f2=y<m&&s[x][y+1]=='#';
		if (f1||f2){
			if (f1&&f2) return puts("Impossible"),0;
			if (f1) x++; else y++;
		} else return puts("Impossible"),0;
	}
	puts("Possible");
	return 0;
}