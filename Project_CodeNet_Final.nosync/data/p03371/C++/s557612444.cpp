//بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int m = 0;
    int d = max(x, y) - min(x, y);
    m += min(a+b, c+c) * min(x, y);
    if(x > y) m += min(a, c*2) * d;
    else m += min(b, c*2) * d;
    cout << m;
}
