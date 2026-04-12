#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
int main()
{
    int x , y , z;
    while (~scanf("%d%d%d", &x,&y,&z)){
        printf("%d\n", (x-z)/(y+z));
    }
    return 0;
}
