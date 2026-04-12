#include<iostream>
using namespace std;
int main()
{
  int valuePlace100, valuePlace10, valuePlace1;
  cin >> valuePlace100 >> valuePlace10 >> valuePlace1;
  int sum = (valuePlace100)*100+(valuePlace10)*10+valuePlace1;
  if(sum % 4 == 0)
  cout << "YES";
  else
  cout << "NO";
  return 0;
}