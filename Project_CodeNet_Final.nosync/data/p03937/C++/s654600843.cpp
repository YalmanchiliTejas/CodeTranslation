#include "bits/stdc++.h"
using namespace std;
int main(){
    int h,w,i,j,k;
    cin >> h >> w;
    char c[h][w];
    for(i=0;i<h;i++) for(j=0;j<w;j++) cin >> c[i][j];
    int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
    int from,to,ans=1;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            from=0; to=0;
            for(k=0;k<4;k++){
                if(i+dy[k]<0||i+dy[k]>=h||j+dx[k]<0||j+dx[k]>=w) continue;
                if(c[i+dy[k]][j+dx[k]]=='#'){
                    if(k==0||k==2) to++;
                    else from++;
                }
            }
            if(from>=2||to>=2) ans = 0;
        }
    }
    if(ans) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}