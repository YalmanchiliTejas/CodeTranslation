#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main()
{
    int N, d15, ans;
    cin >> N;
    d15 = N / 15;
    ans = 800 * N - d15 * 200;
    cout << ans << endl;
}