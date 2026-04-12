#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)



void solve(){
  int k;
  cin >> k;
  const int n=k;
  int h[n];
  for(int i=0; i<n; i++) cin >> h[i];
  int count =0;
  
  for(int i=0;i<n; i++){
    bool b=true;
    for(int j=0; j<i; j++){
       if(h[j]>h[i]) b=false;
    }
    if(b) count++;
  }
  cout << count << endl;
}

int main(){
  solve();
  return 0;
}
  
