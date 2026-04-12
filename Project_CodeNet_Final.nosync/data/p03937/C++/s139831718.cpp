#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

#define y1 roman_kaban
#define rank oryshych_konb
//const int mod = int(1e9) + 7;

const int MX = 20;
int a[MX][MX];

int main()
{
    //freopen("in.txt","r", stdin);
    ios_base::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        string s;
        cin >> s;
        for(int j = 0; j < w; j++)
            if(s[j] == '#') a[i][j] = 1;
    }

    int x = 0;
    int y = 0;
    while(true){
        a[x][y] = 0;
        if(a[x + 1][y]) {x++;} else
        if(a[x][y + 1]) {y++;} else
            break;
    }
    if(x != h - 1 || y != w - 1) {puts("Impossible"); return 0;}
    for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++)
    if(a[i][j]) {puts("Impossible"); return 0;}
    puts("Possible");
    return 0;
}
