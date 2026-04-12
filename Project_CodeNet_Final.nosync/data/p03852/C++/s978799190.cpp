#include <bits/stdc++.h>

#define PI 3.1415926535897932
#define MOD 1000000007
#define INF 1e9

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, start, end) for(int i = (start); i < (end); i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;


void solve()
{
    char c; cin >> c;
    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
        cout << "vowel" << endl;
    else
        cout << "consonant" << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();

    return 0;
}