#include <iostream>
#include <string>

using namespace std;

void resolve()
{
    string S;
    cin >> S;

    if (S == "AAA" || S == "BBB")
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    resolve();
    return 0;
}
