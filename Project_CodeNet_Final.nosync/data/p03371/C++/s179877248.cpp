#include <bits/stdc++.h>
#define PI 3.141592653
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}
int main(void){
    int a,b,c,x,y,ans=INF;
    cin>>a>>b>>c>>x>>y;
    rep(i,0,1e5+1){
        int num=i*2*c+max(0,x-i)*a+max(0,y-i)*b;
        ans=min(ans,num);
    }
    cout<<ans<<endl;
    return 0;
}