#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  for(int bit=0; bit<(1<<n); bit++) {
      vector<int> v;
      for(int i=0; i<n; i++) {
          if(bit & (1<<i)) {
              v.push_back(i);
          }
      }
      cout << bit << ":";
      for(int i=0; i<v.size(); i++) {
          cout << " " << v[i];
      }
      cout << endl;
  }
}
