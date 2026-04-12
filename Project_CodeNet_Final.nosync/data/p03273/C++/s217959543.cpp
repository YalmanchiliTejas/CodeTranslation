#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn = 107;
char s[maxn][maxn];
bool row[maxn], col[maxn];
int main(){
    int h, w;
    scanf("%d%d", &h, &w);
    for(int i = 1; i <= h; ++i){
        scanf("%s", s[i] + 1);
    }
    for(int i = 1; i <= h; ++i){
        for(int j = 1; j <= w; ++j){
            if(s[i][j] == '#'){
                row[i] = true;
                break;
            }
        }
    }
    for(int i = 1; i <= w; ++i){
        for(int j = 1; j <= h; ++j){
            if(s[j][i] == '#'){
                col[i] = true;
                break;
            }
        }
    }
    for(int i = 1; i <= h; ++i){
        if(!row[i])continue;
        for(int j = 1; j <= w; ++j){
            if(!col[j])continue;
            printf("%c", s[i][j]);
        }
        printf("\n");
    }
}
