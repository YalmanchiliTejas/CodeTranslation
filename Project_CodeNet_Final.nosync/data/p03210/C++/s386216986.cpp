#include <iostream>
#define ll long long

using namespace std;

int main()
{
    int X;
    cin >> X;

    bool answer = false;
    if (X-3 == 0) answer = true;
    if (X-5 == 0) answer = true;
    if (X-7 == 0) answer = true;

    cout << (answer ? "YES" : "NO") << endl;

    return 0;
}
