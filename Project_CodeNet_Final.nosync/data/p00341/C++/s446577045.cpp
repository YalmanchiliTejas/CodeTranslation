#include<iostream>
#include<algorithm>

using namespace std;

int main() {
  int a[12];
  for(int i = 0; i < 12; i++) {
    cin >> a[i];
  }
  sort(a, a + 12);
  bool ok = true;
  for(int i = 0; i < 3; i++) {
    ok &= a[i*4 + 0] == a[i*4 + 1] && a[i*4 + 1] == a[i * 4 + 2] && a[i * 4 + 2] == a[i * 4 + 3];
  }
  if(ok) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }

}