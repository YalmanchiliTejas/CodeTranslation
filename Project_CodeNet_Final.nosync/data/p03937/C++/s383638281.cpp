#include <cstdio>

int H, W;
char a[10][10];
int res, sum;
int ok;

void srch(int x, int y)
{
	if(ok)
		return ;
	if(x==H-1 && y==W-1){
		if(res == sum)
			ok = 1;
		return; 
	}
	int xx = x;
	int yy = y+1;
	if(xx>=0 && xx<H && yy>=0 && yy<W && a[xx][yy]=='#'){
		res ++;
		srch(xx, yy);
		res --;
	}
	xx = x+1;
	yy = y;
	if(xx>=0 && xx<H && yy>=0 && yy<W && a[xx][yy]=='#'){
		res ++;
		srch(xx, yy);
		res --;
	}
}

void solve()
{
	int i, j;
	if(a[0][0] == '.'){
		printf("Impossible\n");
		return ;
	}
	sum = 0;
	for(i=0; i<H; i++){
		for(j=0; j<W; j++){
			if(a[i][j] == '#')
				sum ++;
		}
	}
	ok = 0;
	res = 1;
	srch(0, 0);
	if(ok == 1)
		printf("Possible\n");
	else
		printf("Impossible\n");
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int i;
	scanf("%d%d", &H, &W);
	for(i=0; i<H; i++)
		scanf("%s", &a[i]);
	solve();
	return 0;
}