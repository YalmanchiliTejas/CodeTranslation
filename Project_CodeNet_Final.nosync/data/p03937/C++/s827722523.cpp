#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, cnt = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if(c == '#') cnt++;
        }
    }
    if(cnt == (n + m - 1)) cout << "Possible";
    else cout << "Impossible";
}