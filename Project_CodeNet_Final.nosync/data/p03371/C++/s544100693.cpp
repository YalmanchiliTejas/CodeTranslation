// ABC95-C
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
namespace you {
    std::string to_string(char val) {
        return std::string(1, val);
        // return std::string{val};
        // you::to_string(char)
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    
    ll ans=pow(10,10);
    int num=max(x,y);
    for(int i=0;i<=num;i++){ //abピザで作るa,bピザの数
        ll cur=i*2*c;
        cur+=a*max(ll(0),x-i);
        cur+=b*max(ll(0),y-i);
        ans=min(ans,cur);
    }
    cout<<ans<<endl;
    return 0;
}