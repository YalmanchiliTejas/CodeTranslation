#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;


char a[105][105];
bool rr[105], cc[105];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        int c = 0;
        for(int j = 0; j < m; j++){
            c += (a[i][j] == '.');
        }
        rr[i] = (c == m);
    }
    for(int i = 0; i < m; i++){
        int c = 0;
        for(int j = 0; j < n; j++){
            c += (a[j][i] == '.');
        }
        cc[i] = (c == n);
    }
    for(int i = 0; i < n; i++){
        if(rr[i]) continue;
        for(int j = 0; j < m; j++){
            if(cc[j]) continue;
            cout << a[i][j];
        }
        cout << '\n';
    }


    return 0;
}

