#include <bits/stdc++.h>
//---------------------------
using namespace std;
//---------------------------
#define REP(i,n) for(int i = 0; i < (n); i++)
#define P(x) cout << (x) << "\n"

#define MOD 1000000007 // 1e9+7
#define PI acos(-1.0)
#define ll long long int // 10^18
#define INF 1000000001 // 1e9+1

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
//---------------------------

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  int n;cin>>n;
  int get_money=(n/15)*200;
  P(n*800 - get_money);
  return 0;
}
