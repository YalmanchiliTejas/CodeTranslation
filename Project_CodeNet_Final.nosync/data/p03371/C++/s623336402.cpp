#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)

#define mod 1e9+7;
#define inf 1e18+7;

typedef long long ll;

int main() {
    ll a,b,c,x,y,ans=0;
    cin>>a>>b>>c>>x>>y;

    if(a+b<c*2){
        ans=a*x+b*y;
    }

    else if((x>y&&a>2*c)||(x<y&&b>2*c)){
        ans=max(x,y)*2*c;
    }

    else if(x==y){
        ans=x*2*c;
    }

    else if(x>y){
        ans=y*2*c+(x-y)*a;
    }

    else if(x<y){
        ans=x*2*c+(y-x)*b;
    }

    cout<<ans<<endl;
}

