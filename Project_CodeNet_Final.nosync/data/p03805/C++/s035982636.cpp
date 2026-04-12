#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int SIZE = 10;

int n, m;
bool g[SIZE][SIZE];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
    }

    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    ll ans = 0;
    
    do {
        bool ok = true;
        for(int i = 0; i < v.size()-1; i++)
            if(!g[v[i]][v[i+1]])  ok = false;
        if(ok)  ans++;
    } while(next_permutation(v.begin()+1, v.end()));

    cout << ans << endl;
}