#include <iostream>
#include <ctime>
using namespace std;

void solve()
{
    int X;
    cin >> X;
    string ans = (X>=30)?"Yes":"No";
    cout << ans << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    // input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}