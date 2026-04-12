/* next_permutation()によって起こりうる全ての状態を生成できる。
始点が1 かつ全ての頂点を1度だけ訪れるようなパスは1 から始まる順列に対応しているので、
それぞれ条件を満たすかどうか判定する。
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int g[10][10];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a - 1][b - 1] = g[b - 1][a - 1] = 1;
    }

    int num[n];
    int ans = 0;
    for (int i = 0; i < n; i++) num[i] = i;
    do{
        if (num[0] != 0) break;
        bool possible = true;
        for (int i = 0; i < n - 1; i++){
            if (!g[num[i]][num[i + 1]]){
                possible = false;
                break;
            }
        }
        if (possible) ans++;
    }while(next_permutation(num, num + n));

    cout << ans << endl;

    return 0;
}