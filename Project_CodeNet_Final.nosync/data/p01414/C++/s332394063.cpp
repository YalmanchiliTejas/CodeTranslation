#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1e9;
 
int main(){
    int n;
    cin >> n;
    vector<int> h(n),w(n);
    for(int i=0; i<n; i++) cin >> h[i] >> w[i];
    char c[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin >> c[i][j];
        }
    }
     
    vector<int> dp(1<<16, inf);
    dp[0] = 0;
    for(int i=0; i<(1<<16); i++){
        if(dp[i] == inf) continue;
        for(int s=0; s<n; s++){
            for(int y=1-h[s]; y<=3; y++){
                for(int x=1-w[s]; x<=3; x++){
                    char color = 0;
                    int newidx = i;
                    int sy=max(y,0), sx=max(x,0);
                    int gy=min(y+h[s],4), gx=min(x+w[s],4);
                    for(int j=sy; j<gy; j++){
                        for(int k=sx; k<gx; k++){
                            if((i & 1<<(4*j +k)) != 0) continue;
                            if(color!=0 && color!=c[j][k]){
                                color = 0;
                                j = gy;
                                break;//j,k
                            }
                            color = c[j][k];
                            newidx |= 1<<(4*j +k);
                        }
                    }
                    if(color != 0){
                        dp[newidx] = min(dp[newidx], dp[i]+1);
                    }
                }
            }
        }
    }
    cout << dp[(1<<16) -1] << endl;
    return 0;
}
