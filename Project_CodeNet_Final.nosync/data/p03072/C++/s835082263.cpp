#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n; cin >>n;
  int max=0, ans = 0;
  int buf;
  for (int i=0; i<n; i++){
    cin >>buf;
    if (buf>=max){
      max = buf; ans++;
    }
  }
  cout <<ans;
  cout <<endl;
}
