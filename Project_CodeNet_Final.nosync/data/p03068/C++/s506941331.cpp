#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

static const int N = 100100;

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    string s;

    cin >> n >>s>> k;

    char ss = s[k - 1];

    for (int i = 0; i < n; i++)
    {
        if(s[i]!=ss)
            s[i] = '*';
    }


    cout << s <<endl;

    return 0;
}
