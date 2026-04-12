#include<bits/stdc++.h>
using namespace std;

char S[10][10];

int main()
{
    int H, W;
    cin >> H >> W;

    int countx = 0;

    for(int i=1; i<=H; i++)
        for(int j=1; j<=W; j++)
        {
            cin >> S[i][j];
            countx+= (S[i][j]=='#');
        }

    int x = 1, y = 1, flag = 0;

    while(!(x==H && y==W))
    {
        if(S[x+1][y]=='#')
            x++;
        else if(S[x][y+1]=='#')
            y++;
        else
        {
            flag = 1;
            break;
        }
    }

    if(!flag && countx==H+W-1)
        printf("Possible\n");
    else
        printf("Impossible\n");

    return 0;
}
