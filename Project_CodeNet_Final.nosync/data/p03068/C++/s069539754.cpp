#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, k;
    string s;
    cin >> n;
    cin >> s;
    cin >> k;
    char s_k = s.at(k - 1);
    rep(i, n)
    {
        if (s.at(i) != s_k)
        {
            s.at(i) = '*';
        }
    }
    cout << s << endl;
}