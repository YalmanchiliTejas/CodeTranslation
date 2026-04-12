#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reprev(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main()
{
    int n, q, q1, q2, q3;
    string s;
    cin >> s;

    if (s[0] == s[1] && s[1] == s[2])
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}
