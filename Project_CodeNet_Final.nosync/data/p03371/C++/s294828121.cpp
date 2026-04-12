#include <bits/stdc++.h>
using namespace std;
#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define SORT_INV(c) sort((c).begin(), (c).end(), greater<int>())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false
#define LL long long
// sort(a.begin(), a.end(), std::greater<int>());

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    long long int ma = max(x, y);
    long long int money = 0x7fffffff;
    for (long long int i = 0; i <= ma*2; i += 2)
    {
        // i means # AB pizza *
        long long int pizza1 = max((long long int )0, a * (x - i / 2));
        long long int pizza2 = max((long long int )0, b * (y - i / 2));
        long long int pizza3 = (long long int )c * i;
        money = min(money, pizza1 + pizza2 + pizza3);
    }
    cout<<money<<endl;
    return 0;
}
