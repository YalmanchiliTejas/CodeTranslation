#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring> 
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
 
using namespace std;

#define mod 1000000007

int main()
{
    int h, w;
    cin >> h >> w;
    char a[10][10];
    int maxtesu[10][10];
    int sharpnum = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
            maxtesu[i][j] = -1;
            if(a[i][j] == '#') sharpnum++;
        }
    }
    int dx[2] = {1, 0}, dy[2] = {0, 1};
    queue<pair<int, int> > qu;
    qu.push(make_pair(0, 0));
    maxtesu[0][0] = 0;
    while(!qu.empty()){
        int x = (qu.front()).first;
        int y = (qu.front()).second;
        // cout << x << " " << y << " " << maxtesu[x][y] << endl;
        qu.pop();
        for(int i = 0; i < 2; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= h || ny >= w || a[nx][ny] == '.') continue;
            if(maxtesu[nx][ny] < maxtesu[x][y] + 1){
                qu.push(make_pair(nx, ny));
                maxtesu[nx][ny] = maxtesu[x][y] + 1;
            }
        }
    }
    if(maxtesu[h - 1][w - 1] == sharpnum - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}