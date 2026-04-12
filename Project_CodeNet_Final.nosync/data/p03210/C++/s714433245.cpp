#include <bits/stdc++.h>

#define REP(i, n) for(int (i) = 0; (i) < (int)(n); (i)++)
#define REPR(i, n) for(int (i) = (n); (i) >= 0; (i)--)
#define FOR(i, m, n) for(int (i) = (m); (i) < (n); (i)++)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define INF 1e9

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;

int main(int argc, char const *argv[])
{
    int X;
    cin >> X;
    string ans = "NO";

    if(X == 7 || X == 5 || X == 3)
    {
        ans = "YES";
    }

    cout << ans << endl;

    return 0;
}
