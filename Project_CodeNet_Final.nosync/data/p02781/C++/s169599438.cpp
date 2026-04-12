#include <iostream>
#include <string>
#include <cstring>
using namespace std;


#define REP(var, init, num) for(int var = init ; var < num; var ++)

int main(){
    string n;
    int k;

    cin >> n;
    cin >> k;

    int dig = n.size();
    int dp0[dig+1][k+2];
    int dp1[dig+1][k+2];
    
    memset(dp0, 0, sizeof(int)*(dig+1)*(k+2));
    memset(dp1, 0, sizeof(int)*(dig+1)*(k+2));
    dp1[0][0] = 1;

    for(int i=1; i<=dig; i++){
        int hi = stoi(n.substr(i-1,1));

        for(int j=0; j<=9; j++){
                if(j < hi){
                    if(j == 0){
                        REP(jj, 0, k+2) {
                            dp0[i][jj] += dp0[i-1][jj];
                            dp0[i][jj] += dp1[i-1][jj];
                        }
                    }else{
                        REP(jj, 0, k){
                            dp0[i][jj+1] += dp0[i-1][jj];
                            dp0[i][jj+1] += dp1[i-1][jj];
                        }
                        dp0[i][k+1] += dp0[i-1][k+1];
                        dp0[i][k+1] += dp1[i-1][k+1];
                    }
                }else if(j == hi){
                    if(j == 0){
                        REP(jj, 0, k+2) {
                            dp0[i][jj] += dp0[i-1][jj];
                            dp1[i][jj] += dp1[i-1][jj];
                        }
                    }else{
                        REP(jj, 0, k){
                            dp0[i][jj+1] += dp0[i-1][jj];
                            dp1[i][jj+1] += dp1[i-1][jj];
                        }
                        dp0[i][k+1] += dp0[i-1][k+1];
                        dp1[i][k+1] += dp1[i-1][k+1];
                    }
                }else{
                    REP(jj, 0, k) {
                        dp0[i][jj+1] += dp0[i-1][jj];
                    }
                    dp0[i][k+1] += dp0[i-1][k+1];
                }
            
        }
    }

    cout << (dp0[dig][k] + dp1[dig][k]) << endl;

    return 0;
}