#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

typedef long long ll;

using namespace std;
int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    int num = 100 * r + 10 * g + b;

    string ans;
    if (num % 4 == 0)
    {
        ans = "YES";
    }
    else
    {
        ans = "NO";
    }
    
    cout << ans << endl;
}
