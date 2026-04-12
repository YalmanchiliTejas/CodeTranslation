#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int X , Y, Z;
    cin >> X >> Y >> Z;
    int ans;
    for (int i = 0;; i++)
    {
        if( Y*i+Z*(i+1) > X){
            ans = i - 1;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}