#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll n;
    string s;
    cin >> n >> s;

    vector<char> t(n + 1);
    //SSから始まる可能性
    t[0] = 'S';
    t[1] = 'S';
    for (int i = 2; i < n + 1; i++)
    {
        if (s[i - 1] == 'o')
        {
            if (t[i - 1] == 'S')
                t[i] = t[i - 2];
            else if (t[i - 2] == 'S')
                t[i] = 'W';
            else
                t[i] = 'S';
        }
        else
        {
            if (t[i - 1] == 'S')
            {
                if (t[i - 2] == 'S')
                    t[i] = 'W';
                else
                    t[i] = 'S';
            }
            else
            {
                t[i] = t[i - 2];
            }
        }
    }

    //答え合わせ
    char ans;
    if (s[0] == 'o')
        ans = 'S';
    else
        ans = 'W';
    if (ans == t[n - 1] && t[0] == t[n])
    {
        rep(i, n) cout << t[i];
        cout << endl;
        return 0;
    }

    //SWから始まる可能性
    t[0] = 'S';
    t[1] = 'W';
    for (int i = 2; i < n + 1; i++)
    {
        if (s[i - 1] == 'o')
        {
            if (t[i - 1] == 'S')
                t[i] = t[i - 2];
            else if (t[i - 2] == 'S')
                t[i] = 'W';
            else
                t[i] = 'S';
        }
        else
        {
            if (t[i - 1] == 'S')
            {
                if (t[i - 2] == 'S')
                    t[i] = 'W';
                else
                    t[i] = 'S';
            }
            else
            {
                t[i] = t[i - 2];
            }
        }
    }
    //答え合わせ
    if (s[0] == 'o')
        ans = 'W';
    else
        ans = 'S';
    if (ans == t[n - 1] && t[0] == t[n])
    {
        rep(i, n) cout << t[i];
        cout << endl;
        return 0;
    }

    //WSから始まる可能性
    t[0] = 'W';
    t[1] = 'S';
    for (int i = 2; i < n + 1; i++)
    {
        if (s[i - 1] == 'o')
        {
            if (t[i - 1] == 'S')
                t[i] = t[i - 2];
            else if (t[i - 2] == 'S')
                t[i] = 'W';
            else
                t[i] = 'S';
        }
        else
        {
            if (t[i - 1] == 'S')
            {
                if (t[i - 2] == 'S')
                    t[i] = 'W';
                else
                    t[i] = 'S';
            }
            else
            {
                t[i] = t[i - 2];
            }
        }
    }
    //答え合わせ
    if (s[0] == 'o')
        ans = 'W';
    else
        ans = 'S';
    if (ans == t[n - 1] && t[0] == t[n])
    {
        rep(i, n) cout << t[i];
        cout << endl;
        return 0;
    }

    //SSから始まる可能性
    t[0] = 'W';
    t[1] = 'W';
    for (int i = 2; i < n + 1; i++)
    {
        if (s[i - 1] == 'o')
        {
            if (t[i - 1] == 'S')
                t[i] = t[i - 2];
            else if (t[i - 2] == 'S')
                t[i] = 'W';
            else
                t[i] = 'S';
        }
        else
        {
            if (t[i - 1] == 'S')
            {
                if (t[i - 2] == 'S')
                    t[i] = 'W';
                else
                    t[i] = 'S';
            }
            else
            {
                t[i] = t[i - 2];
            }
        }
    }
    //答え合わせ
    if (s[0] == 'o')
        ans = 'S';
    else
        ans = 'W';
    if (ans == t[n - 1] && t[0] == t[n])
    {
        rep(i, n) cout << t[i];
        cout << endl;
        return 0;
    }

    cout << -1 << endl;
}
//方針ok
//実装力