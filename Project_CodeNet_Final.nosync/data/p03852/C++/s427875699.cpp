#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

char n;
int main() {
    cin >> n;
    if (n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u')
        cout << "vowel" << endl;
    else
        cout << "consonant" << endl;
    return 0;
}
