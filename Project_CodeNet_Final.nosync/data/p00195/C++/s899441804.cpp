#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef unsigned int uint;
typedef long long ll;

#define MAX 1000001
int main(){
  int a,b;
  
  while(scanf("%d%d",&a,&b),a+b){
    vector<pair<int,int> > v;
    v.push_back(mp(a+b,0));
    REP(i,4){
      scanf("%d%d",&a,&b);
      v.push_back(mp(a+b,i+1));
    }
    sort(v.rbegin(), v.rend());
    printf("%c %d\n",'A'+v[0].s, v[0].f);
  }

  return 0;
}