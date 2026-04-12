#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007

using namespace std;
int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    int a,b,c,x,y;
    int ans = 0;
    cin >> a >> b >> c >> x >> y;
    if(x>=y){
        if(a+b>=2*c){
            ans += 2*c*y;
            if(a>=2*c){
                ans += 2*c*(x-y);
                cout << ans;
                return 0;
            }else
            {
                ans += a*(x-y);
                cout << ans;
                return 0;
            }
            
        }else
        {
            ans += a*y+b*y;
            if(a>=2*c){
                ans += 2*c*(x-y);
                cout << ans;
                return 0;
            }else
            {
                ans += a*(x-y);
                cout << ans;
                return 0;
            }
        }
        
    }else{
        if(a+b>=2*c){
            ans += 2*c*x;
            if(b>=2*c){
                ans += 2*c*(y-x);
                cout << ans;
                return 0;
            }else
            {
                ans += b*(y-x);
                cout << ans;
                return 0;
            }
            
        }else
        {
            ans += a*x+b*x;
            if(b>=2*c){
                ans += 2*c*(y-x);
                cout << ans;
                return 0;
            }else
            {
                ans += b*(y-x);
                cout << ans;
                return 0;
            }
        }
    }
}