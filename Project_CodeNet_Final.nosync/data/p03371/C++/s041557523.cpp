#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair

vector<int> v;

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a, b, c, x, y;
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
    int ab = min(a + b, 2*c);
    int mn = min(x, y);
    LL res = mn * ab;
    LL mxtemp = max(x, y)*ab;
    x -= mn;
    y -= mn;
    if(x > 0)res += x * a;
    if(y > 0)res += y * b;
    res = min(mxtemp, res);
    printf("%lld\n", res);
    return 0;
}
