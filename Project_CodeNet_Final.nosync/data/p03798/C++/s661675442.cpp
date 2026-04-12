#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define pw(x) (1LL << (x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"

using namespace std;

int n;
string s, a;
bool flag = false;

bool is_saying_right(char animal, char status)
{
    return (animal == 'S' && status == 'o') ||
           (animal == 'W' && status == 'x');
}

bool ok(const char &s, const char &t1, const char &t2, const char &t3)
{
    if ((s == 'o' && t1 == 'W') || (s == 'x' && t1 == 'S'))
        return t2 != t3;
    else
        return t2 == t3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    string ans = "-1";
    string initial[] = {"SS", "SW", "WS", "WW"};

    for (string &t : initial)
    {
        for (int i = 1; i < n - 1; ++i)
        {
            if (is_saying_right(t[i], s[i]))
                t += t[i - 1];
            else
                t += (t[i - 1] == 'S' ? 'W' : 'S');
        }
        if (ok(s[n - 1], t[n - 1], t[0], t[n - 2]) && ok(s[0], t[0], t[n - 1], t[1]))
        {
            ans = t;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
