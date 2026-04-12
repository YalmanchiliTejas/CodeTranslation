#include <bits/stdc++.h>
// #include "bits/stdc++.h"

#define rep(i,a,n) for (int i = a;i < n;i++)
#define per(i,n,a) for (int i = n-1;i >= a;i--)
 
typedef long long ll;
using namespace std;
 
int main(){
  int r,g,b,ans;
  cin >> r >> g >> b;

  ans = (r*100 + g*10 + b)%4;

  if(ans == 0){
    printf("YES\n");
  }
  else printf("NO\n");
  return 0;
}