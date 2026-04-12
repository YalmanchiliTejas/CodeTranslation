#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> A;
  for (int i=0; i<H; i++) {
    string input;
    cin >> input;
    if (input.find("#") != -1)
      A.push_back(input);
  }

  vector<string> temp;
  for (int i=0; i<W; i++) {
    string str = "";
    for (int j=0; j<A.size(); j++) {
      str += A[j][i];
    }
    if (str.find("#") != -1)
      temp.push_back(str);
  }

  for (int i=0; i<temp[0].size(); i++) {
    for (int j=0; j<temp.size(); j++) {
      cout << temp[j][i];
    }
    cout << endl;
  }

  return 0;
}
