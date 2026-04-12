#include<bits/stdc++.h>
using namespace std;
int dp[105][4][2];
int main (){
    string N;
    int k;
    cin >> N >> k;
    

    int l=N.size();
    
    dp[0][0][0]=1;
    for(int i=0; i<l; i++){
        for(int j=0; j<4; j++){
            for(int smaller=0; smaller<2; smaller++){
                int x_ = N[i] - '0';
                for(int x=0; x < 10;x++){
                    //cout << x<< endl;
                   int i_ = i+1;
                   int j_ = j;
                   int smaller_ =smaller ;

                   if(x!=0) j_++;
                   if(j_>k) continue;

                   if(smaller_==0){
                       if(x_<x) continue;
                       else if(x<x_) smaller_ = 1;

                   }
                   dp[i_][j_][smaller_]+=dp[i][j][smaller];
                }
            }
        }
    }
    
    cout << dp[l][k][0] + dp[l][k][1]  <<endl;

    return 0;

}