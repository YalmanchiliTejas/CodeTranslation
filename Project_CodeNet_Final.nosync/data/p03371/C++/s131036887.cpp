#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans=0;

int main(void)
{
    //input
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    
    //calculate
    ans = a*x + b*y;
    for(int i=1; i<=100000; i++){
        ans = min(ans, a*max(0,x-i) + b*max(0,y-i) + 2*c*i);
    }
    //output    
    cout << ans << endl;

    return 0;
}