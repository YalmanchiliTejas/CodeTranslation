#include <iostream>
using namespace std;

int main()
{
    int r, g, b;
    
    while(cin >> r >> g >> b)
    {
        int sum = 0;
        sum += 10*g + b;
        string ans = "NO";
        if(sum % 4 == 0)
        {
            ans = "YES";
        }
        cout << ans << endl;
    }
}