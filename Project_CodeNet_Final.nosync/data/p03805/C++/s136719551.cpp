#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
#include<set>
#include<map>
#include<math.h>
#include <numeric>

using namespace std;

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) for(int i=0; i<n; i++)

typedef long long int ll;

int main(){
  int n,m,a,b;
  scanf("%d %d",&n,&m);
  vector<pair<int,int>> edge(m);
  REP(i,m){
    scanf("%d %d",&a,&b);
    edge[i] = make_pair(a,b);
  }
  vector<int> perm(n-1);
  REP(i,n-1)perm[i]=i+2;
  int sum=0;
  int flag;
  do{
    if(count(edge.begin(),edge.end(),make_pair(1,perm[0]))==1){
      flag = 0;
      REP(i,n-2){
        if(count(edge.begin(),edge.end(),make_pair(perm[i],perm[i+1]))==1 || count(edge.begin(),edge.end(),make_pair(perm[i+1],perm[i]))==1) flag++;
      }
      if(flag==n-2) sum++;
    }
  }while(next_permutation(perm.begin(), perm.end()));

  printf("%d",sum);
  return 0;
}
