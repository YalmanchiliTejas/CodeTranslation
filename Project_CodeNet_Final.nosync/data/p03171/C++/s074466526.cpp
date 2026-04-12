#include <bits/stdc++.h>
using namespace std;
long long dp[3001][3001];
long long a[3001];
long long game(int i, int j,  int c){
   // cout<<i<<" "<<j<<" "<<x<<" "<<y<<endl;
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    long long ans;
    if(i > j){
      //  cout<<x<<" "<<y<<"%%%%5"<<endl;
        return 0;
    }
    else{
        if(c%2 == 0){
            //if(i == j)return (x + a[i] - y);
             ans = max(game(i + 1, j, c + 1) + a[i], game(i, j-1,  c + 1) + a[j]);
         //    cout<<game(i + 1, j, x + a[i], y, c + 1)<<"****"<<game(i, j-1, x + a[j], y, c + 1)<<endl;
        }else{
            //if(i == j)return (x - y - a[i]);
             ans = min(game(i + 1, j,  c+1) - a[i], game(i, j -1,  c + 1) - a[j]);
         //    cout<<game(i + 1, j, x , y + a[i], c + 1)<<"****"<<game(i, j-1, x , y + a[j], c + 1)<<endl;
        }
    }
  //  cout<<i<<"#"<<j<<"#"<<c<<"#"<<ans<<endl;
    dp[i][j] = ans;
    return ans;
}

int main(){
    long long mod = 1000000007;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    //vector<int> a(n, 0);
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<game(0, n-1,  0)<<endl;
    return 0;
}