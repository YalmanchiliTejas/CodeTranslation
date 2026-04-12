#include <iostream>
using namespace std;

int main()
{
    int n, k;
    std::string s;
    cin >> n >> s >> k;
    for (int i = 0; i < n; i++)
    {
        if (s[k - 1] != s[i])
        {
            s[i] = '*';
        }
    }
    std::cout << s;
    return 0;
}