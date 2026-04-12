#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans=1;
  vector <int> h(n,0);

  for (int i=0;i<n;i++){
    cin >> h[i] ;
  }

  int max=h[0];
  

  for(int i=1;i<n;i++){
    if((h[i]>=h[i-1]) and max<=h[i] ){
      ans++;
      max=h[i];
    }
  }

  cout << ans << endl;


  return 0;
}