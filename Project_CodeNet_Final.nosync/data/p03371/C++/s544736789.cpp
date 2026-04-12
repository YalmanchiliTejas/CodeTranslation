#include <bits/stdc++.h>

#define gif(a,b) ((a)/(b)+((a)%(b)?1:0))
#define float long double
#define int long long 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(x) cout<<(#x)<<" is "<<(x)<<"\n";
using namespace std;

int32_t main()
{ 
    IOS
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
        if(a + b < 2*c)
        {
            cout << x*a + y*b ; 
        }
        else
        {
            int ans = min(x, y);
            if(ans == x)
            {
                ans *= 2*c;
                y = y - x;
                if(b > 2*c) 
                    ans += y*2*c;
                else
                    ans += b*y;
            }
            else
            {
                ans *= 2*c;
                x = x - y;
                if(a > 2*c) 
                {
    
                    ans += x*2*c;
                }

                else
                    ans += a*x;
            }
            
            cout << ans ;
        
        }

    return 0;
}