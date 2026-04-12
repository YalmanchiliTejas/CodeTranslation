#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

int main()	{
  int n;
  cin >> n;
  string dict[n];
  for (int i = 0; i < n; i++)	{
    cin >> dict[i];
    sort(dict[i].begin(), dict[i].end());
  }
  string c = dict[0];
  string d(50, ' ');
  sort(c.begin(), c.end());
  string::iterator it;
  it = set_intersection(dict[0].begin(), dict[0].end(), c.begin(), c.end(), d.begin());
  for (int i = 1; i < n; i++)	{
	it = set_intersection(d.begin(), d.end(), dict[i].begin(), dict[i].end(), d.begin());
    d.resize(it - d.begin());
  }
  cout << d << endl;
  return 0;
}