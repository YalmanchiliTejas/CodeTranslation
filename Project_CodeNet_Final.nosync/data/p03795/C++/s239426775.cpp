#include <bits/stdc++.h>
// #include "bits/stdc++.h"

#define rep(i,a,n) for (int i = a;i < n;i++)
#define per(i,n,a) for (int i = n-1;i >= a;i--)
 
typedef long long ll;
using namespace std;
 
int main(){
  int n,a;
  cin >> n;
  a = (n/15)*200;
  
  printf("%d\n",800*n-a);
  return 0;
}