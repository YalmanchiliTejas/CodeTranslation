#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int solve_testcase() {
  vector<int> s1(5), s2(5);
  cin >> s1[0] >> s2[0];
  if(s1[0] == 0 and s2[0] == 0) return 1;
  for(int i=1; i<5; i++) {
    cin >> s1[i] >> s2[i];
  }

  char c[] = {'A', 'B', 'C', 'D', 'E'};
  int max_val = 0, arg = -1;
  for(int i=0; i<5; i++) {
    if(s1[i] + s2[i] > max_val) {
      max_val = s1[i] + s2[i];
      arg = i;
    }
  }
  cout << c[arg] << " " << max_val << endl;
  return 0;
}

int main() {
  while(!solve_testcase());
  return 0;
}

