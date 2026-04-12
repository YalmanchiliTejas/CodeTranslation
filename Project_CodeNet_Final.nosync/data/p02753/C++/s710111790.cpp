#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef string sr;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sr S;
    cin >> S;
    if (S[0] == S[1] && S[1] == S[2] && S[2] == S[1]) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}