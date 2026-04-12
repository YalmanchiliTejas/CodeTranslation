#include <stdio.h>

char s[105][105];
int row[105]={0},col[105]={0};

main() {
    int h,w,i,j;
    scanf("%d %d", &h, &w);
    for(i=0;i<h;i++) {
        scanf("%s", s[i]);
    }
    for(i=0;i<h;i++) {
        for(j=0;j<w;j++) {
            if(s[i][j]=='#') break;
        }
        if(j!=w) row[i]=1;
    }

    for(j=0;j<w;j++) {
        for(i=0;i<h;i++) {
            if(s[i][j]=='#') break;
        }
        if(i!=h) col[j]=1;
    }

    for(i=0;i<h;i++) {
        int flag=0;
        for(j=0;j<w;j++) {
            if(col[j] && row[i]) {
                printf("%c", s[i][j]);
                flag=1;
            }
        }
        if(flag) puts("");
    }
}