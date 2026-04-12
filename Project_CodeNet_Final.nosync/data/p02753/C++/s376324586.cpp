#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;
    if (s[0] == 'A' || s[1] == 'A' || s[2] == 'A')
    {
        if (s[0] == 'B' || s[1] == 'B' || s[2] == 'B') cout << "Yes\n";
        else cout << "No\n";
    }
    else cout << "No\n";

    return 0;
}