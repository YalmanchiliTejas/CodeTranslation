#include <bits/stdc++.h>
#define INF (int)1e9
#define endl "\n"
#define ll long long
#define ull unsigned long long

using namespace std;

int main()
{
    string a;
    cin >> a;

    if (a[1] != a[0] or a[1] != a[2])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}