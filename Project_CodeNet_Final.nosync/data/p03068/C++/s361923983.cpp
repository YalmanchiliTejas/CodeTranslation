#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int k;
    std::cin >> k;
    k--;

    for (int i = 0; i < n; i++) {
        if (s[i] != s[k]) {
            s[i] = '*';
        }
    }

    std::cout << s << std::endl;
}
