#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG



int main() {
  string S;
  cin >> S;
  //vector<ll> a(N);
  //vector<vector<int>> data(3, vector<int>(4));

  ll count_A = 0;
  ll count_B = 0;

  for(ll i=0; i<3; i++){
    if(S.at(i) != 'A'){
      count_A++;
    }    
    else count_B++;

  }

  
  if(count_A * count_B == 0){
    cout << "No" << endl;
    return 0;
  }else cout << "Yes" << endl;
  return 0;
}
