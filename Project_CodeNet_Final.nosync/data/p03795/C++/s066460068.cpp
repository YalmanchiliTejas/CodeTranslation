#include <bits/stdc++.h>

#define INF 1 << 29
#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)

using namespace std;

typedef pair<int,int> pii;
typedef long long int ll;

void gen_sosuu(int sosuu[]){
  REP(i,100010){
    sosuu[i] = true;
  }
  sosuu[0] = false;
  sosuu[1] = false;
  sosuu[2] = true;
  FOR(i,2,sqrt(100000)+1){
    if(sosuu[i] == false) continue;
    for(int j = 2; i*j<=100000;j++){
      //printf("%d %d %d\n",i*j,i,j);
      sosuu[i*j] =false;
    }
  }
}

int n;

int main(){
  scanf("%d",&n);
  printf("%d\n",n*800-n/15*200);
}
