#include <iostream>
#include <string>
using namespace std;

int main()
{
    int r, g, b;
    string answer = "NO";
    cin >> r >> g >> b;
    if ((g * 10 + b) % 4 == 0) {
        answer = "YES";
    }
    cout << answer << endl;

    return 0;
}