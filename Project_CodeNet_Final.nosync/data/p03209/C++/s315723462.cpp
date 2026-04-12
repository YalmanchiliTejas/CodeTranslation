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

ll n,x;

ll b[55],p[55];

ll dfs(ll i,ll j){
  if(i == 0){
    if(j < 1) return 0;
    else return 1;
  }
  else if(j<=1) return 0;
  else if(1 < j && j <= 1 + b[i-1] + p[i-1]) return dfs(i-1,j-1);
  else if(j == b[i-1] + p[i-1] + 2) return p[i-1]+1;
  else if(b[i-1] + p[i-1] + 2< j && j <= b[i] + p[i] - 1) return dfs(i-1,j - (2 + b[i-1] + p[i-1])) + p[i-1] + 1;
  else if(b[i] + p[i] <= j) return p[i];

}

int main(){
  cin >> n >> x;
  b[0] = 0;
  p[0] = 1;
  for(int i = 1; i < 55; i++){
    b[i] = 2*b[i-1] + 2;
    p[i] = 2*p[i-1] + 1;
  }
  cout << dfs(n,x) <<endl;
  return 0;
}
