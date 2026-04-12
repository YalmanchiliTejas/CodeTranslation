#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <tuple>
#include <bitset>
#include <random>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
  int h,w;
  cin>>h>>w;
  vector<vector<char>> ar(h,vector<char>(w));
  vector<bool> flag_row(h,false),flag_column(w,false);
  
  REP(i,h){
    REP(j,w){
      cin>>ar[i][j];
      if(ar[i][j]=='#'){
        flag_row[i]=true;
        flag_column[j]=true;
      }
    }
  }
  REP(i,h){
    REP(j,w){
      if(flag_row[i]&&flag_column[j]){
        cout<<ar[i][j];
      }
      if(j==w-1){
        cout<<endl;
      }
    }
  }

  
  return 0;
}