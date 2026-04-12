#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    
    if(a+b<=2*c)cout<<a*x+b*y<<endl;
    else if(x>y)cout<<min(2*c*y+(x-y)*a,2*c*x)<<endl;
    else cout<<min(2*c*x+(y-x)*b,2*c*y)<<endl;
}