#include <bits/stdc++.h>
using namespace std;

int main() {
vector<char> sta(3);
cin >> sta.at(0) >> sta.at(1) >> sta.at(2);

if (sta.at(0) == 'A' && sta.at(1) == 'A' && sta.at(2) == 'A') {
cout << "No" << endl;
} else if (sta.at(0) == 'B' && sta.at(1) == 'B' && sta.at(2) == 'B') {
  cout << "No" << endl;
}else {
  cout << "Yes" << endl;
}
}