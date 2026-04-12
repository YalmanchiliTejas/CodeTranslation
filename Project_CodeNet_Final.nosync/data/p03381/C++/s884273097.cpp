#include <bits/stdc++.h>

#define fr first
#define sc second
#define pb push_back
#define mk make_pair
#define ll long long
#define OK puts("OK")
#define sz(s) (int)s.size()
#define all(s) s.begin(), s.end()

using namespace std;

const int N = 2e5+10;
const int inf = 1e9+7;

int n;
int a[N];
int ans[N];
pair <int, int> p[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i].fr;
        p[i].sc = i;

    }
    sort(p + 1, p + n + 1);
    for(int i = 1; i <= n; i++) {
        if(i > n / 2)
            ans[p[i].sc] = p[n / 2].fr;
        else
            ans[p[i].sc] = p[n / 2 + 1].fr;
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << endl;
}
