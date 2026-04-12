#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int h[20];
  int count = 0;
  int max = 0;
  for(int i=0; i<n; i++){
    cin >> h[i];
    if(max<=h[i]){
      count++;
      max = h[i];
    }
  }
  cout << count;
  return 0;
}
