#include <iostream>

using namespace std;

int main()
{
    int n, k;
    char s[11];
    cin >> n >> s >> k;
    k -= 1;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != s[k]) s[i] = '*';
    }
    cout << s;
}