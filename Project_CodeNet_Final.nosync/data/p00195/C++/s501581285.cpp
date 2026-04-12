#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int s1, s2;
  while (cin >> s1 >> s2 && s1 != 0){
    int cnt = 0, max = s1 + s2;
    for (int i = 1; i < 5; i++){
      cin >> s1 >> s2;
      if (max < s1 + s2){
        max = s1 + s2;
        cnt = i;
      }
    }
    printf("%c ", 'A' + cnt);
    cout << max << endl;
  }
}