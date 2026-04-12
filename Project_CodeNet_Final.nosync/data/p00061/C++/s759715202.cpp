#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

int main(void){
  char c;
  int a, b, n;
  vector<int> v;
  map<int, int> m;

  while(cin >> a >> c >> b, a || b){
    m[a] = b;
    if(find(v.begin(), v.end(), b) == v.end()){
      v.push_back(b);
    }
  }
  sort(v.begin(), v.end(), greater<int>());


  vector<int>::iterator it;
  while(cin >> n){
    it = find(v.begin(), v.end(), m[n]);
    cout << it - v.begin() + 1 << endl;
  }

  return 0;
}