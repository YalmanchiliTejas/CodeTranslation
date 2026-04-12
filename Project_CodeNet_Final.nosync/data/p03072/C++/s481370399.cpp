#include <bits/stdc++.h>
#include <vector>
#include <string.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)



void solve(){
  int n;
  cin >> n;
  vector<int> h; 
  for(int i=0; i<n; i++){
    int k;
    cin >> k;
    h.push_back(k);
  }
  int count=0;
  for(int i=0; i<n; i++){
    bool b=true;
    for(int j=0; j<i; j++){
      if (h[j]>h[i]) {b=false;}
    }
    if(b) {count++;}
  }
  cout << count << endl;

}

int main(){
  solve();
  return 0;
}
