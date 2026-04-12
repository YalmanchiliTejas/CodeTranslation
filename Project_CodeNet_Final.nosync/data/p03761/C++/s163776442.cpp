#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>


#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))

using namespace std;
int n;
int a[60][30];

int main(){
  cin >> n;
  REP(i,n){
    string s;
    cin >> s;
    REP(j,s.size()){
      a[i][s[j]-'a'] ++;
    }
  }
  REP(i,'z'-'a'+1){
    int k = 1000;
    REP(j,n){
      k = min(k,a[j][i]);
    }
    char t = (int)((int)'a'+i);
    REP(j,k) cout << t;
  }
  cout << endl;
  return 0;
}
