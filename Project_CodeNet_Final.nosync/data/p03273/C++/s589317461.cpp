#define _GLIBCXX_DEBUG
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<string>
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define rep2(i,s,n) for(int i=s;i< (int)n; i++)
#define ll long long 
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
  int h,w; cin >>h>>w;
  vector<vector<char>> G(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >>G[i][j];
    }
  }
  rep(i,h){
    ll key=0;
    rep(j,w){
      if(G[i][j]=='.'){
        key++;
      }
    }
      if(key==w){
        G.erase(G.begin()+i);
        i--;
        h--;
      }
    }
  rep(i,w){
    ll key=0;
    rep(j,h){
      if(G[j][i]=='.'){
        key++;
      }
    }
    if(key==h){
      rep(k,h){
        G[k].erase(G[k].begin()+i);
      }
      w--;
      i--;
    }
  }
  rep(i,h){
    rep(j,w){
      if(j==w-1){
        cout <<G[i][j]<<endl;
      }else{
        cout <<G[i][j];
      }
    }
  }
    return 0;
}