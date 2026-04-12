#include <bits/stdc++.h>

using namespace std;

const int max_n = 1e7 + 5, mod = 998244353;

long long silnia[max_n];

long long pot(int x, int y){
    int wynik = 1;
    while (y){
        if (y % 2)
            wynik = (long long)wynik * x % mod;
        x = (long long) x * x % mod;
        y /= 2;
    }
    return wynik;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    silnia[0] = 1;
    for (int i = 1; i <= n; i++)
        silnia[i] = (long long)silnia[i - 1] * i % mod;
    long long wynik = pot(3, n);
    for (int i = n / 2 + 1; i <= n; i++)
        wynik = (wynik -(pot(2, n - i) * 2 * silnia[n] % mod) * pot(silnia[i] * silnia[n - i] % mod, mod - 2) % mod) % mod;
    if (wynik < 0)
        wynik += mod;
    cout << wynik << "\n";
    return 0;
}