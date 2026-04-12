#include <bits/stdc++.h>
using namespace std;
char s[105][105];
int h,w,ok,sh[105],sw[105],hx,wx;
int main() {
    cin>>h>>w;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin>>s[i][j];
        }
    }
    hx=0;
    for (int i = 0; i < h; ++i) {
        ok=1;sh[hx]=i;
        for (int j = 0; j < w; ++j) {
            if(s[i][j]=='#') {
                ok=0;break;
            }
        }
        if(ok==0) hx++;
    }
    wx=0;
    for (int j = 0; j < w; ++j) {
        ok=1;sw[wx]=j;
        for (int i = 0; i < h; ++i) {
            if(s[i][j]=='#') {
                ok=0;break;
            }
        }
        if(ok==0) wx++;
    }
    for (int i = 0; i < hx; ++i) {
        for (int j = 0; j < wx; ++j) {
            cout<<s[sh[i]][sw[j]];
        }cout<<endl;
    }
    return 0;
}