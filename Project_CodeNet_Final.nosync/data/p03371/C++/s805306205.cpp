#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(a%b == 0) return b;
    else return gcd(b,a%b);
}

int main(){
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll M=max(x,y);
    ll m=x+y-M;
    ll ans=2*M*c;
    
    ans=min(ans,a*x+b*y);

    if(M==x) b=a;

    ans=min(ans,m*2*c+b*(M-m));

    cout << ans << endl;

}