#include <bits/stdc++.h>

#define MAX_N 3000

using namespace std;

typedef long long lint;

const lint MOD = 998244353LL;

int n, s;
int v[MAX_N + 9];

lint ap[MAX_N + 9];

void modd(lint &a)
{
    if(a >= MOD)
        a -= MOD;

    if(a < 0)
        a += MOD;
}

void modd(int &a)
{
    if(a >= MOD)
        a -= MOD;

    if(a < 0)
        a += MOD;
}

int main()
{
    cin >> n >> s;
    for(int i = 1; i <= n; i ++)
    {
        cin >> v[i];
    }

    lint rez = 0;
   // ap[0] = 1;
    for(int i = 1; i <= n; i ++)
    {

        //cout << " SUNTME " << i <<  "ADUNAM " << (n - i + 1) << " RO " << ap[s] << "\n";

        if(v[i] < s)
            rez += 1LL * (n - i + 1) * ap[s - v[i]] % MOD;

        else if(v[i] == s)
            rez += 1LL * (n - i + 1) * i % MOD;

        modd(rez);

        for(int j = s; j > v[i]; j --)
        {
            ap[j] += ap[j - v[i]];
            modd(ap[j]);
        }

        ap[v[i]] += i;
        modd(ap[v[i]]);

    }

    cout << rez << "\n";

    return 0;
}
