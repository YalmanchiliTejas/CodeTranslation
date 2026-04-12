#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(int i=0;i<(int)(n);i++)

int n,q;

int main(){
  scanf("%d%d",&n,&q);
  int head = 0;
  while(q--){
    int typ, k;
    scanf("%d%d",&typ,&k);
    k--;
    if(typ==0){
      printf("%d\n",(head+k)%n + 1);
    }else{
      head = (head+k+1)%n;
    }
  }
  return 0;
}
