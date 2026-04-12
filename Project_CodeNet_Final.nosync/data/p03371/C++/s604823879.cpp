#include<bits/stdc++.h>
#define PI acos(-1.0)
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int MOD=1e9+7;
//ll a[N];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    if(a+b<=2*c){
        cout << a*x+b*y<<endl;
    }
    else{
        ll ans=0;
        if(x<y){
            ans+=x*2*c;
            y-=x;
            x-=x;
//            cout << ans <<" "<<x<<" "<<y<<endl;
            if(b*y<=2*c*y)  ans+=b*y;
            else    ans+=2*c*y;
        }
        else{
            ans+=y*2*c;
            x-=y;
            y-=y;
            if(a*x<=2*c*x){
                ans+=a*x;
            }
            else    ans+=2*c*x;
        }cout <<ans << endl;
    }


    return 0;
}
