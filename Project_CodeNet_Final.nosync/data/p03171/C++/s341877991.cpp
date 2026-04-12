#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,N) for(int i=0;i<N;i++)
typedef long long ll;

ll dp[3300][3300];


int main(){
  int N;
  cin>>N;
  ll a[N];
  rep(i,N) cin>>a[i];


  for (int width = 1; width<=N; width++){
    for(int i = 0; i + width <= N; i++){
        int r=i+width;
        if(width % 2 == N%2){
          dp[i][r] = max(dp[i+1][r] + a[i],dp[i][r-1] + a[r-1]);
        }else{
          dp[i][r] = min(dp[i+1][r] - a[i], dp[i][r-1] - a[r-1]);
        }
    }
  }

cout<< dp[0][N];

}
