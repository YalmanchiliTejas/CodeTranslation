#include<cstdio>
#include<bits/stdc++.h>

#define REP(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define FOR_IN(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
#define IN(x, a, b) ((x) >= (a) && (x) <= (b))

using namespace std;
//n m
int n,m;
vector<vector<bool> > connected(8, vector<bool>(8, false));
int perm[8];

int main(){
  cin >> n >> m;
  REP(i, m){
    int a,b;
    cin >> a >> b;
    connected[a-1][b-1]=true;
    connected[b-1][a-1]=true;
  }

  REP(i, n)
    perm[i]=i;

  int ans=0;
  do{
    if(perm[0]!=0)
      continue;
    bool f=true;
    REP(i, n-1){
      f = f && (connected[perm[i]][perm[i+1]]);
    }
    ans += f ? 1 : 0;
  }while(next_permutation(perm, perm+n));

  cout << ans << endl;

  return 0;
}
