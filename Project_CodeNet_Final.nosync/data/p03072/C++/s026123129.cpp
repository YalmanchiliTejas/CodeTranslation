#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> a(n);

  for(int i = 0; i < n; i++){
    cin >> a.at(i);
  }

  int ans = 0;

  for(int i = 0; i < n; i++){
    bool can_see = true;
    for(int j = i - 1; j >= 0; j--){
      if(a.at(i) < a.at(j)){
        can_see = false;
      }
    }

    if(can_see == true){
      ans++;
    }
  }

  cout << ans << endl;
}