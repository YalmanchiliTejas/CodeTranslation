#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long 
using namespace std;

ll dp[3050][3050];
int n;
ll a[3050];

ll solve(int i, int f){
  if(i == f)
    return a[i];
  
  if(dp[i][f] != -1)
    return dp[i][f];

  return dp[i][f] = max(a[i] - solve(i+1, f), a[f] - solve(i, f-1));
}

int main()
{
    cin >> n;
    memset(dp, -1, sizeof dp);

    for(int i = 0; i < n; i++){
      cin >> a[i];
    }

    cout << solve(0, n-1) << endl;

    return 0;
}