#include <iostream>
#include <string>

int main()
{
    int n, k;
    std::string s;
    std::cin >> n >> s >> k;
    char r = s[k-1];
    char ans[n];

    for (int ii=0; ii < n; ++ii)
    {
        if (s[ii] == r)
        {
            ans[ii] = s[ii];
        }
        else
        {
            ans[ii] = '*';
        }
    }
    for(int ii = 0; ii < n; ++ii)
    {
        std::cout << ans[ii];
    }
}
