#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define rrep(i,n) for(int (i) = (n) - 1; (i) >= 0; --(i)) //Reversi rep
#define nfor(i,a,b) for(int (i) = (a); (i) < (b); ++(i)) //Natural for
#define rfor(i,a,b) for(int (i) = (b); (i) >= (a); --(i)) //Reversi for

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if ((100 * a + 10 * b + c) % 4 == 0) {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}