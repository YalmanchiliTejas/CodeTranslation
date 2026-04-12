#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
//#pragma GCC optimize (-O3)
//#define endl tutaj n
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define int long long

struct drzewo_przedzialowe //drzewo przedzial-przedzial dodaj
{
    int rozmiar;
    vector<int> modyfikator, S, L, P;

    int pot(int n)
    {
        int x = 1;
        while (n > x)
            x = x * 2;
        return x;
    }

    void deklaracja(int x) //x-rozmiar drzewa
    {

        rozmiar = pot(x);
        modyfikator.resize(2 * rozmiar, 0);
        L.resize(2 * rozmiar, 0);
        S = modyfikator;
        P = L;

        for (int i = rozmiar; i < 2 * rozmiar; i++)
            L[i] = P[i] = i - rozmiar;

        for (int i = rozmiar - 1; i > 0; i--)
        {
            L[i] = L[2 * i];
            P[i] = P[2 * i + 1];
        }
    }

    void zmien(int p, int q, int o_ile_zmienic, int wezel = 1) //dodaje o_ile_zmienic na przedziale [p,q]
    {
        if (p > q)
            return;

        if (p == L[wezel] && q == P[wezel])
        {
            modyfikator[wezel] = modyfikator[wezel] + o_ile_zmienic;
            S[wezel] += o_ile_zmienic;
            return;
        }
        zmien(p, min(P[2 * wezel], q), o_ile_zmienic, 2 * wezel);
        zmien(max(L[2 * wezel + 1], p), q, o_ile_zmienic, 2 * wezel + 1);

        S[wezel] = min(S[2 * wezel], S[2 * wezel + 1]) + modyfikator[wezel];
    }
    int mak(int p, int q, int wezel = 1) //zwraca maksa na przedziale [p,q]
    {
        if (p > q)
            return 1e18;
        if (p == L[wezel] && q == P[wezel])
            return S[wezel];

        return min(mak(p, min(P[2 * wezel], q), 2 * wezel), mak(max(L[2 * wezel + 1], p), q, 2 * wezel + 1)) + modyfikator[wezel];
    }

    void wypisz()
    {
        for (int i = 1; i < rozmiar * 2; i++)
            cout << i << ": " << modyfikator[i] << " " << S[i] << endl;
    }
};
const int MAXN = 2e5 + 100;
int n, m, suma = 0;
int dp[MAXN]; //dp, suma wszystkich ktore zaczynaja sie conajmniej w i
drzewo_przedzialowe D;
vector<pii> konce[MAXN]; //

void wyrzuc(int x)
{
    for (auto Y : konce[x])
        D.zmien(0, Y.st - 1, Y.nd);
}

void wczytywanie()
{
    cin >> n >> m;
    D.deklaracja(n + m + 10);
    REP(i, m)
    {
        int l, r, a;
        cin >> l >> r >> a;
        suma += a;
        konce[r].push_back(mp(l, a));
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = D.mak(0, i - 1);
        D.zmien(i, i, dp[i]);
        wyrzuc(i);
    }
    cout << suma - D.mak(0, n) << endl;
}

main()
{
    _upgrade;
    wczytywanie();
}