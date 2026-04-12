#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repp(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define rrep(i, n, m) for (int i = n; i >= m; i--)
#define p(s) cout << s << endl;
typedef long long LL;
template <class T>
bool contain(const std::string &s, const T &v)
{
    return s.find(v) != std::string::npos;
}

int main()
{
    char v[5] = {'a', 'e', 'i', 'o', 'u'};
    char c;
    cin >> c;
    rep(i, 5)
    {
        if (v[i] == c)
        {
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
}
