#include <iostream>
#define N_MAX 100
using namespace std;

int N,A,B,i,j,k;
int a[N_MAX];
int num[N_MAX] = {0};
int ans=0;
int r,g,b;

int main(){
  cin >> r >> g >> b;
  ans = r*100 + g*10 + b;
  if (ans % 4 == 0)  cout << "YES" << endl;
  else cout << "NO" << endl;
}