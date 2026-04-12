#include <bits/stdc++.h>
using namespace std;

const bool DEBUG = false;

string S;

void input() { cin >> S; }

int main(int argc, char const *argv[]) {
  input();
  if (S[0] == S[1] && S[1] == S[2]) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

  return 0;
}