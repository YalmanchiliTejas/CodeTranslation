#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pi 3.14159265358979323846264
#define pii pair <int, int>
#define pb push_back
#define mp make_pair
#define vi vector <int>
#define vl vector <long long>
#define vpii vector <pair <int, int> >
#define ll long long
#define fi first
#define se second
#define FOR(i, x, y) for (int i=x; i<=y; i++)
#define FORI(i, x, y) for (int i=y; i>=x; i--)
#define debug printf("OK\n")
int n, a[100005], ans;
map <int, int> m;
int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) {
        auto it = m.upper_bound(-a[i]);
        if (it == m.end()) ans++;
        else {
            int k = it->first;
            m[k]--;
            if (m[k] == 0) m.erase(it);
        }
        //CODE
        m[-a[i]]++;
    }
    cout << ans << endl;
    return 0;
}