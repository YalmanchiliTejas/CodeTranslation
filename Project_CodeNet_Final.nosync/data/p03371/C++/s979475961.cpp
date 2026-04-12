#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    long long ans = 0;

    if (a + b <= c*2)
    {
        ans = a * x + b * y;
    }else
    {
        if (x>=y)
        {
            ans += 2*c * y;
            if (a > 2*c)
            {
                ans += c * (x-y) *2;
            }else
            {
                ans += a * (x-y);
            }
            
            
        }else
        {
            ans += 2*c * x;
            if (b > 2*c)
            {
                ans += c * (y-x) *2;
            }else
            {
                ans += b * (y-x);
            }
        }
        
        
    }

    cout << ans << endl;
    
    
}