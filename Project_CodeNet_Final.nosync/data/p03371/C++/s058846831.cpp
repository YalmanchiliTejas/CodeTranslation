#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int x,y;
    cin >> x >> y;
    ll ans;
    if(x >= y){
        ans = min(x*a+y*b, min(c*y*2+(x-y)*a, c*x*2));
    }else{
        ans = min(x*a+y*b, min(c*x*2+(y-x)*b, c*y*2));
    }
    cout << ans << endl;
}
