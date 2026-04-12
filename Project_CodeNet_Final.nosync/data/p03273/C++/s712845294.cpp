#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stdio.h>
#include <stack>
#include <queue>
#include <deque>
#include <numeric>
#define MAX 100000007
using namespace std;
using ll = long long;
map <int ,int> mpa,mpb;
typedef pair<ll, ll> P;
priority_queue<P, vector<P>, greater<P>> pque;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int H,W;
  cin >> H >> W;
  char c;
  int a[101][101]={0};
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> c;
      if(c=='#'){
        a[i][j]=1;
      }else{
        a[i][j]=5;
      }
    }
  }
  for(int i=0;i<H;i++){
    bool flag=true;
    for(int j=0;j<W;j++){
      if(a[i][j]==1) flag=false;
    }
    if(flag){
      for(int k=0;k<W;k++){
        a[i][k]=0;
      }
    }
  }
  for(int i=0;i<W;i++){
    bool flag=true;
    for(int j=0;j<H;j++){
      if(a[j][i]==1) flag=false;
    }
    if(flag){
      for(int k=0;k<H;k++){
        a[k][i]=0;
      }
    }
  }
  for(int i=0;i<H;i++){
    bool flag=false;
    for(int j=0;j<W;j++){
      if(a[i][j]!=0){
        if(a[i][j]==1){
          cout << '#';
          flag =true;
        }if(a[i][j]==5){
          cout << '.';
        }
      }
    }
    if(flag){
      cout << endl;
    }
  }
  return 0;
}
