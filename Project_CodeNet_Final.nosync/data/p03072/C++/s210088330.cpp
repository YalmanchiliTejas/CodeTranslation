#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;

  int h[n];
  for (int i = 0; i< n; i++){
    cin >> h[i];
  }

  int max = 0;
  int ct = 0;
  for (int i = 0; i < n; i++){
    if (h[i] >= max){
      ct++;
    }

    if (h[i] > max){
      max = h[i];
    }
  }

  cout << ct << endl;
}
