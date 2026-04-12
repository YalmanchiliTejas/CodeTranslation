#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    //freopen("input.txt","r",stdin);
    lli n;
    cin >> n;
    vector <lli> v(n);
    for(int i =0;i<n;i++)cin >> v[i];
    vector < vector <lli> > dp(n,vector <lli> (n));
   for(int i =n-1;i>=0;i--){
    for(int j =i;j<n;j++){
        if(i == j){
            dp[i][i] = v[i];
        }else{
            dp[i][j] = max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
        }
    }
   }
    cout << dp[0][n-1]<<endl;
}
