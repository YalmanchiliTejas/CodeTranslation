//Half and Half

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
template<class T>inline bool chmin(T& a,T b,bool f){
if(f==1){if(a>b){a=b;return true;}return false;}
else if(f==0){if(a<b){a=b;return true;}return false;}return false;}
typedef pair<int,string> p;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

int main (){
    int a,b,c,x,y,ans;cin>>a>>b>>c>>x>>y;
    int amai=x,bmai=y;
    ans=a*amai+b*bmai;
    rep(i,1,x+y+1){
        amai--;
        bmai--;
        if(amai<0)amai=0;if(bmai<0)bmai=0;
        ans=min(ans,amai*a+bmai*b+c*2*i);
    }
    cout << ans << nnn;
    return 0;
}