#include<bits/stdc++.h>
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(), x.end()
#define skip continue
#define NAME "code"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
void faster(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
const int MAXN = 1e3 + 1;
const ll INF = 1e18;
const ld pi = acos(-1);

int n, m;
char c[MAXN][MAXN];

int main() {

    faster();

    cin >> n >> m;
 
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> c[i][j];
        }
    } 

    if(c[0][0] != '#'){
        cout << "Impossible";
        return 0;
    }

    int x = 0, y = 0;
    c[x][y] = '.';

    for(int i = 0; i < n + m - 2; ++i){
        if(y + 1 < m && c[x][y + 1] == '#')
            y++;
        else if(x + 1 < n && c[x + 1][y] == '#')
            x++;
        c[x][y] = '.';
    } 


    if(x != n - 1 || y != m - 1){
        cout << "Impossible";
        return 0;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(c[i][j] == '#'){
                cout << "Impossible";
                return 0;
            }
        }
    } 

    cout << "Possible";

    return 0;
}