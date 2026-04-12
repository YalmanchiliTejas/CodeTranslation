#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main(){
  int n;
  while(cin >> n, n!=0){
    vector<int> s;
    int input = 0;
    for(int i=0; i<n; i++){
      cin >> input;
      s.push_back(input);
    }
    sort(s.begin(), s.end());
    int sum = 0;
    for(int i=1;i<n-1;i++){
      sum += s[i];
    }
    cout << floor(sum/(n-2)) << endl;
    s.clear();
  }
  return 0;
}