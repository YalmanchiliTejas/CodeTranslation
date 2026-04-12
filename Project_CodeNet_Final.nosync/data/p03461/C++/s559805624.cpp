#include<bits/stdc++.h>
using namespace std;

int d[11][11];
int c[111][111];

int main(){
    int A, B; scanf("%d%d",&A,&B);
    for(int i=1;i<=A;i++) for(int j=1;j<=B;j++) scanf("%d",&d[i][j]);

    for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) c[i][j] = -1;

    for(int x=1;x<=A;x++) for(int y=1;y<=B;y++){
        bool found = false;
        for(int a=0;a<=100;a++){
            for(int b=0;b<=100;b++){
                int curC = d[x][y] - x*a - y*b;
                if(0<=curC && curC<=100){
                    bool cur = true;
                    for(int xx=1;xx<=A;xx++){
                        for(int yy=1;yy<=B;yy++){
                            if(curC + xx*a + yy*b < d[xx][yy]){
                                cur = false;
                                break;
                            }
                        }
                        if(!cur) break;
                    }
                    if(cur){
                        found = true;
                        c[a][b] = curC;
                        break;
                    }
                }
            }
            if(found) break;
        }
        if(!found) return !printf("Impossible\n");
    }

    printf("Possible\n");

    int xMax = 0, yMax = 0;
    for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) if(c[i][j]>=0){
        xMax = max(xMax, i);
        yMax = max(yMax, j);
    }
    int N = xMax + yMax + 2;

    int M = N - 2;
    for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) if(c[i][j] >= 0) M++;

    printf("%d %d\n", N, M);
    for(int i=1;i<=xMax;i++) printf("%d %d X\n", i, i+1);
    for(int i=0;i<yMax;i++) printf("%d %d Y\n", N-i-1, N-i);

    for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) if(c[i][j] >= 0)
        printf("%d %d %d\n", 1+i, N-j, c[i][j]);

    printf("1 %d\n", N);
}
