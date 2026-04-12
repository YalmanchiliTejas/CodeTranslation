#if 1

#include <bits/stdc++.h>
using namespace std;
int x,y,n,ans;

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> x;
        if(y <= x)
        {
            y = x;
            ans++;
        }
    }
    cout << ans;
}

#endif // 1++