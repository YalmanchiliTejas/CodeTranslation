#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll sum[2*N];
ll n,x,mod;
int main() {
    cin >> n >> x >> mod;
    map<int, int> m;
    ll s=-1,e,i=1;
    while(1) {
        sum[i]=x +sum[i-1];
        if (m[x] == 0) m[x]++;
        else if (m[x] == 1) {
            if(s==-1) s = i;
            m[x]++;
        } else{
            e = i - 1;
            break;
        }
        x=((x%mod)*(x%mod))%mod;
        i++;
        //if(x<0) cout<<x<<endl;
    }

    ll k=(e-s+1);
    if(s>k) s-=k,e-=k;
    //cout<<s<<" "<<e<<endl;
    ll ans=0;
    ll res=sum[e]-sum[s-1];
    ans=sum[s-1]+res*((n-(s-1))/k)+(sum[s+(n-(s-1))%k-1]-sum[s-1]);
    //else ans=sum[s-1];
    cout<<ans;
    return 0;
}
