#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n, m;
vector <string> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    a.resize(n);
    for(auto &i : a) cin >> i;
    for(auto &i : a){
        bool b = 0;
        for(int j = 0 ; j < m ; j++){
            if(i[j] == '.') continue;
            if(b) finish("Impossible");
            while(j < m && i[j] == '#') j++;
        }
    }
    int x = 0, y = 0;
    while(x != n - 1 || y != m - 1){
        a[x][y] = '.';
        if(y + 1 < m && a[x][y + 1] == '#') y++;
        else if(x + 1 < n && a[x + 1][y] == '#') x++;
        else break;
    }
    a[x][y] = '.';
    for(auto &i : a){
        for(auto &j : i){
            if(j != '.') finish("Impossible");
        }
    }
    cout << "Possible" << endl;
}
