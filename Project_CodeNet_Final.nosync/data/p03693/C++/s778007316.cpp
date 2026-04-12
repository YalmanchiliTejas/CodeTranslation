#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX = 100005;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if((a*100+b*10+c)%4)
        puts("NO");
    else
        puts("YES");
    return 0;
}
