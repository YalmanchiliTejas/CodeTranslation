#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,x,m;
    cin >> n >> x >> m;
    vector<ll>roop(m,0);
    ll a=x;
    ll cnt=1;
    ll ans=x;
    bool lim=false;
    for(ll i=0;i<m+10;i++){
        a=(a*a)%m;
        cnt++;
        ans+=a;
        if(cnt==n) {
            lim=true;
            break;
        }
        bool ok=false;
        roop[a]++;
        if(roop[a]>=2) ok=true;
        if(ok) break;
    }
    if(lim){
        cout << ans << endl;
        return 0;
    }
    n-=cnt;
    ans-=a;
    n++;
    vector<ll>num;
    bool judge=true;
    ll b=a;
    num.push_back(a);
    ll sum=a;
    while(judge){
        b=(b*b)%m;
        if(b==a) break;
        num.push_back(b);
        sum+=b;
    }
    ll siz=num.size();
    ll aa=n/siz;
    ans+=sum*aa;
    n-=aa*siz;
    for(ll i=0;i<n;i++){
        ans+=num[i];
    }
    cout << ans << endl;
}
    