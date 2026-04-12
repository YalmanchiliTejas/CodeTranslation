#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = 0;
    if (A + B < 2 * C)
    {
        ans = A * X + B * Y;
    }else
    {
        if (X < Y)
        {
            ans = 2 * C * X;
            ans += min(B * (Y - X), 2 * C * (Y - X));
        }else
        {
            ans = 2 * C * Y;
            ans += min(A * (X - Y), 2 * C * (X - Y));
        }
        
    }
    
    cout << ans << endl;
    
    return 0;
}