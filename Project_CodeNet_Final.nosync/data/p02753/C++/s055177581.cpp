#include"bits/stdc++.h"
using namespace std;

void Main()
{
    string s;
    std::cin >>  s;

    if (s[0] == s[1] && s[1] == s[2])
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    Main();
}