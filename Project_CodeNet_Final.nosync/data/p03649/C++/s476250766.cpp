#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

long long int ans = 0;
long long int n,x,y,z;

bool check(long long int* a){
  long long int u,b;
  u = 0;  b = 10000000000002000;
  for(int i=0;i<n;i++){
    if(a[i] > u){
      u = a[i];
      y = i;
    }
    if(a[i] < b){
      b = a[i];
      x = i;
    }
  }
  z = ( u - b ) / (n + 1);

  return ( u - b >= n + 1 );
}

void sub(long long int* a){
  for(int i=0;i<n;i++){
    if(i == y)
      a[i] -= n * z;
    else
      a[i] += z;
  }
  ans += z;
}


int main()
{
  cin >> n;
  long long int a[50]={};

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  //minとmaxの差を埋める
  while(check(a)){
    sub(a);
  }

  //minを下げる
  if(a[x] >= n){
    long long int tmp = a[x] + 1 - n;
    for(int i=0;i<n;i++)
      a[i] -= tmp;
    ans += tmp * n;
  }

  //あとは普通にやる
  while(true){
    sort(a,a+n);
    if(a[n-1]<n)
      break;

    for(int i=0;i<n;i++){
      if(i != n-1)
        a[i] ++;
      else
        a[i] -= n;
      }
      ans++;
  }

  cout << ans << endl;

  return 0;
}