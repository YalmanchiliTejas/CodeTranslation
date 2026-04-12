#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int X; cin >> X;

    string res;
    if (X == 3 || X == 5 || X == 7) {
        res = "YES";
    } else {
        res = "NO";
    }

    cout << res << endl;
    return 0;
}