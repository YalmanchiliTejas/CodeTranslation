#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <cstdio>
#include <math.h>
#include <utility>
#include <list>
#include <functional>
using namespace std;

#define ll long long
#define vecint vector<int>
#define Pii pair<int, int>

#define REP(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define print(a) cout << a << endl

#define MOD 1000000007
#define NIL -1

int alpha[26];

int main(){
  vector<string> S;
  int n;

  rep(i,26){
    alpha[i]=0;
  }

  cin>>n;
  rep(i,n){
    string x;
    cin>>x;
    sort(x.begin(),x.end());
    S.push_back(x);
  }
  // rep(i,n){
  //   print(S[i]);
  // }
  rep(i,26){
    int count=0;
    rep(j,n){
      int min_count=0;
      while(S[j].size()!=0&&S[j][0]==(char)(i+(int)'a')){
        min_count++;
        S[j].erase(S[j].begin());
        // print(min_count);
      }
      if(j!=0){
        count=min(count,min_count);
      }else{
        count=min_count;
      }
    }
    rep(j,count){
      cout<<(char)(i+(int)'a');
    }
  }
  print("");
  return 0;
}
