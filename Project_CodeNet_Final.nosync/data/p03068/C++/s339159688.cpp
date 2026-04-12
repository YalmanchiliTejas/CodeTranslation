#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    int n; cin >> n;
    string s; cin >> s;
    int k; cin >> k;
    k--;
    for(int i = 0; i < n; i++){
        if(s[i] == s[k]) cout << s[i];
        else cout << '*';
    }
    cout << '\n';

    return 0;
}
