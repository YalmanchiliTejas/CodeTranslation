#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
    char r, g, b;
    cin >> r >> g >> b;
    int num = 0;
    num = (r - '0') * 100 + (g - '0') * 10 + (b - '0');
    if (num % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
