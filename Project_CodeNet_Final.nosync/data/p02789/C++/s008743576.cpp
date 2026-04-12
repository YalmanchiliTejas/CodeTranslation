#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = (int)1e9+7;
const ll INF = MOD*MOD;
ll n,m,k,ans;
string s,t;
const ll powll = 1LL<<1;

bool cmp(P a, P b){
  return a.first+a.second < b.first+ b.second;
}

int main(void){
  int a,b; cin >> a >> b;
  if(a == b) cout << "Yes\n";
  else cout << "No\n";
}