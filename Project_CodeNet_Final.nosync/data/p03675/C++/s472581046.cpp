#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);

  for(int i = 0; i < n; i++)
    cin >> a[i];

  list<int> li;

  for(int i = 0; i < n; i++) {
    if((n - i) % 2 == 0) {
      li.push_back(a[i]);
    }else{
      li.push_front(a[i]);
    }
  }

  for(auto it = li.begin(); it != li.end(); ++it) {
    if(it != li.begin()) {
      cout << ' ';
    }

    cout << *it;

  }

  cout << endl;

}
