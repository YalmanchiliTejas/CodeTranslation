#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fr(i, a, b) for (ll i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(false);
    #ifdef CODE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int x;
    cin >> x;
    if (x >= 30) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}