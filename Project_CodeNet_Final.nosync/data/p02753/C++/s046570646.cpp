#include "bits/stdc++.h"
using namespace std;
int main()
{
  string s;
  cin >> s;
  set<char> st;
  for(auto e:s){
    st.insert(e);
  }
  cout << (st.size()>1?"Yes":"No") << endl;
  return 0;
}