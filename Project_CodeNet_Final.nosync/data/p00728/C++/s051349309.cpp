//#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <climits>

using namespace std;
using ll=long long;

void solve(){
  while(true){
  int num;
  cin >> num;if(num==0){return;}
  int ma=0,mi=10000,sum=0;
  for(int i=0;i<num;i++){
    int c=0;
    cin >> c;
    ma=max(ma,c);
    mi=min(mi,c);
    sum+=c;
  }
  cout << (sum-ma-mi)/(num-2) << endl;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int roop=1;
  while(roop--)
    solve();
  return 0;
}

