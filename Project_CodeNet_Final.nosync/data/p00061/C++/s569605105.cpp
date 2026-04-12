#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<climits>
#include<cmath>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()

typedef unsigned int uint;
typedef long long ll;

using namespace std;

int main(){
  vector<int> v[31];
  int a,b;
  int m = 0;
  while(scanf("%d,%d",&a,&b),a+b){
    v[b].push_back(a);
    m = max(m, a);
  }
  vector<int> ans(m+1);
  int tmp = 1;
  for(int i=30; i>=0; i--){
    REP(j,v[i].size()){
      ans[v[i][j]] = tmp;
    }
    if(v[i].size() != 0) tmp++;
  }
  while(~scanf("%d",&a))
    printf("%d\n",ans[a]);
  return 0;
}