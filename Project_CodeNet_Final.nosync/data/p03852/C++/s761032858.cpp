#include <bits/stdc++.h>
using namespace std;

// requiredstring contains stringlist ?(yes:1,no:0)
template <class T>
bool strcontain(const string stringlist,
                const T& requiredstring) {
  return stringlist.find(requiredstring) != string::npos;
}
void prians(bool answer) {
  if(answer)
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;
}

string s = "aiueo";
char x;

int main() {
  cin >> x;
  prians(strcontain(s, x));
  return 0;
}