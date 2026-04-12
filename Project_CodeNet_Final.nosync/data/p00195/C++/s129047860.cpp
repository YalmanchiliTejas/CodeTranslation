#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Shop
{
  int sale;
  char name;

  bool operator<(const Shop& right) const
  {
    return sale < right.sale;
  }
};

int main(void)
{
  while (true)
  {
    vector<Shop> shops;
    for (int i = 0, x, y; i < 5; ++i)
    {
      cin >> x >> y;
      shops.push_back( {x + y, (char)(65 + i)} );
    }
    if (cin.eof()) break;

    sort(shops.rbegin(), shops.rend() );
    cout << shops[0].name << " " << shops[0].sale << endl;
  }
  return 0;
}