#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int,int> PII;


int n, m, cnt;
char a[20][20];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '#') cnt++;
        }
    for (int i = 0, it = 0; i < n; i++) {
        while (a[i][it] == '#') it++, cnt--;
        it--;
    }
    if (cnt > 0) cout << "Impossible\n";
    else cout << "Possible\n";
}
