#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#define lsb(x) ((x) & -(x))
using namespace std;

#define mod 1000000007

int d;

void add(int & a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}

void pass(int * vechi, int * nou)
{
    /// adauga o cifra in plus
    fill(nou, nou + d, 0);
    for (int i = 0; i < d; i++) {
        if (!vechi[i])
            continue;
        for (int c = 0, q = i; c <= 9; c++) {
            add(nou[q], vechi[i]);
            q++;
            if (q == d)
                q = 0;
        }
    }
}

int spcif[100010]; /// suma ultimelor i cifre
int cifr[100010];
int dp[2][100];

int main()
{
    string s;
    cin >> s >> d;

    int n = s.size();

    for (int i = 0; i < s.size(); i++)
        cifr[i + 1] = s[i] - '0', spcif[i + 1] = (spcif[i] + cifr[i + 1]) % d;

    dp[0][0] = 1;
    int nr = (spcif[n] == 0);

    for (int lback = 0; lback < n; lback++) {
        int * act = dp[lback & 1];
        int * oth = dp[(lback & 1) ^ 1];

        int c_poz = cifr[n - lback], sback = spcif[n - lback - 1];
        for (int c = 0; c < c_poz; c++) {
            int sact = (sback + c) % d;
            sact = d - sact;
            if (sact == d)
                sact = 0;
            add(nr, act[sact]);
        }

        if (lback + 1 < n)
            pass(act, oth);
    }

    cout << (nr - 1 + mod) % mod << '\n';
    return 0;
}
