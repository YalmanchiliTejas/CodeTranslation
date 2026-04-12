#include <bits/stdc++.h>
// #include "bits/stdc++.h"

#define rep(i,a,n) for (int i = a;i < n;i++)
#define per(i,n,a) for (int i = n-1;i >= a;i--)
 
typedef long long ll;
using namespace std;
 
int main(){
  int x,y,z;

  cin >> x >> y >> z;

  for(int i = 1; ; i++){
    int a = y*i + z*(i+1);

    if(a > x){
      printf("%d\n", i-1);
      return 0;
    }
  }
  return 0;
}