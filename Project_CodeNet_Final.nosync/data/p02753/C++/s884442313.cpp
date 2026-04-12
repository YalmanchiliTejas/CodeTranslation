#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define rrep(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string S;
    cin >> S;
    if (S.compare("AAA") == 0 || S.compare("BBB") == 0)
    {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}
