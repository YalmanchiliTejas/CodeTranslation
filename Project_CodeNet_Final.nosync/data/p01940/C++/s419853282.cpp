#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
  string s, t;
  cin >> s >> t;
  int n = s.length();
  vector<int> F;
  {
    int j = 0;
    for(int i = 0; i < n; ++i){
      if(j == t.length()) break;
      if(s[i] != t[j]) continue;
      F.push_back(i);
      ++j;
    }
  }
  if(F.size() != t.length()){
    puts("no");
    return 0;
  }
  vector<int> B;
  {
    int j = t.length()-1;
    for(int i = n-1; i >= 0; --i){
      if(j == -1) break;
      if(s[i] != t[j]) continue;
      B.push_back(i);
      --j;
    }
    reverse(B.begin(), B.end());
  }
  if(B.size() != t.length()){
    puts("no");
    return 0;
  }
  if(F != B){
    puts("no");
    return 0;
  }
  puts("yes");
}
  

