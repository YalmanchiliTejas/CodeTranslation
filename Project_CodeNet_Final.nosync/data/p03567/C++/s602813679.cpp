#include <bits/stdc++.h>
using namespace std;

string str;

int main(void){
  cin >> str;
  for (int i = 0; i < str.size() - 1; ++i) {
    if (str[i] == 'A' && str[i + 1] == 'C') {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}