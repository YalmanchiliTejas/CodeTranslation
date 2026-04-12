#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n) ; i++)
constexpr auto INF = 2147483647;
typedef long long ll;

int main(){

  string s;
  cin >> s;
  rep(i, 2){
    if(s[i] != s[i+1]){
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";

  return 0;
}