#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
bool g[8][8];

bool check(vector<int> vec){
    for (int i = 1; i < n; i++){
        if (!g[vec[i-1]][vec[i]]) return false;
    }
    return true;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x][y] = true;
        g[y][x] = true;
    }
    vector<int> v;
    for (int i = 0; i < n; i++){
        v.push_back(i);
    }

    int cnt = 0;
    do {
        if (check(v)) cnt++;
    } while (next_permutation(v.begin()+1, v.end()));

    cout << cnt << endl;
}
