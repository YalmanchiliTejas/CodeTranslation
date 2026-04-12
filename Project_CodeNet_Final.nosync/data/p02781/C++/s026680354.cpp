#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int dp[103][2][4];
int main(){
    string n;
    cin >> n;
    int t;
    cin >> t;
    int digit=n.size();
    int hi=n[0]-'0';
    if(digit==1){
        if(t>1){
            cout << 0 << endl;
            return 0;
        }
        cout << hi << endl;
        return 0;
    }
    dp[1][0][1]=hi-1;
    dp[1][1][1]=1;
    dp[1][0][0]=1;
    for(int i=2; i<=digit; i++){
        for(int k=0; k<=min(i,3); k++){
            if(k==0){
                dp[i][0][0]=dp[i-1][0][0];
                continue;
            }
            if(n[i-1]=='0'){
                dp[i][0][k]=dp[i-1][0][k]+dp[i-1][0][k-1]*9;
                dp[i][1][k]=dp[i-1][1][k];
            }
            else{
                dp[i][1][k]=dp[i-1][1][k-1];
                dp[i][0][k]=dp[i-1][0][k]+dp[i-1][0][k-1]*9+dp[i-1][1][k]+dp[i-1][1][k-1]*(n[i-1]-'1');
            }
        }
    }
    cout << dp[digit][0][t]+dp[digit][1][t] << endl;
    return 0;
}