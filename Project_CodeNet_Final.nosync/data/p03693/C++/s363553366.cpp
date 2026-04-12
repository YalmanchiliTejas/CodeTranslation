#include <iostream>
using namespace std;


int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    
    int result = 0;
    result = 100 * r + 10 * g + 1 * b;
    
    if (result % 4 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    
    return 0;
}
