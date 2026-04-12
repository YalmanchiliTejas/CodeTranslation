#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int X, Y, Z;

int main(int argc, char const *argv[])
{
    cin >> X >> Y >> Z;
    int ans=0;
    for (int i = 0; i < 100000; i++)
    {
        if (i * Y + (i + 1) * Z > X)
        {
            ans=i-1;
            i=100000;
        }
    }
    cout << ans << endl;
    return 0;
}
