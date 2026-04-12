#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string n;
int k;
ll res;

ll C(int lft, int k)
{
    if (k < 0) return 0;
    if (k == 3) return ll(lft) * (lft - 1) * (lft - 2) / 6 * 9 * 9 * 9;
    else if (k == 2) return lft * (lft - 1) / 2 * 9 * 9;
    else if (k == 1) return lft * 9;
    else return 1;
}

int main()
{
    cin >> n;
    cin >> k;
    res += C(int(n.length()) - 1, k);
    for (int i = 0; i < n.length() && k >= 0; i++) {
        for (int j = i == 0? 1: 0; j < n[i] - '0'; j++)
            res += C(int(n.length()) - 1 - i, k - (j != 0));
        k -= n[i] - '0' != 0;
    }
    if (k == 0) res++;
    printf("%lld\n", res);
    return 0;
}
