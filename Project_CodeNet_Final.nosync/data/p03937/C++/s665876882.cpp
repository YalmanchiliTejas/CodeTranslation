#include <stdio.h>

int H, W;
char a[10][10];

int dfs(int x, int y){
    if(x >= H || y >= W || a[x][y] == '.') return 0;
    a[x][y] = '.';
    if(x == H-1 && y == W-1){
        for(int i=0; i<H; i++) for(int j=0; j<W; j++) if(a[i][j] == '#') return 0;
        return 1;
    }
    if(dfs(x+1, y)) return 1;
    if(dfs(x, y+1)) return 1;
    a[x][y] = '#';
    return 0;
}

int main(){
    scanf("%d%d", &H, &W);
    for(int i=0; i<H; i++) scanf("%s", a[i]);
    if(dfs(0, 0)) printf("Possible");
    else printf("Impossible");
    return 0;
}