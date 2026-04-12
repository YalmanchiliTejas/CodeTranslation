#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const int INF=1e7;
const LL LINF=1e18;

int main(){
    int H,W;
    cin >> H >> W;
    char s[H][W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> s[i][j];
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(s[i][j]=='#'){
                if(s[i-1][j]=='#'&&s[i][j-1]=='#'&&i-1>0&&j-1>0){
                    puts("Impossible");
                    return 0;
                }
                if(s[i+1][j]=='#'&&s[i][j+1]=='#'&&i+1>0&&j+1>0){
                    puts("Impossible");
                    return 0;
                }
            }
        }
    }
    puts("Possible");
    return 0;
}