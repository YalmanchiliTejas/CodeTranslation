
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <set>

using namespace std ; 

typedef long long ll ; 


char map[11][11] ; 

int main()
{
    int H, W ; 
    scanf("%d%d", &H, &W) ; 
    for(int i = 0 ; i != H ; i++)
        scanf("%s", map[i]) ; 
    bool ans = true ; 
    int x = 0, y = 0 ; 
    while(ans && (x != H-1 || y != W-1)) {
        map[x][y] = '.';
        if(x == H-1) {
            y++ ;
            if(map[x][y] != '#')
                ans = false ; 
        }
        else if(y == W-1) {
            x++ ; 
            if(map[x][y] != '#')
                ans = false ; 
        }
        else {
            if(map[x+1][y] == '#' && map[x][y+1] == '#')
                ans = false ;
            if(map[x+1][y] == '.' && map[x][y+1] == '.')
                ans = false ; 
            if(map[x+1][y] == '#')
                x++ ; 
            else
                y++ ; 
        }
        map[x][y] = '.';
    }
    for(int i = 0 ; i != H ; i++)
        for(int j = 0 ; j != W ; j++) {
            if(map[i][j] == '#')
                ans = false ; 
        }
    puts(ans ? "Possible" : "Impossible");
    return 0 ; 
}

