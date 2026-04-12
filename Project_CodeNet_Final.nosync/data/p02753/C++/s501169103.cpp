#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  set<char> st;
  for(auto ch : s) {
      st.insert(ch);
  }
  if(st.size() > 1) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
}