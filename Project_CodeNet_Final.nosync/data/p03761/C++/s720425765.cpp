#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const double eps = 1e-9;

typedef pair<ll, ll> P;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    int n;
    cin >> n;
    string alpa = "abcdefghijklmnopqrstuvwxyz";
    
    vector <int> x(26, 1000);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int i = 0; i < 26; i++) {
            int cnt = 0;
            for (int j = 0; j < int(s.size()); j++) {
                if (s[j] == alpa[i]) cnt++;
            }
            chmin(x[i], cnt);
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < x[i]; j++) {
            cout << alpa[i];
        }
    }
    cout << endl;
    return 0;
}

