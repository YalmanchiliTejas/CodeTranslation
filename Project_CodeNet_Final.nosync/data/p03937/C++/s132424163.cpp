#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, M;
string s[10];
int c[20];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ff(i, 0, N - 1) cin >> s[i];
    ff(i, 0, N - 1) ff(j, 0, M - 1) if (s[i][j] == '#') ++c[i+j];
    ff(i, 0, N + M - 2) if (c[i] != 1) return cout << "Impossible" << endl, 0;
    cout << "Possible" << endl;
    return 0;
}
