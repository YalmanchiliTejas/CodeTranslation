#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int ans=0;
  int mx=0;
  int tmp;
  for(int i=0;i<n; i++){
    cin >> tmp;
    if(mx<=tmp){ans++;mx = tmp;}
  }
  cout << ans << endl;
}