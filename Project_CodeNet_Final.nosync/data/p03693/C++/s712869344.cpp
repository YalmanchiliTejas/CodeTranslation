#include<bits/stdc++.h>
#define taskname "test1"
#define int long long
using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);
    if (ifstream("test.inp"))
    {
        freopen("test.inp", "r", stdin);
        #ifdef CHECKING
            freopen(taskname".out", "w", stdout);
        #else
            freopen("test.out", "w", stdout);
        #endif //CHECKING
    }
    else if (ifstream(taskname".inp"))
    {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    int a, b, c;    cin >> a >> b >> c;
    if ((a * 100 + b * 10 + c) % 4 == 0) cout << "YES";
    else cout << "NO";
}
