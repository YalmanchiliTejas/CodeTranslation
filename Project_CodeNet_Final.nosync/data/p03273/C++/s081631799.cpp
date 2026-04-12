#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define printjudge(cond) {if(cond) printf("Yes\n"); else printf("No\n");}
#define printans(ans) {printf("%d\n", (ans));}
typedef int* intarray;
typedef char* chararray;

int main(){
    int H, W;
    scanf("%d %d ", &H, &W);
    chararray* a;
    a = new chararray[H];
    for(int i=0; i<H; i++) a[i] = new char[W+1];
    for(int i=0; i<H; i++){
        scanf("%s", a[i]);
    }
    intarray row = new int[H];
    intarray column = new int[W];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(a[i][j]=='#') {row[i] = 1; break;}
            if(j==W-1) row[i] = 0;
        }
    }
    for(int j=0; j<W; j++){
        for(int i=0; i<H; i++){
            if(a[i][j]=='#') {column[j] = 1; break;}
            if(j==W-1) column[j] = 0;
        }
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(row[i]*column[j]) printf("%c", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}