#include <iostream>
#include <algorithm>

using namespace std;

int solve(){
  int n, l, r;
  int a[100];
  
  scanf("%d%d%d", &n, &l, &r);
  if(!n) return 0;
  
  for(int i=0;i<n;i++){
    scanf("%d", a+i);
  }

  int ans = 0;
  
  for(int i=l;i<=r;i++){
    int t = n;
    for(int j=0;j<n;j++){
      if(i % a[j] == 0){
        t = j;
        break;
      }
    }

    ans += t%2 == 0;
  }

  printf("%d\n", ans);
  
  return 1;
}

int main(){
  while(solve());
}

