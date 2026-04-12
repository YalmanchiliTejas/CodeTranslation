#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#define llint long long
#define inf 1e9

using namespace std;
typedef pair<llint, llint> P;

string s;
llint x;

int main(void)
{
  cin >> s >> x;
  llint ans = s[0]-'0';
  for(int i = 2; i < s.size(); i+=2){
    if(s[i-1] == '+') ans += s[i]-'0';
    else ans *= s[i]-'0';
  }

  llint ans2 = 0, mul = 1;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '+'){
      ans2 += mul;
      mul = 1;
    }
    else if(s[i] != '*') mul *= s[i]-'0';
  }
  ans2 += mul;

  if(ans == x){
    if(ans2 == x) cout << "U" << endl;
    else cout << "L" << endl;
  }
  else{
    if(ans2 == x) cout << "M" << endl;
    else cout << "I" << endl;
  }
  return 0;
}

