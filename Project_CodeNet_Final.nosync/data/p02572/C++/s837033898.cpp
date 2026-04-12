#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000*1000*1000+7;
long long n, curr, suma, wynik;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(long long i = 1; i <= n; i++)
    {
        cin >> curr;
        wynik = (wynik +  curr * suma) % MOD;
        suma = (suma + curr) % MOD;
    }
    cout << wynik % MOD << "\n";
}
