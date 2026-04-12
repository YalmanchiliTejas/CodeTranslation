#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>

using namespace std;

int main(){
  int n;
  int h[21];
  cin >> n;
  h[0]= 0;
  int ans = 0;
  int m = 0;
  for(int i = 1; i <= n; i++){
    cin >> h[i];
    if(m <= h[i]){
      m = h[i];
      ans++;
    }
  }
  cout << ans << endl;
}
