#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, o, p, i, j;
    string x, y;
    cin >> m;
    cin >> x;
    cin >> n;
    o = (int)x[n-1];
    for (i=0;i<m;i++){
        p = (int)x[i];
        if (p == o){
            cout << char(o);
        }
        else {
            cout << "*";
        }
    }
    return 0;

}