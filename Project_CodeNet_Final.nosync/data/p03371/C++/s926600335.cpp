#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans;
    if(x>y){
        ans=min(a+b,2*c)*y;
        ans+=min(a,2*c)*(x-y);
    }
    else{
        ans=min(a+b,2*c)*x;
        ans+=min(b,2*c)*(y-x);
    }
    cout << ans << "\n";
    return 0;
}