#include <bits/stdc++.h>

using namespace std;

int main()
{
  vector< int > E(12);
  for(int i = 0; i < 12; i++) {
    cin >> E[i];
  }
  sort(E.begin(), E.end());
  if(E[0] == E[3] && E[4] == E[7] && E[8] == E[11]) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }

}