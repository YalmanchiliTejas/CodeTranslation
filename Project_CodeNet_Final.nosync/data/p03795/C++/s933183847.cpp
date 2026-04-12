#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  int x, y;
  x = 800 * N;
  y = 200 * (N - N % 15) / 15;
  cout << x - y << endl;
}