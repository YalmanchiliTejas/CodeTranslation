#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define vec(s) vector<s>
#define vvec(s) vector<vector<s>>
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli, lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Yes(x) cout << (x ? "Yes" : "No") << endl;
#define YES(x) cout << (x ? "YES" : "NO") << endl;
#define out(s) cout << s << endl;
#define Reverse(x) reverse(all(x));
#define Sort(x) sort(all(x));
#define pb(s) push_back(s);
#define sp " "
#define INF 10000000000
#define LINF 9000000000000000000
#define all(s) s.begin(), s.end()
void vout(vi v)
{
    for (lli i = 0; i < v.size(); i++)
        cout << v.at(i) << endl;
}
int main()
{
    cout << std::fixed << std::setprecision(10);
    lli n, x, m, ans = 0;
    cin >> n >> x >> m;
    set<lli> ch;
    vi rec;
    lli last = x;
    lli tmp = 0;
    ch.insert(x);
    rec.push_back(x);
    rep(i, 2 * m)
    {
        x = ((x * x) % m);
        if (ch.count(x))
        {
            last = x;
            break;
        }
        else
        {
            ch.insert(x);
            rec.push_back(x);
        }
    }
    lli lasti;
    rep(i, rec.size())
    {
        if (rec[i] == last)
        {
            lasti = i;
        }
    }
    for (lli i = 0; i < lasti;i++)
    {
        ans += rec[i];
    }
    for (lli i = lasti; i < rec.size();i++){
        tmp += rec[i];
    }
    n -= lasti;
    ans += tmp*(n / (rec.size() - lasti));
    tmp = n % (rec.size() - lasti);
    for (lli i = 0; i < tmp;i++){
        ans += rec[lasti + i];
    }
        out(ans);
}