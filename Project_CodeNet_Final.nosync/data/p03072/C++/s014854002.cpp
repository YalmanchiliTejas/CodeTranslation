#include <stdio.h>
#include <vector>
#include <iostream>
// #include <bits/stdc++.h>

using namespace std;
#define _GLIBCXX_DEBUG

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int N;
    cin >> N;

    vector<int> H(N);

    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }

    int ans = 0, num = 0;

    for (int i = 0; i < N; i++)
    {
        if (num <= H[i])
        {
            num = H[i];
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
