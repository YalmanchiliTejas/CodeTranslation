#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <float.h>
#include <stdlib.h>
#include <functional>
#include <limits>
#include <numeric>
#include <type_traits>
#include <queue>
#include <fstream>
#include <bitset>
#include <cmath>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
#define sort1(v) sort(v.begin(),v.end())
#define reverse(v) reverse(v.begin(),v.end())
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> p;
bool paircom (pair<int,int> p,pair<int,int> q){
return p.second<q.second;
}

void count(vector<int> v,vector<int>& ans){
    sort1(v);
    int n=v.size();
  int k=1;
  int i=1;
  bool bl=true;
    while(true){
    while(bl){
        if(v[i-1]==v[i]){
        k++;    
      }else{
          bl=false;
      }
      i++;
      }
      ans.push_back(k);
      if(i>=(n-1))break;
      k=1;
      bl=true;
    }
    }




int main() {
    int a;
    cin >> a;
    if(a>=30){cout <<"Yes";}else{cout <<"No";}
    
}

    