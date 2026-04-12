#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int X;
    string ans;
    ans = "NO";
    cin >> X;
    if (X == 3 || X == 5 || X == 7)
    {
        ans = "YES";
    }
    cout << ans << endl;
    return 0;
}
