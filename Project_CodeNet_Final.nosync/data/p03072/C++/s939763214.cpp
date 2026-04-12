#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>

using namespace std;


int main(){
  int n, tmp = 0;
  int ans = 0;
  cin >> n;
  vector<int> h(n);

  for(int i = 0; i < n; ++i){
    cin >> h[i];
  }

  for(int i = 0; i < n; ++i){
    if(tmp <= h[i]){
      tmp = h[i];
      ans++;
    }
  }
  cout << ans << endl;

}
