#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n;
    auto s = new char[n + 1];
    cin >> s >> k;
    char c = s[k-1];

    for (int i = 0; i < n; ++i)
        if (s[i] != c)
            s[i] = '*';

    cout << s << endl;
    return 0;
}