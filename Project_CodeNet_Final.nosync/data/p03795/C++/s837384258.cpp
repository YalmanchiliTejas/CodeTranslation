#include<iostream>
using namespace std;
int main(void){
  int n;
  int ret;
  cin >> n;
  ret = 800*n;
  ret -= 200*(n/15);
  cout << ret;
}
