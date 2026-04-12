#include <iostream>
#include <vector>
#include <algorithm>
 
#define ascent(i, a, b) for(int (i) = (a); (i) < (b); (i) ++)

using namespace std;

int main() {
  int n, tmp;
  vector<int> p;
  while(true) {
    cin >> n;
    if(n == 0) break;

    p.clear();
    while(n --) {
      cin >> tmp;
      p.push_back(tmp);
    }

    sort(p.begin(), p.end());

    int sum = 0;
    ascent(i, 1, p.size()-1) {
      sum += p[i];
    }

    cout << sum/(p.size()-2) << endl;
  }
      
  return 0;
}