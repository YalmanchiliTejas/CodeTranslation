#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
int a, b, c;

int main(){
    cin >> a >> b >> c;
    a -= c;
    int ans = a/(b+c);
    cout << ans << "\n";
    return 0;
}
