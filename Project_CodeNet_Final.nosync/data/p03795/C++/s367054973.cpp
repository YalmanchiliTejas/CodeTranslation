#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  
  int M = N / 15;
  int y = M * 200;
  int x = N * 800;
  
  cout << x - y << endl;
}