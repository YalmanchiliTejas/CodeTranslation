#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,h,w,ans = 0;
    char a;
    cin >> h >> w;
    for(i = 0; i < h; i ++)
    {
        getchar();
        for(j = 0; j < w; j ++)
        {
            cin >> a;
            if(a == '#') ans ++;
        }
    }
    if(ans == h + w - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}