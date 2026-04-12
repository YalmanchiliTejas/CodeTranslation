#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
const ll inf = (ll)1e9 + 7;
int main()
{
    ll i, j, k;
    char a[4];
    cin >> a;
    k = 0;
    for (i = 0; i < 3; i++)
    {
        if (a[i] == 'A')
            k++;
    }
    if (k == 1 || k == 2)
        cout << "Yes";
    else
    {
        cout << "No";
    }

    return 0;
}