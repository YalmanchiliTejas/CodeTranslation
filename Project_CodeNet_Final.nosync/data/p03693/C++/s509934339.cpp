#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl
#define YORN(f) cout<<((f)?"YES":"NO")<<endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    YORN((100 * r + 10 * g + b) % 4 == 0);
    return 0;
}