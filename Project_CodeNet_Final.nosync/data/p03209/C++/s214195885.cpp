#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,x,sum = 1,num = 1,ans = 0;
    cin >> n >> x;
    for(int i = 1; i < n; i ++)
    {
        sum = sum * 2 + 1;
        num = num * 2 + 3;
    }
    while(sum > 1)
    {
        if(x > num + 2)
        {
            ans += sum + 1;
            x -= (num + 1);
        }
        else if(x == num + 2)
        {
            ans += sum + 1;
            cout << ans << endl;
            return 0;
        }
        else if(x >= num + 1)
        {
            ans += sum;
            cout << ans << endl;
            return 0;
        }
        num = (num - 3) / 2;
        sum = (sum - 1) / 2;
        x --;
    }
    if(x == 0) cout << ans << endl;
    else cout << ans + min(3 * 1ll,x - 1) << endl;
    return 0;
}