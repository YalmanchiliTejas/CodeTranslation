#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define fcin ios::sync_with_stdio(false); cin.tie(nullptr);
#define INF 0x3f3f3f3f
#define all(x) x.begin(), x.end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair<int, int> pii;

int main(){
    fcin;
    string s;
    cin >> s;

    sort(all(s));
    if(s[0] == s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}

