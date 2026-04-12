#include <bits/stdc++.h>
//---------------------------
using namespace std;
//---------------------------
// #define REP(i,n) for(int i = 0; i < (n); i++)
// #define P(x) cout << (x) << "\n"

// #define MOD 1000000007 // 1e9+7
// #define PI acos(-1.0)
// #define ll long long int // 10^18
// #define INF 1000000001 // 1e9+1

// int dx[4]={1,-1,0,0};
// int dy[4]={0,0,1,-1};
//---------------------------

bool p[8][8]; int n,m,a,b;
int main(){
  // std::ios::sync_with_stdio(false);
  // std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());
  cin>>n>>m;
  for(int i=0; i<m; i++) {cin>>a>>b; a--; b--; p[a][b]=true; p[b][a]=true;}
  int G[8]={0,1,2,3,4,5,6,7};
  int cnt=0;
  do {
    if(G[0]!=0) continue;
    bool OK=true;
    for(int i=1; i<n; i++) {
      if(p[G[i-1]][G[i]]==false) OK=false;
    }
    if(OK==true) cnt++;
  } while(next_permutation(G,G+n));
  cout<<cnt<<endl;
  return 0;
}
