#include <bits/stdc++.h>

#define name "lqdoj"
#define long long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inoutf ifstream fi(name".inp"); ofstream fo(name".out");

using namespace std;

const int N = 3000;
long d[N][N];

int main(){
    fastio;
    inoutf;

    int n;
    cin >> n;
    long a[n];
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; --i){
        for (int j = 0; j < n; ++j){
            if (i == j) d[i][j] = a[i];
            else
                if (i > j) d[i][j] = 0;
                else d[i][j] = max((a[i] - d[i + 1][j]),(a[j] - d[i][j - 1]));
        }
    }
    cout << d[0][n - 1];

    return 0;
}
