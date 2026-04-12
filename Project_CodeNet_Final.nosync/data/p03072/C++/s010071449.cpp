#include <iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
    cin >> n;
  	int h[n];
  	int index = 0;
  	int highest_view = 0;
  	int o = 0;
  	while(index != n)
    {
      cin >> h[index];
      if(h[index] >= highest_view)
      {
        o++;
        highest_view = h[index];
      }
      index++;
    }
  	
  	cout << o << endl;
  	return 0;
}