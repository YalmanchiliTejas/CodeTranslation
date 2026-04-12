#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 123;

using namespace std;

int n;
int m;
int used[N][N];
char a[N][N];

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m;
        used[1][0] = 1;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> a[i][j];
                        if(a[i][j] == '.'){
                                continue;
                        }
                        if(!used[i - 1][j] && !used[i][j - 1]){
                                cout << "Impossible" << "\n";
                                return 0;
                        }
                        used[i - 1][j] = used[i][j - 1] = 0;
                        used[i][j] = 1;
                }
        }
        if(used[n][m]){
                cout << "Possible" << "\n";
        } else{
                cout << "Impossible" << "\n";
        }
}
