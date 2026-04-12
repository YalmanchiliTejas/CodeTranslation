#include <iostream>
using namespace std;
int main()
{
    int x = 0, y = 0, z = 0, a = 0;
    cin >> x >> y >> z;
    while(x > z)
    {
        x -= z;
        if(x >= y)
        {
            x -= y;
            a++;
        }
        else
        {
            break;
        }
    }

    if(x >= z)
    {
        cout << a;
    }
    else if(a == 0)
    {
        cout << a;
    }
    else
    {
        cout << a - 1;
    }
    return 0;
}