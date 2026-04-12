#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
#define rep(NAME, NUM) for (int NAME = 0; NAME < (NUM); ++NAME)

#define vec(TYPE, A, NAME, INIT) vector<TYPE> NAME(A, INIT)

vec(ull, 0, burgerP, 0L);
vec(ull, 0, burgerNum, 0L);

ull eat(int num, ull xx)
{
    if (xx <= 0L)
        return 0L;
    if (num == 0)
        return 1L;
    if (xx >= burgerNum[num] - 1L)
        return burgerP[num];
    if (xx > burgerNum[num - 1] + 2L)
        return 1L + burgerP[num - 1] + eat(num - 1, xx - burgerNum[num - 1] - 2L);
    if (xx >= burgerNum[num - 1] + 2)
        return 1L + burgerP[num - 1];
    if (xx > 1)
        return eat(num - 1, xx - 1L);
    return 0L;
}

int main()
{
    //-----------------
    int n = 0;
    ull x = 0;
    cin >> n >> x;
    burgerP.assign(n + 1, 0L);
    burgerNum.assign(n + 1, 0L);
    rep(i, n + 1)
    {
        if (i == 0)
        {
            burgerP[i] = 1L;
            burgerNum[i] = 1L;
            continue;
        }
        burgerP[i] = 2L * burgerP[i - 1] + 1L;
        burgerNum[i] = 2L * burgerNum[i - 1] + 3L;
    }

    cout << eat(n, x) << endl;
    //----------------
    return 0;
}