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

using namespace std;
using ll=long long;

void solve(){
  int h,w;
  cin >> h >> w;
  vector<string> gred(h);
  for(int i=0;i<h;i++)
    cin >> gred[i];
  vector<int> hind;
  std::vector<int> wind;
  for(int i=0;i<h;i++){int ct=0;
    for(int j=0;j<w;j++)
      if(gred[i][j]!='.')ct++;
    if(ct==0)hind.push_back(i);
  }
  for(int j=0;j<w;j++){int ct=0;
    for(int i=0;i<h;i++)
      if(gred[i][j]!='.')ct++;
    if(ct==0)wind.push_back(j);
  }
  for(int i=0;i<h;i++){
    string str="";bool a=true;
    for(int j=0;j<hind.size();j++)
      if(i==hind[j])a=false;
    if(!a)continue;
    for(int j=0;j<w;j++){
      bool b=true;
      for(int k=0;k<wind.size();k++)
        if(j==wind[k])b=false;
      if(b)str+=gred[i][j];
    }
    cout << str << endl;
  }
}

int main(){
  solve();
  return 0;
}
