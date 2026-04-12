#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if(a+b < 2*c){
        cout << a*x+b*y << endl;
        return 0;
    }
    int ans = 0;
    ans += c*min(x,y)*2;
    if(a<2*c){
    ans += a*(x-min(x,y));
    }else{
        ans += 2*c*(x-min(x,y));
    }
    if(b<2*c){
    ans += b*(y-min(x,y));
    }else{
        ans += 2*c*(y-min(x,y));
    }
    cout << ans << endl;
    return 0;
}