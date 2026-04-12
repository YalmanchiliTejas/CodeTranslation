#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int,int> P;
P T[200];
int J[1001];
int main(){
  int i = 0;
  while(1){
    int t,p;
    scanf("%d,%d",&t,&p);
    if(!t && !p) break;
    T[i]=P(p,t);
    i++;
  }
  sort(T,T+i);
  int rank=0;
  int tmp = 50;
  for(int j=i-1;j>-1;j--){
    if(tmp > T[j].first){
      rank++;
      tmp = T[j].first;
    }
    J[T[j].second]=rank;
  }
  int id;
  while(~scanf("%d",&id)){
    printf("%d\n",J[id]);
  }
}