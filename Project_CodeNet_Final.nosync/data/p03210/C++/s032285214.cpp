#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  int X; cin>>X;
  vector<int> v({3,5,7});
  string s;
  if (find(v.begin(), v.end(), X) != v.end()){
    s = "YES";
  } else {
    s = "NO";
  }
  cout<<s<<endl;
}