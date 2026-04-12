#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define rep(i,n) for(int i=0;i<n;i++)
const long long MOD = 1000000007;

int h,w; 
int main(){
  cin >> h >> w; cin.ignore();
  int ans = 0;
  rep(i,h){
    string s; getline(cin,s);
    rep(j,w){
      if(s.at(j) == '#') ans++;
    }
  }
  if(ans == h+w-1 ){
    cout << "Possible\n";
  }else{
    cout << "Impossible\n";
  }
}