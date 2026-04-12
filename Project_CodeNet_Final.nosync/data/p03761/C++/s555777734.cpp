#include <iostream>
using namespace std;
int main()
{
  int n, arr['z'-'a'+1]{};
  string curr;
  cin >> n >> curr;
  for(int i = 0; i < curr.size(); i++)
    arr[ curr[i] - 'a' ]++;
  for(int i = 1; i < n; i++)
  {
    cin >> curr;
    int  tmp['z'-'a'+1]{};
    for(int j = 0; j < curr.size(); j++)
      tmp[ curr[j] - 'a' ]++;
    for(int j = 0; j < 'z'-'a'+1; j++)
      arr[j] = arr[j] > tmp[j] ? tmp[j] : arr[j];
  }
  for(int i = 0; i < 'z'-'a'+1; i++)
    for(int j = 0; j < arr[i]; j++)
      cout << (char)('a'+i);
}