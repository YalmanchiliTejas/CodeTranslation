#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7,INF=1e17;
const int iINF=1e9;
#define enld endl
int main(){
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    c*=2;
    bool flag=(x>y)?true:false;
    if(a+b>=c){
        ll add=min(x,y)*c;
        add+=flag?abs(x-y)*a:abs(x-y)*b;
        ll comp=max(x,y)*c;
        if(add<comp)cout<<add<<endl;
        else cout<<comp<<endl;
    }
    else{
        cout<<x*a+y*b<<endl;
    }
}