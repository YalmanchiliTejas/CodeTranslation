#include <iostream>
using namespace std;
int main()
{
    int n, k;
    string s;
    cin >> n >> s >> k;

    const char c = s[k-1];

    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
        {
            cout << c;
        } else {
            cout << '*';
        }
    }

    cout << '\n';
    return 0;
}