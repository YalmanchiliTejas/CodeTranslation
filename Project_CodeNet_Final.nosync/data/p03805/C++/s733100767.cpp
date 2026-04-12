#include <iostream>

using namespace std;

bool g[10][10];
bool v[10];
int n, m;
int a, b;

int dfs(int now);

int main()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        --a; --b;
        
        g[a][b] = true;
        g[b][a] = true;
    }

    v[0] = true;
    cout << dfs(0) << endl;
    
    return 0;
}

int dfs(int now)
{
    bool f = true;

    for (int i = 0; i < n; i++) {
        f = f & v[i];
    }

    if (f) {
        return 1;
    }

    int rec = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == false && g[now][i]) {
            v[i] = true;
            rec += dfs(i);

            v[i] = false;
        }
    }

    return rec;
}
