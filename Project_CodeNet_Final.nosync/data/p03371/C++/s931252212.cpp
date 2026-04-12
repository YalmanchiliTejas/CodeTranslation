#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);
    int a,b,c;
    long long x,y,s,r;
    cin>>a>>b>>c>>x>>y;
    if(x>y){
        if(2*c*x <= 2*c*y+(x-y)*a){
            s=2*c*x;
        } else s=2*c*y+(x-y)*a;
        if(a*x+b*y <= s)
            r=a*x+b*y;
        else r=s;
    } else {
        if(2*c*y <= 2*c*x+(y-x)*b){
            s=2*c*y;
        } else s=2*c*x+(y-x)*b;
        if(a*x+b*y <= s)
            r=a*x+b*y;
        else r=s;
    }
    cout<<r;
    return 0;
}
