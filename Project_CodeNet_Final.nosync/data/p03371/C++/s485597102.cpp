#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i = 0;i < (n); ++i)
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if(a+b <= 2*c){
        cout << a*x + b*y << endl;
        return 0;
    }else{
        int mn = min(x,y);
        int mx = max(x,y);
        int ans;
        int num;
        ans = 2*mn*c + max(x - mn, 0)*a + max(y - mn, 0)*b;
        num = 2*mx*c;
        ans = min(ans,num);
        cout << ans << endl;
        return 0;
    }
} 