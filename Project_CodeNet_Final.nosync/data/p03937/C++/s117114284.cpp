#include<bits/stdc++.h>
using namespace std;

int H,W;
char fid[20][20] = {0};
bool visit[20][20] = {0};

int main()
{
    scanf("%d%d",&H,&W);
    for(int i = 0; i < H; i++)for(int j = 0; j < W; j++)scanf(" %c",&fid[i + 1][j + 1]);
    int x = 1,y = 1;
    if(fid[1][1] != '#')
    {
        printf("Impossible\n");
        return 0;
    }
    for(int i = 0; i < H; i++)for(int j = 0; j < W; j++)if(fid[i + 1][j + 1] == '#')x++;
    if(W + H == x)printf("Possible\n");
    else printf("Impossible\n");
    return 0;
}
