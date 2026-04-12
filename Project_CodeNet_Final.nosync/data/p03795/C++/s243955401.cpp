#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    int ret = n / 15;

    cout << (n*800) - (200*ret) << endl;

    return 0;
}
