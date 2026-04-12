#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

bool graph[55][55];
bool seen[55];

void dfs(int i,int n){
  seen[i] = true;
  for(int j = 0;j < n;j++){
    if(graph[i][j] == false) continue;
    if(seen[j] == true) continue;
    dfs(j,n);
  }
  return;
}

int main(){
  int n;cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  sort(a.rbegin(),a.rend());
  ll ans = 0;
  ll sum = 0;
  if(n%2==1){
    rep(i,n/2) ans += 2*a[i];
    for(int i = n/2;i<n;i++) ans -= 2*a[i];
    ans += a[n/2] + a[n/2+1];

    rep(i,n/2+1) sum += 2*a[i];
    for(int i = n/2+1;i<n;i++) sum -= 2*a[i];
    sum -= a[n/2-1] + a[n/2];
    ans = max(ans,sum);
  }else{
    rep(i,n/2) ans += 2*a[i];
    for(int i = n/2;i<n;i++) ans -= 2*a[i];
    ans -= a[n/2-1];
    ans += a[n/2]; 
  }
  cout << ans << endl;

}