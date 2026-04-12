#include<bits/stdc++.h>
#include <time.h> 
#define ll long long int
#define F first
#define S second
#define pb push_back
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sdl(x) scanf("%lld",&x)
#define sd2l(x,y) scanf("%lld%lld",&x,&y);
#define sz(x) (int)(x.size())
#define nax 100010
#define inf 1001000100
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define mp make_pair
#define pc pair<char ,int>
#define pi pair<int ,int>
#define pii pair <pi,pi>
using namespace std;
ll dp[3003][3003]; 
ll sum[3003];
int arr[3003];
int main(int argc, char const *argv[])
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int n,a,b;
  sd(n);
  for(int i = 1; i <= n; i++)
  {
    sd(arr[i]);
    dp[i][i] = arr[i];
    sum[i] = sum[i] + sum[i - 1]  + arr[i];
  }
  for(int i = 2; i <= n; i++) // size
  {
      for(int j = 1; j + i - 1 <= n; j++)
          dp[j][i + j - 1] = max(sum[i + j - 1] - sum[j] - dp[j + 1][i + j - 1] + arr[j], sum[i + j - 2] - sum[j - 1] - dp[j][i + j - 2] + arr[i + j - 1]);
  }
  cout << 2 * dp[1][n] - sum[n]<< '\n';
  return 0;
} 