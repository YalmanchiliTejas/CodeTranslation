#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

int main(int argc, char *argv[])
{
  string t, p;
  cin >> t >> p;

  int n = t.size();
  int m = p.size();
  
  vector<int> ks;
  int k = 0;
  int i = 0;
  while(k < n) {
    while(k < n && t[k] != p[i]) k++;
    if(k >= n) break;
    ks.push_back(k);
    k++;
    i++;
    if(i == m) break;
  }
  if(i < m) { // no match
    cout << "no" << endl;
    return 0;
  }
  // now, found a match. let's try next!
  // try moving the last one to the next position
  // if possible, then the second match found.
  // if not, try moving the 2nd last one to the next position before the last,
  // and so on.
  ks.push_back(n);
  while(i > 0) {
    i--;
    for(k = ks[i] + 1; k < ks[i+1]; k++) {
      if(t[k] == p[i]) { // the second match!
        cout << "no" << endl;
        return 0;
      }
    }
  }
  cout << "yes" << endl;
}