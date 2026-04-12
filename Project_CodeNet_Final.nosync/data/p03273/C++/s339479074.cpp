#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
char s[105][105];
int a[105], b[105];
int main(){
    int h, w;
    scanf("%d%d", &h, &w);
    for (int i = 0; i<h; i++) {
        scanf("%s",s[i]);
    }
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for(int i = 0; i<h; i++){
        int cnt = 0;
        for (int j = 0; j<w; j++) {
            if (s[i][j]=='.') {
                cnt++;
            }
        }
        if (cnt == w) {
            a[i]=1;
        }
    }
    for(int i = 0; i<w; i++){
        int cnt = 0;
        for (int j = 0; j<h; j++) {
            if (s[j][i]=='.') {
                cnt++;
            }
        }
        if (cnt == h) {
            b[i]=1;
        }
    }
    for (int i = 0; i<h; i++) {
        int cnt = 0;
        for (int j = 0; j<w; j++) {
            if (a[i]==0&&b[j]==0) {
                cnt = 1;
                printf("%c", s[i][j]);
            }
        }
        if (cnt) {
            printf("\n");
        }
    }
}