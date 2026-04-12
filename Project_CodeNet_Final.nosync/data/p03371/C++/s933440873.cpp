#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int a,b,c;
    int x,y;
    cin >> a >> b >> c >> x >> y;
    
    int ans = a*x + b*y;
    for(int i=0; i<=2*max(x,y); i+=2){
        ans = min(ans, i*c+ max(0,a*(x-i/2)) + max(0,b*(y-i/2)));
    }
    cout << ans << endl;
}