#include<bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, a[N], res[N];

int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  int now = 1, l = 1, r = n;
  for(int i = n; i >= 1; --i){
    if(now){
      res[l++] = a[i];
    }
    else{
      res[r--] = a[i];
    }
    now ^= 1;
  }
  for(int i = 1; i <= n; ++i){
    printf("%d%c", res[i], i == n ? '\n' : ' ');
  }
  return 0;
}
