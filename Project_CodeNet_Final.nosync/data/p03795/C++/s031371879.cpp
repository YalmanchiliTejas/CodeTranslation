#include<iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int cnt = 0;
  cnt = (n / 15) * 200;

  cout << 800*n - cnt << endl;

  return 0;

}

