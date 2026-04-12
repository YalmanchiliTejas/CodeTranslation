#include <iostream>
#include <string>
#include <set>
using namespace std;

char l[11] = {'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm'};

int main() {
  set<char> left;
  for (int i=0; i<11; ++i) left.insert(l[i]);

  string in;
  while(cin>>in) {
    if (in == "#") break;
    int prev = (left.find(in[0]) == left.end())?0:1;
    int ans = 0;
    for (int i=0; i<in.length(); ++i) {
      int n = (left.find(in[i]) == left.end())?0:1;
      if (n != prev) ans++;
      prev = n;
    }
    cout<<ans<<endl;
  }
}