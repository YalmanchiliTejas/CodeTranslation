#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int inf = (int)1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    string s;

    cin >> s;

    bool ans = false;

    for (size_t i = 1; !ans && i < s.size (); i++)
        ans |= (s.substr (i - 1, 2) == "AC");

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}
