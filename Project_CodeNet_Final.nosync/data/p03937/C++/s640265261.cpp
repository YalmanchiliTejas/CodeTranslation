#include<stdio.h>
int n,m;
char t[11][11];
char s[11][11];
bool process(){
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			t[i][j] = '.';
	int x = 0, y = 0;
	while(1){
		t[x][y] = '#';
		if(x==n-1 && y == m-1)break;
		if(x<n-1 && s[x+1][y] == '#')
			x++;
		else
		if(y<m-1 && s[x][y+1] == '#')
			y++;
		else
			return false;
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(s[i][j]!=t[i][j])
				return false;
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
		scanf("%s",s[i]);
	puts(process()?"Possible":"Impossible");
	return 0;
}