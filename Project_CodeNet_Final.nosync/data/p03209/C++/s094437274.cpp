//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;

long long a[61];
long long p[61];

long long f(int j, long long x){
  if(x == 1){
    if(j == 0) return 1;
    else return 0;
  }
  if(x <= 1+a[j-1]) return f(j-1,x-1);
  if(x == 2+a[j-1]) return p[j-1]+1;
  if(x <= 2+2*a[j-1]) return p[j-1]+1+f(j-1,x-2-a[j-1]);
  if(x == 3+2*a[j-1]) return 2*p[j-1]+1;
  return 0;
}

int main(){
  int n;
  long long x;
  a[0] = 1;
  p[0] = 1;
  for(int i=0;i<60;i++){
    a[i+1] = 2*a[i]+3;
    p[i+1] = 2*p[i]+1;
  }
  cin >> n >> x;
  cout << f(n,x) << endl;

  return 0;
}
