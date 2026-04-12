#include<bits/stdc++.h>
using namespace std;
int dp[101][4][2];
int main (){
    string N;
    int k;
    cin >> N >> k;
    vector<int> n(100,0);
    int l=N.size();
    for(int i=0;i<l;i++)
    n[i]=N[i]-'0';

    dp[0][0][0]=1;
    for(int i=0; i<l; i++){
        for(int j=0; j<4; j++){
            for(int smaller=0; smaller<2; smaller++){
                
                for(int x=0; x <= (smaller ? 9 : n[i]);x++){
                    //cout << x<< endl;
                   if(x==0) dp[i+1][j][smaller || (x<n[i])] += dp[i][j][smaller];
                   else if(j==3) continue;
                   else dp[i+1][j+1][smaller || (x<n[i])] += dp[i][j][smaller];
                }
            }
        }
    }
    
    cout << dp[l][k][0] + dp[l][k][1]  <<endl;

    return 0;

}