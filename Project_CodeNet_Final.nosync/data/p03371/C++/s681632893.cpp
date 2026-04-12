#include <bits/stdc++.h>

#define PI 3.14159265359
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
ll LCM(int a, int b){
    return a*b/gcd(a,b);
}

int main(void)
{
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll case1=x*a+y*b;
    ll case2=max(x,y)*2*c;
    ll case3=min(x,y)*2*c+abs(x-y)*(x>y?a:b);
    //cout<<case1<<" "<<case2<<" "<<case3<<endl;
    cout<<min({case1,case2,case3})<<endl;
    return 0;
}