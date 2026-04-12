#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=3.141592653589793;

int main() {
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    //abピザを何枚買う?
    ll ans=10000000000000;
    ll num=max(x,y)*2;
    for (int i=0;i<num+1;i++){
        ll ans1=0;
        ans1+=i*c;
        if (x>i/2){
            ans1+=(x-i/2)*a;
        }
        if (y>i/2){
            ans1+=(y-i/2)*b;
        }
        ans=min(ans,ans1);
    }
    cout<<ans<<endl;

    return 0;
}