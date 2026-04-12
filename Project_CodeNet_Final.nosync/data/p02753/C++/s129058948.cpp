#include "bits/stdc++.h"
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()





int main(){
  string S;

  cin >> S;

  rep(i, 0, 2){
    if(S[i] != S[i+1]){
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";

}