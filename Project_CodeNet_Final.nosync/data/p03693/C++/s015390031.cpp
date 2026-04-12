#include <iostream>
using namespace std;
int main()
{
int r,g,b;
    cin >> r >> g >> b;
g = g*10+b;
cout << (g%4 ? "NO" : "YES") << endl;
return 0;
}