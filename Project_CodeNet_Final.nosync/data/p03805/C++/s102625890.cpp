#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
#include<numeric>
#include<set>
#include<string>
#include<utility>
#include<vector>

#define rep(i, a, n)  for(int i=a; i<n; i++)
#define per(i, a, n)  for(int i=n-1; i>=a; i--)
#define fill0(n)  setfill('0') << right << setw(n)
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MAX 1000000000
using namespace std;
typedef long long ll;

int n, m;
int ans = 0;
vector<bool> visited(8, false);
vector<vector<bool>> vec(8, vector<bool>(8, false));
void dfs(int p){
  bool all_visited = true;
  rep(i, 0, n){
    if(!visited[i]){
      all_visited = false;
    }
  }
  if(all_visited){
    ans++;
    return;
  }

  rep(i, 0, n){
    if(!vec[p][i] || visited[i])  continue;
    visited[i]=true;
    dfs(i);
    visited[i]=false;
  }
  return ;
}

int main(){
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, 0, m){
    cin >> a[i] >> b[i];
    a[i]--;  b[i]--;
    vec[a[i]][b[i]] = true;
    vec[b[i]][a[i]] = true;
  }

  rep(i, 0, n)  visited[i] = false;
  visited[0]=true;
  dfs(0);

  cout << ans << endl;
  return 0;
}