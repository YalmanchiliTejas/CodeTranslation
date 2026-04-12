#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int x, y;
    x = n * 800;
    y = n / 15 * 200;    

    cout << x - y << endl;

    return 0;
}