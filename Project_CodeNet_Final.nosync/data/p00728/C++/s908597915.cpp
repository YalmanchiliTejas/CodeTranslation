
#include<iostream>
using namespace std;

int main()
{
loop:
  int min = 1 << 30, max = 0, sum = 0, n;
  cin >> n;
  if(!n)
    return 0;
  for(int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    max = max < tmp ? tmp : max;
    min = min > tmp ? tmp : min;
    sum += tmp;
  }
  cout << (sum - max - min) / (n - 2) << endl;
  goto loop;
}