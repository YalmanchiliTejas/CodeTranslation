#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long int ulint;
typedef long long int lint;

int main(){
  ulint N;
  cin >> N;

  vector<ulint> A;
  
  for (int i = 0; i < N; ++i) {
    ulint a;
    cin >> a;
    A.push_back(a);
  }

  vector<ulint> C(N, (ulint) -1);
  
  for (int i = N - 1; i >= 0; --i) {
    // TODO: binary search here.
    auto it = upper_bound(C.begin(), C.end(), A[i]);
    // int j = 0;
    // while (A[i] >= C[j]) {
    //   ++j;
    // }
    *it = A[i];
    // C[j] = A[i];    
  }

  // cout << "C= " << endl;
  // for (int i = 0; i < N; ++i) {
  //   cout << C[i] << " ";
  // }
  // cout << endl;
  
  auto it = find(C.begin(), C.end(), (ulint) -1);

  ulint val =  it - C.begin();

  cout << val << endl;

}
