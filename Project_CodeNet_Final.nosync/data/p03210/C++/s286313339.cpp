
#include <bits/stdc++.h>

using namespace std;

void Main()
{
    int x;
    cin >> x;
    if (x == 3 || x == 5 || x == 7)
        cout << "YES";
    else
        cout << "NO";
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    //std::cout << std::fixed << std::setprecision(10);

#ifdef DEBUG_BUILD
    while (true)
    {
        Main();
        cout << std::endl;
    }
#endif

    Main();
    cout << endl;

    return 0;
}