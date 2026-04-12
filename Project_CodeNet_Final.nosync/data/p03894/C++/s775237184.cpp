#include <algorithm>
#include <iostream>
using namespace std;

int N, Q;
int arr[101010];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> Q;
  fill(arr, arr+101010, 0);

  int pos = 0;

  for (int j = 0; j < Q; ++j) {    
    int a, b;
    cin >> a >> b;
    --a; --b;

    // use magic before exchange
    if (pos > 0) { arr[pos-1] = 1; }
    if (pos < N-1) { arr[pos+1] = 1; }

    swap(arr[a], arr[b]);

    if (pos == a) { pos = b; }
    else if (pos == b) { pos = a; }
  }
  if (pos > 0) { arr[pos-1] = 1; }
  if (pos < N-1) { arr[pos+1] = 1; }
  arr[pos] = 1;
  int val = 0;
  for (int j = 0; j < N; ++j) { val += arr[j]; }
  cout << val << endl;
  return 0;
}