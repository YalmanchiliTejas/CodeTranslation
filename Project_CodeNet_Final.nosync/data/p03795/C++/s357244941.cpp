#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  ll n;
  cin >> n;
  ll temp = n/15;
  ll total = n*800;
  ll returnval = temp*200;
  ll answer = total-returnval;
  cout << answer << endl;
  return 0;
}
