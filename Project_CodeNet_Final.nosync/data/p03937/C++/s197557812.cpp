#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define debug(x) cerr << #x << " = " << (x) << endl;
template<typename T>
ostream& operator<<(ostream& o, vector<T>& v) {
    for (auto& x : v) o << x << ' ';
    return o;
}
char grid[10][10];
char ans[10][10];
int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            ans[i][j] = '.';
        }
    }
    int j = 0;
    for (int i = 0; i < n; i++){
        while (j < m && grid[i][j] == '#') {
            ans[i][j] = '#';
            j++;
        }
        j--;
        if (i == n-1) break;
        if (grid[i+1][j] != '#') break;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] != ans[i][j]) {
                cout << "Impossible" << endl;
                return 0;
            }
    cout << "Possible" << endl;
}
