#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <set>
using namespace std;
typedef long long int LL;

const int MAX = 100+24;
char g[MAX][MAX];
bool r[MAX], c[MAX];
int main(){
    int h,w;
    while(~scanf("%d %d",&h,&w)){
        memset(r, false, sizeof r);
        memset(c, false, sizeof c);
        for(int i =0;i<h;i++){
            scanf("%s",g[i]);
        }
        for(int i = 0;i<h;i++){
            bool flag = true;
            for(int j =0;j<w;j++){
                if(g[i][j] == '#'){
                    flag = false;
                    break;
                }
            }
            if(flag){
                r[i] = true;
            }
        }
        for(int i = 0;i<w;i++){
            bool flag = true;
            for(int j =0;j<h;j++){
                if(g[j][i] == '#'){
                    flag = false;
                    break;
                }
            }
            if(flag){
                c[i] = true;
            }
        }
        for(int i =0;i<h;i++){
            for(int j =0;j<w;j++){
                if((!r[i]) && (!c[j])){
                    printf("%c", g[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
