#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MOD 1000000007

ll p[55],b[55];
ll n,x;

ll dfs(ll i, ll j){
  if(i == 0){
    if(j < 1) return 0;
    else return 1;
  }
  if(j < 1) return 0;
  if(j <= p[i-1] + b[i-1] + 1) return dfs(i-1,j-1);
  if(j == p[i-1] + b[i-1] + 2) return p[i-1] + 1;
  if(j <= p[i] + b[i] - 1) return p[i-1] + 1 + dfs(i-1,j-(p[i-1] + b[i-1] + 2));
  else return p[i];

}

int main(){
  cin >> n >> x;
  p[0] = 1;
  b[0] = 0;
  for(int i = 0; i < 51; i++){
    p[i+1] = (p[i]<<1) + 1;
    b[i+1] = (b[i]<<1) + 2;
  }
  cout << dfs(n,x) << endl;
  return 0;
}