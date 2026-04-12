#include<bits/stdc++.h>

#define REPI(i, n) for(int i = 0; i < n; i++)
#define REPJ(j, n) for(int j = 0; j < n; j++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c; cin >> a >> b >> c;
    (100 * a + 10 * b + c) % 4 == 0 ? cout << "YES" : cout << "NO";
}
