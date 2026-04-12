#include <bits/stdc++.h>

int main()
{
    std::string s;
    std::cin >> s;

    bool ans = false;
    std::string first_s;
    for (int i = 0; i < s.length(); i++)
    {
        std::string tgt_s = {s[i]};
        if (i == 0)
            first_s = tgt_s;
        if (i > 0)
        {
            if (tgt_s == first_s)
                continue;
            else
            {
                ans = true;
                break;
            }
        }

    }

    if (ans == true)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}