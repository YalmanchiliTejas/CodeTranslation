#include <bits/stdc++.h>

typedef long long ll;

#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define AA(i) cout << i << endl;
#define AS(i) cout << i << " ";

const int INF = 1001001001;

const double PI = 3.14159;

using namespace std;

//vector<ll> memo(1000007, INF);

int main() {

    int n, m;
    cin >> n >> m;

    string ans = "No";
    if (n==m) ans = "Yes";

    AA(ans);
}