#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

int main(){
    fast_io

    int a, b, ab;
    cin>>a>>b>>ab;
    int x, y;
    cin>>x>>y;
    ll ans=a*x+b*y;
    ll ans2, ans3;
    if(x<y){
        ans2=2*ab*x+(y-x)*b;
        ans3=2*ab*y;
    }else{
        ans2=2*ab*y+(x-y)*a;
        ans3=2*ab*x;
    }
    ans=min(ans, ans2);
    ans=min(ans, ans3);
    cout<<ans<<endl;
    return 0;

}
