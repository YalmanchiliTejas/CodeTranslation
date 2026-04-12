#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1005;

int n, m, x, y, uk = 0;
char s[N][N];

int main(){
    memset(s, '.', sizeof(s));
    scanf("%d%d", &n, &m);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf(" %c", &s[i][j]);
        	uk += (s[i][j] == '#');
        }
    }
  	
    if(s[0][0] != '#' || uk != n + m - 1){printf("Impossible\n");return 0;}
    for(;x != n - 1 || y != m - 1;){
        int cnt = (s[x][y + 1] == '#') + (s[x + 1][y] == '#');
        if(cnt != 1){printf("Impossible\n");return 0;}
        if(s[x][y + 1] == '#') y++;
        else x++;
    }
    printf("Possible\n");
}
