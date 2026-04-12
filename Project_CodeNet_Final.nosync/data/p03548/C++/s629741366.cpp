#include <iostream>
using namespace std;

int main()
{
  	int x1,y1,z1;
  	cin >> x1 >> y1 >> z1;
    if (x1 < y1+2*z1)
        cout << 0 << endl;
    else
        cout << ((x1-z1)/(y1+z1)) << endl;
}