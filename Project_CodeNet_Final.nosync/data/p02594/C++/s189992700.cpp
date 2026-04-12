#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define REP(i, start, end) for (int i = start, i##Len = (end); i < i##Len; ++i)
#define REPR(i, start, end) for (int i = start, i##Len = (end); i > i##Len; --i)
using ll = long long;
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n;
    cin >> n;
    cout << (n >= 30 ? "Yes" : "No") << endl;
}