#include <iostream>
#include <deque>
#include <vector>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

#define i64 long long
#define ui64 unsigned long long
#define REP(i,n) for(int (i)=0;(i)<(n);i++)
#define REP2(i,k,n) for(int (i)=(k);(i)<(n);i++)
#define MDIST(a,b) abs(a-b)
#define DIST(a,b) sqrt((a)*(a)+(b)*(b))
#define ATCODER 1000000007
using namespace std;
 
////////////////////////

int main(){
  int n,t,e;
  cin >> n >> t >> e;
  int a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<n;i++){
    if((t%a[i])<=e||(t/a[i]*a[i]+a[i])<=(t+e)){
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}