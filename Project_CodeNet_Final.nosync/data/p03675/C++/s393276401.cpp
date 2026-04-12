//CLMN
//Every cloud has a silver lining
//Hakuna matata

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define fi first
#define se second
#define pb push_back
#define sqr(x) ((x) * (x))

const char *fin = "arc077_a.inp";
const char *fon = "";

#define oo (int) (1e9+7)
#define maxn (int) (2e5+5)

int a[maxn];
int n;

void sol(int MOD) {
    for(int i = n; i >= 1; --i) if (i % 2 == MOD) cout << a[i] << ' ';
    for(int i = 1; i <= n; ++i) if (i % 2 != MOD) cout << a[i] << ' ';
}

void inp() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sol(n % 2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //freopen(fin, "r", stdin); freopen(fon, "w", stdout);
    inp();
    return 0;
}
