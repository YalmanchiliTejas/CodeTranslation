#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

ll ret(string s, int k){

  if (s.size() == 0)
    return 0;
  if (s[0] == '0')
    return ret(s.substr(1), k);

  if (k == 1){
    return (s[0] - '0') + 9 * (ll)(s.size() - 1);
  }

  string t = "";
  for (unsigned int i = 0; i < s.size() - 1; i++){
    t += string("9");
  }
  
  return ret(s.substr(1), k - 1) + (s[0] - '0' - 1) * ret(t, k - 1) + ret(t, k);
}

int main(void){
  string n;
  int k;

  cin >> n;
  cin >> k;

  cout << ret(n, k) << endl;

  return 0;
}
