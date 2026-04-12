#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

typedef string::const_iterator State;
class ParseError
{
};

int number(State &begin)
{
    int ret = 0;

    while (isdigit(*begin))
    {
        ret *= 10;
        ret += *begin - '0';
        begin++;
    }
    return ret;
}

int term(State &begin)
{
    int ret = number(begin);

    for (;;)
    {
        if (*begin == '*')
        {
            begin++;
            ret *= number(begin);
        }
        else
        {
            break;
        }
    }
    return ret;
}

int expr(State &begin)
{
    int ret = term(begin);
    for (;;)
    {
        if (*begin == '+')
        {
            begin++;
            ret += term(begin);
        }
        else
        {
            break;
        }
    }
    return ret;
}
int exprWrong(State &begin)
{
    int ret = number(begin);
    for (;;)
    {
        if (*begin == '+')
        {
            begin++;
            ret += number(begin);
        }
        else if (*begin == '*')
        {

            begin++;
            ret *= number(begin);
        }
        else
        {
            break;
        }
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int ans;
    cin >> ans;
    State begin = s.begin();
    int ansc = expr(begin);
    begin = s.begin();
    int answ = exprWrong(begin);
    if (ans == ansc && ans != answ)
    {
        cout << "M" << endl;
    }
    else if (ans != ansc && ans == answ)
    {
        cout << "L" << endl;
    }
    else if (ans == ansc && ans == answ)
    {
        cout << "U" << endl;
    }
    else if (ans != ansc && ans != answ)
    {
        cout << "I" << endl;
    }

    return 0;
}

