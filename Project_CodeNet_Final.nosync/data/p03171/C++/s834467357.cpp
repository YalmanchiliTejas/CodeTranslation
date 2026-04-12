#include <bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define x first
#define y second
#define pb push_back
#define ll long long
#define int ll
#define ld long double
#define ii pair<int, int>
#define iii pair<int, ii>
#define vi vector<int>
#define vii vector<ii>
#define pq priority_queue
using namespace std;
const int ms = 4000;
const int mod = 1e9+7;
const int inf = 1e9;
const int sigma = 30;
int n, m, k, t = 1;
string s;

int ele[ms];

bool seen[ms][ms][2];
int dp[ms][ms][2];

int sol(int i, int j, int p){
  if(i==j) return p==0? ele[i]: -ele[i];

  if(seen[i][j][p]) return dp[i][j][p];
  seen[i][j][p] = 1;

  if(p==0){
    int val1 = ele[i] + sol(i+1, j, 1);
    int val2 = ele[j] + sol(i, j-1, 1);
    return dp[i][j][p] = max(val1, val2);
  }else{
    int val1 = -ele[i] + sol(i+1, j, 0);
    int val2 = -ele[j] + sol(i, j-1, 0);
    return dp[i][j][p] = min(val1, val2);
  }
}

void solve(){
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>ele[i];
  }
  cout<<sol(0, n-1, 0)<<endl;
}

int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while(t--){
    solve();
  }
}