#include <bits/stdc++.h>
using namespace std;
const int MAX=10;

string S;
int a,b,c,d,H,W,last;
char f[MAX][MAX];

void solve(){
    H=W=0;
    for (char c:S){
        if (c=='/') ++H,W=0;
        else if (c=='b'){
            f[H][W++]='b';
        } else for (int i=0;i<c-'0';++i) f[H][W++]='.';
    }
    f[--a][--b]='.'; f[--c][--d]='b';
    for (int i=0;i<H+1;++i){
        last=-1;
        for (int j=0;j<W;++j) if (f[i][j]=='b'){
            if (j-last-1) cout << j-last-1;
            cout << 'b';
            last=j;
        }
        if (W-last-1) cout << W-last-1;
        if (i!=H) cout << '/';
    }
    cout << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(cin >> S,S!="#"){
        cin >> a >> b >> c >> d;
        solve();
    }
}
