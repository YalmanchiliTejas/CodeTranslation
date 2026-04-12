#include <iostream>
using namespace std;

int H,W; char a[20][20];

void dfs(int x, int y){
    if (a[x][y]!='#') return;
    a[x][y]='.';
    if (a[x+1][y]=='#') dfs(x+1,y);
    else dfs(x,y+1);
}

int main(){
    cin >> H >> W;

    int i,j;
    for (i=1; i<=H; i++)
        for (j=1; j<=W; j++) cin >> a[i][j];

    if (a[1][1]!='#' || a[H][W]!='#'){
        cout << "Impossible\n";
        return 0;
    }

    dfs(1,1);
    for (i=1; i<=H; i++)
        for (j=1; j<=W; j++)
        if (a[i][j]!='.'){
            cout << "Impossible\n";
            return 0;
        }

    cout << "Possible\n";
    return 0;
}
