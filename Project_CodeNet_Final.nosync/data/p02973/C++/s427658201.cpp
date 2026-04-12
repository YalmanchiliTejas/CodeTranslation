#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N; cin >> N; int A; vector<int> b;
  b.push_back(-1);
  for(int i=0; i<N; i++){
    cin >> A;
    int wh = distance(b.begin(), upper_bound(b.begin(), b.end(), A, std::greater<int>()));
    if (wh < b.size()) b[wh] = A;
    else b.push_back(A);
  }
  cout << b.size() << endl;
}