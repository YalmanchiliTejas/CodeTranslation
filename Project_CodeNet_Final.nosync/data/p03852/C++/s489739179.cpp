#include <bits/stdc++.h>
using namespace std;

int main() {
  char C;
  cin >> C;

  set<int> st;
  st.insert('a');
  st.insert('e');
  st.insert('i');
  st.insert('o');
  st.insert('u');

  if (st.find(C) != st.end()) {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }
}
