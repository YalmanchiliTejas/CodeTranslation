#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3030;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
long long d[N][N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = n; i >= 1; i--){
                for(int j = i; j <= n; j++){
                        int tp = (n - j + i) % 2;
                        if(tp){
                                d[i][j] = max(d[i][j - 1] + a[j], d[i + 1][j] + a[i]);
                        }
                        else{
                                d[i][j] = min(d[i][j - 1] - a[j], d[i + 1][j] - a[i]);
                        }
                }
        }
        cout << d[1][n] << "\n";
}

