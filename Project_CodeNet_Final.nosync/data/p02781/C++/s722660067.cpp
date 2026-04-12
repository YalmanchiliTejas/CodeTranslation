#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;


 
int main(){
    string n;
    int K;
    cin >> n >> K;
    int p = n.size();
    long dp[p+10][4][2];//桁数、０でない個数、N超えてるか判定(０でわからん、１でOK）
    
    //初期化
    for(int i=0;i<p+1;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<2;k++) dp[i][j][k]=0;
        }
    }
    dp[0][0][0]=1;
    //桁見ていく
    for(int i=0;i<p;i++){
        int lead=n.at(i)-'0';
        for(int j=0;j<4;j++){
            for(int k=0;k<2;k++) {
                
                //次の桁の数
                for(int a=0;a<10;a++){
                    int ni,nj,nk;
                    ni=i+1;
                    nj=j;
                    nk=k;
                    if(a!=0){
                        nj++;
                    }
                    if(nj>K){
                        continue;
                    }
                    if(k==0 && a<lead){
                        nk=1;
                    }
                    if(k==0 && a>lead){
                        continue;
                    }
                    
                    dp[ni][nj][nk]+=dp[i][j][k];
                }
            }
        }
    }
    cout << dp[p][K][0]+dp[p][K][1] << endl;
}

    

