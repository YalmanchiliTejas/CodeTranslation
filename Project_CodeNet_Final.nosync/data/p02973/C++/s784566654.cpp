#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long int lli;

int main() {
  lli n;
  cin >> n;
  vector<lli> lines;
  lli currMin = 0;
  for (int i=0; i < n;i++) {
    lli curr;
    cin >> curr;
    int lineMax = -1;
    int insertIndex = -1;
    if ( currMin < curr )
    for (size_t idx=0; idx < lines.size(); idx++) {
      lli lineA = lines[idx];
      if(lineA < curr){
      	if(lineMax < lineA) {
          lineMax = lineA;
          insertIndex = idx;
        }
      }
    }
    if (insertIndex < 0){
      lines.push_back(curr);
      currMin = curr;
    } else {
      lines[insertIndex] = curr;
    }
  }
  std::cout << (lines.size()) << std::endl;
}