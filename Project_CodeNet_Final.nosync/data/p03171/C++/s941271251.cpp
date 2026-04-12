#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define ll long long
#define s second
#define f first

const int MAX_N=3005;
int n;
ll a[MAX_N],dp[MAX_N][MAX_N];
bool turn=true;

int main(){
  cin >> n;
  for(int i=0;i<n;++i){
    cin >> a[i];
    dp[i][i]=a[i];
  }
  for(int i=1;i<n;++i){
    turn=!turn;
    for(int j=0;j+i<n;++j){
        int l=j,r=j+i;
        if(i==1){
            dp[l][r]=-abs(a[l]-a[r]);
            continue;
        }
        if(!turn){
            dp[l][r]=min(-a[l]+dp[l+1][r],-a[r]+dp[l][r-1]);
        }else{
            dp[l][r]=max(a[l]+dp[l+1][r],a[r]+dp[l][r-1]);
        }
    }
  }
  if(n%2==0){
    cout << -dp[0][n-1] << endl;
  }else{
   cout << dp[0][n-1] << endl;
  }
  return 0;
}