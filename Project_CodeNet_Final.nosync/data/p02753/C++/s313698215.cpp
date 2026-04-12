#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<char> station(3);
  for (int i = 0; i < 3; i++) {
    cin >> station.at(i);
  }
  
  if (station.at(0) == station.at(1) && station.at(1) == station.at(2)) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}