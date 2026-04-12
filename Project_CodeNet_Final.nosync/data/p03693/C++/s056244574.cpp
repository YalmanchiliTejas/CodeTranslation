#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    if ((g * 10 + b) % 4 == 0)
        cout << "YES";
    else
        cout << "NO";
}