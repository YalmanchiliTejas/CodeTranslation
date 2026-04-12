#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int tl[22222];
int main(void){
  while(cin >> n >> m && n+m){
    for(int i = 1; i <= n+m; i++) cin >> tl[i];
    sort(tl,tl+n+m+1);
    int res = 0;
    for(int i = 1; i <= n+m; i++) res = max(res,tl[i]-tl[i-1]);
    cout << res << endl;
  }
}