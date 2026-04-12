#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;

int main()
{
    int x,y,z;
    int ans;

    while(scanf("%d%d%d",&x,&y,&z) != EOF)
    {
        x -= 2*z;
        ans = x/(y+z);
        if(x%(y+z) >= y) ans++;
        printf("%d\n",ans);
    }

    return 0;
}


