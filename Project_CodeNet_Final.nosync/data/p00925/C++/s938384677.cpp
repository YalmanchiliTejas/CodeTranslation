#include <bits/stdc++.h>

using namespace std;
using i64 = long long int;
using ui64 = unsigned long long int;

////////////////////////////////

int main()
{
  string s;
  int ans;
  cin >> s >> ans;
  char prev = '+';
  vector<int> m_terms;
  int l_val = 0;
  for(int i=0;i<s.length();i++){
    if(i&1){
      prev = s[i];
    }else{
      int val = s[i] - '0';
      if(prev == '+'){
        l_val += val;
        m_terms.push_back(val);
      }else{
        l_val *= val;
        m_terms[m_terms.size()-1] *= val;
      }
    }
  }
  int m_val = 0;
  for(auto&& x:m_terms)m_val += x;
  char res;
  if(ans == m_val && ans == l_val) res = 'U';
  else if(ans == m_val) res = 'M';
  else if(ans == l_val) res = 'L';
  else res = 'I';
  cout << res << endl;
}


