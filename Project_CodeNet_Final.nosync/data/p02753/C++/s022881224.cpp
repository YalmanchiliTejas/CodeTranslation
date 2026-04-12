#include "bits/stdc++.h"
using namespace std;

int main()
{
    string s;
    cin >> s;
    char c;
    bool ismixed = false;
    for (auto i = 0; i < s.length(); i++)
    {
        if (i != 0 && c != s.at(i))
        {
            ismixed = true;
            break;
        }
        c = s.at(i);
    }
    if (ismixed)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
}
