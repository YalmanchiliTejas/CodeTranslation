#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;
long long A[100000];
long long bins[100000];
int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  bins[0] = - A[0];
  int bin_no = 1;
  for(int i = 1; i < N; i++){
    auto it = upper_bound(bins, bins + bin_no, - A[i]);
    *it = - A[i];
    if(it == bins + bin_no){
      bin_no ++;
    }
  }
  cout << bin_no << endl;
  return 0;
}
