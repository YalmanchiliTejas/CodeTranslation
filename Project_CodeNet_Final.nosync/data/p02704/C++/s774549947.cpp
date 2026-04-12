#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
const int MAXN = 510;

int N;
ll S[MAXN], T[MAXN], U[MAXN], V[MAXN];
int ns[MAXN];
int nt[MAXN];

ll vv[MAXN][MAXN];
ll nleft[MAXN][MAXN];

ll gv (int K, int t)
{
    int tt;
    if (t == 0)
    {
        tt = S[K];
    }
    else
        tt = T[K];

    ll res = 0;
    if (tt == 0)
    {
        res = -1;
    }

    for (int i = 0; i < N; i++)
    {
        ll v;
        if (t == 0)
            v = vv[K][i];
        else
            v = vv[i][K];
        if (tt == 0)
            res &= v;
        else
            res |= v;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> S[i];
    for (int i = 0; i < N; i++)
        cin >> T[i];
    for (int i = 0; i < N; i++)
        cin >> U[i];
    for (int i = 0; i < N; i++)
        cin >> V[i];
    
    bool bad = false;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (S[i] == 0 && T[j] == 0)
            {
                vv[i][j] = U[i] | V[j];
            }
            else if (S[i] == 1 && T[j] == 1)
            {
                vv[i][j] = U[i] & V[j];
            }
            else
            {
                ll v1 = U[i], v2 = V[j];
                if (S[i])
                    swap (v1, v2);
                // AND, OR
                // 00 = no
                // 11 = yes
                // 10 = bad
                // 01 = ??
                vv[i][j] = v1 & v2;
                ll vl = v1 - vv[i][j], vl2 = v2 - vv[i][j];
                if (vl)
                {
                    bad = true;
                }
                // find bits for vl2
                nleft[i][j] = vl2;
            }
        }

    for (int i = 0; i < N; i++)
    {
        int cc = 0;
        for (int j = 0; j < i; j++)
            if (S[j] == S[i])
                cc++;
        ns[i] = cc;
    }
    for (int i = 0; i < N; i++)
    {
        int cc = 0;
        for (int j = 0; j < i; j++)
            if (T[j] == T[i])
                cc++;
        nt[i] = cc;
    }

    for (int i = 0; i < N; i++)
    {
        if (S[i] == 0 && gv (i, 0) != U[i])
            bad = true;
        if (S[i] == 1)
        {
            ll remain = U[i] - gv (i, 0);
            //cout << i << " " << S[i] << " " << gv (i, 0) << " " << remain << "\n";
            if ((remain & U[i]) != remain)
                bad = true;
            for (int j = 0; j < N; j++)
                nleft[i][j] &= remain;
        }
        if (S[i] == 0)
        {
            ll rhard = -1;
            for (int j = 0; j < N; j++)
                rhard &= (vv[i][j] + nleft[i][j]);
            for (int j = 0; j < N; j++)
            {
                ll nv = nleft[i][j] & rhard;
                if (nv != nleft[i][j])
                {
                    vv[i][j] += nleft[i][j] - nv;
                    nleft[i][j] = nv;
                }
            }
        }
        if (T[i] == 0 && gv (i, 1) != V[i])
            bad = true;
        if (T[i] == 1)
        {
            ll remain = V[i] - gv (i, 1);
            if ((remain & V[i]) != remain)
                bad = true;
            for (int j = 0; j < N; j++)
                nleft[j][i] &= remain;
        }
        if (T[i] == 0)
        {
            ll rhard = -1;
            for (int j = 0; j < N; j++)
                rhard &= (vv[j][i] + nleft[j][i]);
            for (int j = 0; j < N; j++)
            {
                ll nv = nleft[j][i] & rhard;
                if (nv != nleft[j][i])
                {
                    vv[j][i] += nleft[j][i] - nv;
                    nleft[j][i] = nv;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if ((ns[i] + nt[j]) % 2 == 0)
                vv[i][j] += nleft[i][j];
    for (int i = 0; i < N; i++)
    {
        if (gv (i, 0) != U[i]) bad = true;
        if (gv (i, 1) != V[i]) bad = true;
    }
    if (bad)
    {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j) cout << " ";
            cout << vv[i][j];
        }
        cout << "\n";
    }

    /*for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j) cout << " ";
            cout << nleft[i][j];
        }
        cout << "\n";
    }*/
}