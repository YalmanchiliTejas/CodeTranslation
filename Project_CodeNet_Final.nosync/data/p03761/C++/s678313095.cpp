#include <bits/stdc++.h>
#define ll long long int
#define mod_ceil(a, b) (a % b) ? a / b + 1 : a / b
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        sort(A[i].begin(), A[i].end());
    }
    vector<ll> chr(26, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        vector<ll> tmp(26, 0);
        for (int j = 0; j < A[i].length(); j++)
        {
            tmp[A[i][j] - 'a']++;
        }
        for (int a = 0; a < 26; a++)
            chr[a] = min(chr[a], tmp[a]);
    }
    for (int i = 0; i < 26; i++)
    {
        while (chr[i] > 0)
        {
            cout << char('a' + i);
            chr[i]--;
        }
    }
    cout << endl;
}