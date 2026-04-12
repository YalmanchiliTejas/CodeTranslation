#include <iostream>
using namespace std;

int main(void){
  int num, v, i, j;
  cin >> num;
  int* a = new int[num];
  while(cin >> v){
        a[i++] = v;
  }
  v = 1;
  for (i = 1; i < num; ++i) {
    for (j = 0; j < i; ++j) {
      if (a[j] > a[i]) {
        break;
      }
    }
    
    if (i == j) {
      ++v;
    }
  }
  cout << v << endl;
}
