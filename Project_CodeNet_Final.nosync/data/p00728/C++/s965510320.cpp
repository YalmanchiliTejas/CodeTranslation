#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  while(cin >> n){
    if(n == 0) break;
    int sum = 0;
    int s[100];
    for(int i = 0; i < n; i++)
      cin >> s[i];
    sort(s, s + n);
    for(int i = 1; i < n - 1; i++)
      sum += s[i];
    cout << sum / (n - 2) << endl;
  }
}