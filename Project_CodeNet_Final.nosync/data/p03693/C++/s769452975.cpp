//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;

#define endl "\n"

const int MOD = 1000000007;


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

    int a, b, c, x, y, z;
    cin >> a >> b >> c;
    x = (a*100)+(b*10)+c;
    if(x % 4 == 0)
        cout << "YES" << endl;
    else
        cout  << "NO" << endl;

    return 0;
}
