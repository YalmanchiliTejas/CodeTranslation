#include <bits/stdc++.h>
#define ll long long int
#define FASTIO std::ios::sync_with_stdio(false);
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define input_from_file  freopen("input.txt", "r", stdin);
using namespace std;

struct pa{
  ll f, s;
};

int main()
{
FASTIO
//input_from_file

int n;
cin >> n;

ll a[n];
for(int i = 0; i < n; i++){
  cin >> a[i];
}

pa dp[n][n];

for(int i = 0; i < n; i++){
  for(int j = 0; j < n; j++){

    if(j < i){
      dp[i][j].f = 0;
      dp[i][j].s = 0;
    }

    else if(i == j){
      dp[i][j].f = a[i];
      dp[i][j].s = 0;
    }
  }
}

int i = 0;
while(i < n - 1){
  int temp = 0, j = i + 1, cnt = n - i -1;

  while(cnt > 0){

    dp[temp][j].f = max(dp[temp + 1][j].s + a[temp], dp[temp][j - 1].s + a[j]);

    if(dp[temp + 1][j].s + a[temp] > dp[temp][j - 1].s + a[j]){
      dp[temp][j].s = dp[temp + 1][j].f;
    }

    else{
      dp[temp][j].s = dp[temp][j - 1].f;
    }

    cnt--; temp++; j++;
  }

  i++;
}

ll ans = dp[0][n - 1].f - dp[0][n - 1].s;

cout << ans;
}
