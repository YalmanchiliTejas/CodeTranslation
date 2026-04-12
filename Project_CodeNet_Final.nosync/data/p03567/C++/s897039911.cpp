#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using node = tuple< ll, ll, ll>;
const ll inf = numeric_limits< ll >::max()/3;

int main(void){
  string s;
  cin >> s;
  for(int i = 0;i < (int)s.size()-1;++i){
    if(s.substr(i,2) == "AC"){
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}
