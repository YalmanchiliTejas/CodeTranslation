#include <iostream>
using namespace std;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    
    string s = "NO";
    if (((r*100)+(g*10)+b) % 4 == 0)
    {
        s = "YES";
    }

    cout << s << endl;

    return 0;
}