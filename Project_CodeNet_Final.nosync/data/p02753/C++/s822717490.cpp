#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main()
{
    string S;
    cin >> S;

    cout << (S[0] != S[1] || S[1] != S[2] || S[2] != S[0] ? "Yes" : "No");
}