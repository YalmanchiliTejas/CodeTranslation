#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>

#define AS(a) (sizeof(a)/sizeof(a[0]))
using namespace std;
long long int MOD = 1000000007;

int main() {
  int N;
  cin >> N;
  deque<int> v;
  bool b = true;
  int a[N];
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < N; i++) {
    if(b) {
      v.push_back(a[i]);
      b = false;
    } else {
      v.push_front(a[i]);
      b = true;
    }
  }
  if(b) {
    cout << v.front();
    v.pop_front();
    for(int i = 1; i < N; i++) {
      cout << " " << v.front();
      v.pop_front();
    }
    cout << endl;
  } else {
    cout << v.back();
    v.pop_back();
    for(int i = 1; i < N; i++) {
      cout << " " << v.back();
      v.pop_back();
    }
    cout << endl;
  }




}
