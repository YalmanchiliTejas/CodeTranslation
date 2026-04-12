//long long使う！！！！！！
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define Clear(a) a = decltype(a)();
typedef long long ll;

ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
  return x+y-max(x,y);
}
 
const ll big=998244353;
ll exp(ll x,ll y){
    if(y==0)return 1;//0^0=1
    if(x==1||x==0)return x;
    if(y%2==1)return (exp(x,y-1)*x);
    ll t=exp(x,y/2);
    return (t*t);
}
 
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(0);
    /*--------------------------------*/
    
    ll a,b,c,x,y;cin >> a >> b >> c >> x >> y;
    ll ans=0;
    if(a+b>=2*c){
        ans+=min(x,y)*2*c;
        ll t=min(x,y);
        x-=t;
        y-=t;
        
        if(x==0){swap(x,y);swap(a,b);}//y=0
        if(a<=2*c){
            ans+=a*x;
        }else{
            ans+=2*c*x;
        }
    }else{
        ans=a*x+b*y;
    }
    cout << ans << endl;
}