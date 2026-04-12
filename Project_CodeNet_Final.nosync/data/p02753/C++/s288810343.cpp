#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    string s; cin >> s;
    int c = count(all(s), 'A');
    if (c == 3 || c == 0) cout << "No\n";
    else cout << "Yes\n";
}