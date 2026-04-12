#include <bits/stdc++.h>
using namespace std;

int main() {
int n,h;
cin >> n >> h;
  int count=0, hmax=h;
  for (int i=0; i<n; i++){
  if (h>=hmax){
  count++;
    hmax=h;
  }
  cin >> h;
  }
  cout << count << endl;
}
