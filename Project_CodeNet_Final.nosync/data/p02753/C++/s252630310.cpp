#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

  string s;cin>>s;

  if(count(s.begin(), s.end(), 'A') > 0 && count(s.begin(), s.end(), 'B') > 0) {
    puts("Yes");
  }else
  {
    puts("No");

  }
  

  
  return 0;
}
