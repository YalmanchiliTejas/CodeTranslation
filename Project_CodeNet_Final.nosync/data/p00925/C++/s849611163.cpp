#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string s;
    cin >> s;
    s = "+" + s;
    int b;
    cin >> b;

    int n = s.size();

    // mul-first
    int a1 = 0;
    rep(i, n) {
        if (s[i] == '+') {
            int t = 1;
            rep2(j, i + 1, n) {
                if (isdigit(s[j])) {
                    t *= s[j] - '0';
                }
                if (s[j] == '+') {
                    break;
                }
            }
            a1 += t;
        }
    }

    // left-to-right
    int a2 = 0;
    rep(i, n) {
        if (s[i] == '+') {
            a2 += s[i + 1] - '0';
        }
        if (s[i] == '*') {
            a2 *= s[i + 1] - '0';
        }
    }

    if (b == a1 && b != a2) {
        cout << "M" << endl;
    }
    if (b != a1 && b == a2) {
        cout << "L" << endl;
    }
    if (b == a1 && b == a2) {
        cout << "U" << endl;
    }
    if (b != a1 && b != a2) {
        cout << "I" << endl;
    }

}