#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
#define f first
#define s second
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define FOR(i, n, x) for(int i = x; i < n; i++)
#define PUT(a, n) FOR(i, n) cin >> a[i]
#define OUT(a, n) FOR(i, n) cout << a[i] << ' '

using namespace std;

const int N = 1e5 + 5;

int main() {
	fast;
    int n; cin >> n;
    string s; cin >> s;
    int k; cin >> k;
    char a = s[k - 1];
    FOR(i, n, 0)
    {
        if(s[i] != a)
        {
            s[i] = '*';
        }
    }
    cout << s;
    return 0;
}
