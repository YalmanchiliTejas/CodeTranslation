#include <iostream>

using namespace std;

int main()
{
    int n, x, y, z ;
    cin >> n ;
    x=n*800;
    if (n>=1 && n<=100)
    {
        if (n>=15)
        {
            z=n/15 ;
            y=(z*200);
            cout << x-y ;
        }
        else
            cout << x ;
    }

    return 0;
}
